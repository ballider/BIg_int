#ifndef E260E68E_777C_4D75_8167_3AB68CBDD1DF
#define E260E68E_777C_4D75_8167_3AB68CBDD1DF

#include "CIntN.hpp"

class CIntN1 : public CIntN{
public:
    using CIntN::CIntN;
    using CIntN::operator=;
    
    CIntN1(const CIntN& n) : CIntN(n) {};

    void print_to_file() override {
        std::ofstream out(fileName_, std::ios_base::app);
        if(!out){
            std::cout << "Error! Cannot open file!\n";
            return;
        }
                
        if(sign_ == 0) out << "-\n";

        for(size_t i = 0; i < N_; ++i) out << num_[i] << "\n";

        out.close();
    }
};

#endif /* E260E68E_777C_4D75_8167_3AB68CBDD1DF */
