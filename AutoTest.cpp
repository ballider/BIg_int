#include "AutoTest.hpp"
#include "head.hpp"
#include "CIntN.hpp"
#include "CIntN1.hpp"
#include "CIntN0.hpp"

bool AutoTest1() {
	CIntN a = -123;
    CIntN b = 124;
    CIntN ans; ans = a + b;
	if (ans.get_N() == 1 ) return 1;
	else return 0;
}

bool AutoTest2() {
	CIntN a = 123; 
    CIntN b = 125;
	CIntN ans = a - b;
	if (ans.get_N() == 1 && ans.get_sign() == '-') return 1;
	else return 0;
}

bool AutoTest3(){
    CIntN1 a = 9831367832;
    CIntN0 b("-23943288028342");
    CIntN ans = 5;
    ans += b;
    ans += a;
    CIntN** arr = new CIntN*[3];
    for(size_t i = 0; i < 3; ++i) arr[i] = new CIntN;
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &ans;

    for(size_t i = 0; i < 3; ++i) arr[i]->print("AutoTest.txt");

    std::vector<std::string> answer = {"10", "+", "9831367832", "14 - 23943288028342", "-23933456660505"};
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