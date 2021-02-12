#include <iostream>
#include <string>
using namespace std;
int GetMax(int a,int b){
    cout <<"调用函数1 ";
    return a > b ? a : b;
}
char GetMax(char a,char b){
    cout <<"调用函数2 ";
    return a > b ? a : b;
}
// template <class type1,class type2>
// type1 GetMax(type1 x, type2 y){
//     cout <<"调用函数模板1 ";
//     return x>y?x:y;
// }
template <class type1,class type2,class type3> 
type1 GetMax(type1 x, type2 y,type3 z){
    cout << "调用函数模板2 ";
    return x>y?(x>z?x:z) : (y>z?y:z);
}
//系统先调用重载函数，在寻找不到重载函数之后才开始寻找重载模板。注意，函数模板和函数重载同时存在时，将不会有隐式转换的机会
//但若没有对应的函数模板与之匹配，则会自动开始隐式转换。
int main(){
    cout << "   " << GetMax(10,20) << endl;
    cout << "   " << GetMax('a','i') << endl;
    // cout << "   " << GetMax(1.0,2.0) << endl;
    cout << "   " << GetMax('a',100) << endl;
    cout << "   " << GetMax('a',4,'c') << endl;
    cout << "   " << GetMax(98,99.8) << endl;
    return 0;
}
