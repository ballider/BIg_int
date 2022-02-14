#ifndef E260E68E_777C_4D75_8167_3AB68CBDD1DF
#define E260E68E_777C_4D75_8167_3AB68CBDD1DF

#include "CIntN.hpp"

class CIntN1 : public CIntN{
public:
    using CIntN::CIntN;
    CIntN1(const CIntN& n) : CIntN(n) {};

    void print(const std::string& file_name) override {
        std::ofstream out(file_name, std::ios_base::app);
        if(!out){
            std::cout << "Error! Cannot open file!\n";
            return;
        }
        
        out << N_ << "\n";
        
        if(sign_ == 1) out << "+\n";
        else out << "-\n";
        
        for(size_t i = 0; i < N_; ++i) out << num_[i];
        out << "\n";

        out.close();
    }
};

#endif /* E260E68E_777C_4D75_8167_3AB68CBDD1DF */
