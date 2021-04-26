#include "util.h"

bool is_prime2(int_t val) {
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