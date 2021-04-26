#include <cmath>
#include <cassert>
#include "fint.h"

using namespace  std;

fint::fint(int_t n) {
    val = n;
}

fint::fint(const std::initializer_list<int_t>& lf,
       const std::initializer_list<int_t>& lm) {
    assert (lf.size() > 0);
    assert (lf.size() == lm.size());
    val = 1;
    //todo: complete the method.

}
bool fint::divides(const fint& a) const {
    return( val % a.val == 0);
}

int_t fint::to_int() const {
    return val;
}

bool fint::is_prime() const {
    int cpt = 1, divider = 2;
    bool result = true;
    do{
        if(val % divider == 0) {
            cpt++;
            if(cpt > 2) {
                result = false;
                break;
            }
        }
        divider++;
    }while(val >= divider);

    return result;
}

bool operator==(const fint& a, const fint& b) {
    return a.val == b.val;
}

bool operator!=(const fint& a, const fint& b) {
    return a.val != b.val;
}

fint lcm(const fint& a, const fint& b) {
    int_t va = a.val, vb = b.val;
    int_t p = va * vb;
    while (va != vb) {
        if (va < vb)
            vb -= va;
        else
            va-= vb;
    } 
    int_t result = (int_t)(p/va);
    return fint(result);
}

fint gcd(const fint& a, const fint& b) {
    int_t va = a.val, vb = b.val;
    int_t r, q = 0;
    
    while(true) {
        r = va % vb;
        q = (va - r)/ vb;
        if (r == 0)
            break;
        va = vb;
        vb = r;
    }
    
    return fint(vb);
}

fint operator*(const fint& a, const fint& b) {
    return fint(a.val * b.val);
}

fint operator/(const fint& a, const fint& b) {
    return fint(a.val/b.val);
}

fint pow(const fint& a, unsigned int n) {
    int_t result = (int_t) pow((long double)a.val, n);
    return fint(result);
}

std::ostream& operator<<(std::ostream& os, const fint& a) {
    os << a.val;
    return os;
}