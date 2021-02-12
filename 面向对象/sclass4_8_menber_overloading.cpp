#include<iostream>
#include<string>
using namespace std;

class addition{
    public:
        int add(int a,int b);
        string add(string s1,string s2);
        int add(double d1,double d2);
        //double add(double d1,double d2); //不能重载，因为和上一个函数的区别仅仅在于返回值类型不同；
};

int addition::add(int a,int b){
    int c = (a+b) % 250;
    cout <<"两个整数加和并同时对250取余：" << c << endl;
    return c;
}

string addition::add(string s1,string s2){
    string s = s1 + s2;
    cout << "子曰：" << s <<endl;
    return s;
}

int addition::add(double d1,double d2){
    int d = d1 + d2;
    cout << "两个双精度浮点数之和取整：" << d << endl;
    return 0;
}

int main(){
    addition oca;
    oca.add(250,250);
    oca.add("很多250加起来","====0");
    oca.add(128.188,128.218);
    return 0;
}