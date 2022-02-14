#ifndef C75F998A_A15A_41A6_A37F_6ABADB9ED1CE
#define C75F998A_A15A_41A6_A37F_6ABADB9ED1CE

#include "head.hpp"

class CIntN{
protected:
    size_t N_ = 0;
    bool sign_ = 1;     // 1 = '+', 0 = '-';
    int* num_ = nullptr;
public:
    CIntN() = default;
    CIntN(int64_t x);
    CIntN(const std::string& s);
    CIntN(const CIntN& n);

    CIntN& operator=(const CIntN& n);
    CIntN& operator=(const std::string& s);

    void swap(CIntN& n);

    CIntN& operator+=(const CIntN& n);
    CIntN& operator++();
    CIntN operator++(int);
    CIntN& operator-=(const CIntN& n);
    CIntN& operator--();
    CIntN operator--(int);

    virtual void print(const std::string& file_name);
    void print();

    char get_sign() const;
    size_t get_N() const;

    void new_sign(char sgn);

    virtual ~CIntN();
};

CIntN operator+(const CIntN& a, const CIntN& b);
CIntN operator-(const CIntN& a, const CIntN& b);

#endif /* C75F998A_A15A_41A6_A37F_6ABADB9ED1CE */
