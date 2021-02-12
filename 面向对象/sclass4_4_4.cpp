#include <iostream>
using namespace std;
int cal(int a){
    return a;
}
int cal(double a){ //不能是float 因为 0.X默认为double 类型。
    return a;
}
int main(){
    cout << cal(5) << cal(0.5);
}