#include "head.hpp"
#include "CIntN.hpp"
#include "CIntN0.hpp"
#include "CIntN1.hpp"
#include "Autotest.hpp"

int main(){
    if(!AutoTest()){
        return 0;
    }
    
    std::cout << "Enter file name: ";
    std::string file; std::cin >> file;
    
    std::ifstream inp(file);
    if(!inp){
        std::cout << "Error! Cannot open file!\n";
        return -1;
    }

    size_t k = 0;

    std::string line;
    while(getline(inp, line)) ++k;
    inp.close();

    CIntN** arr = new CIntN*[k];

    inp.open(file);
    size_t i = 0;
    while(!inp.eof()){
        bool I; std::string FileName; std::string num;
        inp >> I;
        inp >> FileName;
        inp >> num;

        if(I == 0 && i < k){
            arr[i] = new CIntN0(num);
            arr[i]->updateFile(FileName);
        }
        if(I == 1 && i < k){
            arr[i] = new CIntN1(num);
            arr[i]->updateFile(FileName);
        }

        ++i;
    }
    inp.close();

    for(size_t j = 0; j < k; ++j){
        arr[j]->print_to_file();
    }
    
    for(size_t j = 0; j < k; ++j){
        delete arr[j];
    }
    delete[] arr;
    
    return 0;
}