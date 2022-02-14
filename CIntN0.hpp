#ifndef CFCB98EC_557D_4B24_A9C4_ED760B265A84
#define CFCB98EC_557D_4B24_A9C4_ED760B265A84

#include "CIntN.hpp"

class CIntN0 : public CIntN{
public:
    using CIntN::CIntN;                     
    CIntN0(const CIntN& n) : CIntN(n) {};
    
    void print(const std::string& file_name) override {
        std::ofstream out(file_name, std::ios_base::app);
        if(!out){
            std::cout << "Error! Cannot open file!\n";
            return;
        }
        
        out << N_ << " ";
        
        if(sign_ == 1) out << "+ ";
        else out << "- ";
        
        for(size_t i = 0; i < N_; ++i) out << num_[i];
        out << "\n";

        out.close();
    }
};

#endif /* CFCB98EC_557D_4B24_A9C4_ED760B265A84 */
