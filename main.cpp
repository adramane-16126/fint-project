#include <iostream>
#include "fint.h"
using namespace std;

int main() {
    fint f({2,5,11}, {1,2,2});
    cout<<"La valeur en entier est: "<< f.to_int()<<endl;
    f.print_facts();
    return 0;
}