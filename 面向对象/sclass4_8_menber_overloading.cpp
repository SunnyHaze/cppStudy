#include<iostream>
#include<string>
using namespace std;

class addition{
    public:
        int add(int a,int b);
        string add(string s1,string s2);
        int add(double d1,double d2);
        //double add(double d1,double d2); //�������أ���Ϊ����һ������������������ڷ���ֵ���Ͳ�ͬ��
};

int addition::add(int a,int b){
    int c = (a+b) % 250;
    cout <<"���������ӺͲ�ͬʱ��250ȡ�ࣺ" << c << endl;
    return c;
}

string addition::add(string s1,string s2){
    string s = s1 + s2;
    cout << "��Ի��" << s <<endl;
    return s;
}

int addition::add(double d1,double d2){
    int d = d1 + d2;
    cout << "����˫���ȸ�����֮��ȡ����" << d << endl;
    return 0;
}

int main(){
    addition oca;
    oca.add(250,250);
    oca.add("�ܶ�250������","====0");
    oca.add(128.188,128.218);
    return 0;
}