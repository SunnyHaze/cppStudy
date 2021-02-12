#include "trapzint.cpp"
#include <iostream>
#include <iomanip>
const int pi = 3.14159265357;
using namespace std;
int main(){
    Fun f;
    Trapz trapz1(f);
    cout << "Trapz int :" << setprecision(10) << trapz1(0,2,1e-10)<< endl;
}--