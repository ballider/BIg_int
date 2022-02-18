#include "CIntN.hpp"
#include "CIntN0.hpp"

CIntN& CIntN::operator+=(const CIntN& n){
    if(sign_ != n.sign_){
        if(sign_ == 1){
            CIntN0 temp = n;
            temp.new_sign('+');
            return *this -= temp;
        }else{
            CIntN0 temp = n;
            temp.new_sign('-');
            return *this -= temp;
        }
    }
    
    size_t k = std::min(N_, n.N_);
    int64_t i = static_cast<int>(N_); --i;
    int64_t j = static_cast<int>(n.N_); --j;
    int t = 0;

    int* bar = new int[std::max(N_, n.N_)+1];
    for(size_t q = 0; q < std::max(N_, n.N_)+1; ++q) bar[q] = 0;
    int64_t q = std::max(N_, n.N_);

    while(k > 0){
        int temp = num_[i]+n.num_[j]+t;
        bar[q] = temp%10;
        t = temp/10;
        --q;
        --i;
        --j;
        --k;
    }
        
    while(i > -1){
        int temp = num_[i]+t;
        bar[q] = temp%10;
        t = temp/10;
        --q;
        --i;
    }

    while(j > -1){
        int temp = n.num_[j]+t;
        bar[q] = temp%10;
        t = temp/10;
        --q;
        --j;
    }
        
    if(t != 0) bar[q] = t;

    if(bar[0] == 0) N_ = std::max(N_, n.N_);
    else N_ = std::max(N_, n.N_)+1;

    if(num_) delete[] num_;
    num_ = new int[N_];

    for(int64_t l = N_-1; l >= 0; --l){
        if(bar[0] == 0) num_[l] = bar[l+1];
        else num_[l] = bar[l];
    }
    delete[] bar;

    return *this;
}

CIntN& CIntN::operator++(){
    CIntN0 unit = 1;
    return *this += unit;
}

CIntN& CIntN::operator-=(const CIntN& n){
    if(sign_ == 1 && n.sign_ == 0){
        CIntN0 t = n;
        t.new_sign('+');
        return *this += t;
    }
    if(sign_ == 0 && n.sign_ == 1){
        CIntN0 t = n;
        t.new_sign('-');
        return *this += t;
    }

    bool sgn;   // итоговый знак
    if(N_ == n.N_){
        bool comp = 1;  // 1 = num_ >= n.num_, 0 = num_ < n.num_;
        for(size_t q = 0; q < N_; ++q){
            if(num_[q] > n.num_[q]){
                comp = 1;
                break;
            }
            if(num_[q] < n.num_[q]){
                comp = 0;
                break;
            }
        }
        if(sign_ == 0){
            if(comp) sgn = 0;
            else sgn = 1;
        }else{
            if(comp) sgn = 1;
            else sgn = 0;
        }
    }   
    else if(N_ > n.N_){
        if(sign_ == 1) sgn = 1;
        else sgn = 0;
    }else{
        if(sign_ == 1) sgn = 0;
        else sgn = 1;
    }

    CIntN0 temp = n;
    if(n.N_ > N_) swap(temp);
    if(n.N_ == N_){
        for(size_t q = 0; q < N_; ++q){
            if(num_[q] < n.num_[q]){
                swap(temp);
                break;
            }
        }
    }

    int* bar = new int[N_];
    for(size_t q = 0; q < N_; ++q) bar[q] = 0;
    int64_t q = N_-1;
    
    int64_t i = N_-1;
    int64_t j = temp.N_-1;

    while(j > -1){
        if(num_[i] >= temp.num_[j]) bar[q] = num_[i]-temp.num_[j];
        else{
            int64_t l = i-1;
            while( l > -1){
                if(num_[l] != 0) break;
                --l;
            }
            for(int64_t g = l; g < i; ++g){
                if(g == l) --num_[g];
                else num_[g] = 9;
            }
            bar[q] = 10+num_[i]-temp.num_[j];
            num_[i] = 0;
        }
        --q;
        --i;
        --j;
    }
        
    while(i > -1){
        bar[q] = num_[i];
        --i;
        --q;
    }
        
    size_t fh = 0;
    for(size_t l = 0; l < N_; ++l){
        if(bar[l] == 0) ++fh;
        else break;
    }

    q = N_-1;

    N_ = N_-fh;
    if(num_ != nullptr) delete[] num_;
    num_ = new int[N_];
    for(int64_t l = N_-1; l >=0; --l){
        num_[l] = bar[q];
        --q;
    }
    delete[] bar;
    
    sign_ = sgn;

    return *this;
}

CIntN& CIntN::operator--(){
    CIntN0 unit = 1;
    return *this -= unit;
}

CIntN0 operator+(const CIntN& a, const CIntN& b){
    CIntN0 sum = a;
    sum += b;
    return sum;
}

CIntN0 operator-(const CIntN& a, const CIntN& b){
    CIntN0 dif = a;
    dif -= b;
    return dif;
}
