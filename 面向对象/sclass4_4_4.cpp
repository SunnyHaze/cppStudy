#include <iostream>
using namespace std;
int cal(int a){
    return a;
}
int cal(double a){ //������float ��Ϊ 0.XĬ��Ϊdouble ���͡�
    return a;
}
int main(){
    cout << cal(5) << cal(0.5);
}