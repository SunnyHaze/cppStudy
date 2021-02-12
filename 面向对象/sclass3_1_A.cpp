#include "sclass3_1_A.h"

void A::setx(int i){
    x = i;
}
int A::getx(void) const{
    return x;
}
void B::setvalue(int a,int b,int c,int d,int e){
    setx(a);
    y = b;
    z = c;
    m = d;
    n = e;
}
void B::display(void) const{
    cout << "x=" << getx() <<endl;
    cout << "y=" << y << endl;
    cout << "z=" << z << endl;
    cout << "m=" << m << endl;
    cout << "n=" << n << endl;
}
