#include <iostream>
#include <string>
using namespace std;
int GetMax(int a,int b){
    cout <<"���ú���1 ";
    return a > b ? a : b;
}
char GetMax(char a,char b){
    cout <<"���ú���2 ";
    return a > b ? a : b;
}
// template <class type1,class type2>
// type1 GetMax(type1 x, type2 y){
//     cout <<"���ú���ģ��1 ";
//     return x>y?x:y;
// }
template <class type1,class type2,class type3> 
type1 GetMax(type1 x, type2 y,type3 z){
    cout << "���ú���ģ��2 ";
    return x>y?(x>z?x:z) : (y>z?y:z);
}
//ϵͳ�ȵ������غ�������Ѱ�Ҳ������غ���֮��ſ�ʼѰ������ģ�塣ע�⣬����ģ��ͺ�������ͬʱ����ʱ������������ʽת���Ļ���
//����û�ж�Ӧ�ĺ���ģ����֮ƥ�䣬����Զ���ʼ��ʽת����
int main(){
    cout << "   " << GetMax(10,20) << endl;
    cout << "   " << GetMax('a','i') << endl;
    // cout << "   " << GetMax(1.0,2.0) << endl;
    cout << "   " << GetMax('a',100) << endl;
    cout << "   " << GetMax('a',4,'c') << endl;
    cout << "   " << GetMax(98,99.8) << endl;
    return 0;
}
