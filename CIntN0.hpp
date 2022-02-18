#ifndef CFCB98EC_557D_4B24_A9C4_ED760B265A84
#define CFCB98EC_557D_4B24_A9C4_ED760B265A84

#include "CIntN.hpp"

class CIntN0 : public CIntN{
public:
    using CIntN::CIntN;
    using CIntN::operator=;

    CIntN0(const CIntN& n) : CIntN(n) {};
    
    void print_to_file() override {
        std::ofstream out(fileName_, std::ios_base::app);
        if(!out){
            std::cout << "Error! Cannot open file!\n";
            return;
        }
        
        
        if(sign_ == 0) out << "- ";
        
        for(size_t i = 0; i < N_; ++i) out << num_[i] << " ";
        out << "\n";

        out.close();
    }
};

CIntN0 operator+(const CIntN& a, const CIntN& b);
CIntN0 operator-(const CIntN& a, const CIntN& b);

#endif /* CFCB98EC_557D_4B24_A9C4_ED760B265A84 */
