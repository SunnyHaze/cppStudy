#include<iostream>
#include <string>
using namespace std;

template <class type,class T>
type getMax(type a, type b,T c);

int main(){
    string str1("Rong Ji") ,str2("Zheng Ming"), str3("Jing Tao");
    char n = 21;
    cout << n << endl;
    cout << "int:10,30,21,max="<< getMax(10,20,n) << endl;
    cout << "double:51.8,20.8,31.6,max=" << getMax(51.8,20.8,31.6)<<endl;
    cout <<"string: max =" << getMax(str1,str2,str3) << endl;
    return 0;
}

template <class type,class T>
type getMax(type a,type b,T c){
    type t;
    t = a > b ? (a > c ? a : c) : (b > c ? b : c);
    return t;
}