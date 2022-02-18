#include "AutoTest.hpp"
#include "head.hpp"
#include "CIntN.hpp"
#include "CIntN1.hpp"
#include "CIntN0.hpp"

bool AutoTest1() {
	CIntN0 a = -123;
    CIntN0 b = 124;
    CIntN1 ans; ans = a + b;
	if (ans.get_N() == 1 ) return 1;
	else return 0;
}

bool AutoTest2() {
	CIntN1 a = 123; 
    CIntN1 b = 125;
	CIntN0 ans = a - b;
	if (ans.get_N() == 1 && ans.get_sign() == '-') return 1;
	else return 0;
}

bool AutoTest3(){
    CIntN1 a = 9831367832;
    CIntN0 b("-23943288028342");
    CIntN0 ans = 5;
    ans += b;
    ans += a;
    CIntN** arr = new CIntN*[3];
    arr[0] = new CIntN1; arr[0] = &a;
    arr[1] = new CIntN0; arr[1] = &b;
    arr[2] = new CIntN0; arr[2] = &ans;
    for(size_t i = 0; i < 3; ++i) arr[i]->updateFile("AutoTest.txt");

    for(size_t i = 1; i < 3; ++i) arr[i]->print_to_file();

    std::vector<std::string> answer = {"- 2 3 9 4 3 2 8 8 0 2 8 3 4 2 ", "- 2 3 9 3 3 4 5 6 6 6 0 5 0 5 "};
    size_t i = 0;

    std::ifstream inp("AutoTest.txt");
    if(!inp) return 0;

    std::string line;
    while(getline(inp, line)){
        if(line != answer[i]){
            inp.close();
            remove("AutoTest.txt");
            return 0;
        }
        ++i;
    }
    inp.close();
    remove("AutoTest.txt");
    return 1;
}

bool AutoTest() {
	bool all = 1;
	if (!AutoTest1()) {
		all = 0;
		std::cout << "AutoTest1 failed." << std::endl;
	}
	if (!AutoTest2()) {
		all = 0;
		std::cout << "AutoTest2 failed." << std::endl;
	}
    if (!AutoTest3()) {
		all = 0;
		std::cout << "AutoTest3 failed." << std::endl;
	}
	return all;
}