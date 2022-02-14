#include "CIntN.hpp"

CIntN::CIntN(int64_t x){
    if(x < 0) sign_ = 0;
    if(x < 0) x = -x;

    int64_t t = x;
    while(t > 0){
        ++N_;
        t /= 10;
    }
    if(x == 0) ++N_;

    if(num_) delete[] num_;
    num_ = new int[N_];

    for(size_t i = N_-1; i != 0; --i){
        num_[i] = x%10;
        x /= 10;
    }
    num_[0] = x;
}
CIntN::CIntN(const std::string& s){
    std::string temp;
    if(s[0] == '-' || s[0] == '+') temp = s.substr(1);
    else temp = s;

    if(is_number(temp)){
        N_ = temp.size();

        if(s[0] == '-') sign_ = 0;

        num_ = new int[N_];
        for(size_t i = 0; i < N_; ++i){
            num_[i] = static_cast<int>(temp[i]) - 48;
        }
    }else throw std::invalid_argument("Expected int, got \'" + s + "\'");
        
}
CIntN::CIntN(const CIntN& n){
    N_ = n.N_;
    sign_ = n.sign_;
    if(num_) delete[] num_;
    num_ = new int[N_];
    for(size_t i = 0; i < N_; ++i) num_[i] = n.num_[i]; 
}

CIntN& CIntN::operator=(const CIntN& n){
    if(this == &n) return *this;
    CIntN copy = n;
    swap(copy);
    return *this;
}
CIntN& CIntN::operator=(const std::string& s){
    CIntN temp(s);
    swap(temp);
    return *this;
}

void CIntN::swap(CIntN& n){
    std::swap(num_, n.num_);
    std::swap(N_, n.N_);
    std::swap(sign_, n.sign_);
}
    
void CIntN::print(const std::string& file_name){
    std::ofstream out(file_name, std::ios_base::app);
    if(!out){
        std::cout << "Error! Cannot open file!\n";
        return;
    }
    if(!sign_) out << "-";
    for(size_t i = 0; i < N_; ++i) out << num_[i];
    out.close();
}
void CIntN::print(){
    if(!sign_) std::cout << "-";
    for(size_t i = 0; i < N_; ++i) std::cout << num_[i];
}

char CIntN::get_sign() const{
    if(sign_ == 1) return '+';
    else return '-';
}
size_t CIntN::get_N() const{
    return N_;
}

void CIntN::new_sign(char sgn){
    if(sgn == '+') sign_ = 1;
    else sign_ = 0;
}

CIntN::~CIntN(){
    delete[] num_;
}