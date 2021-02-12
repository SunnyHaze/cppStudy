#include <iostream>
#include <string>
using namespace std;
class cOperator{
    public:
        cOperator(int b = 0);

        int operator ++(int i);
        int operator ++();
        int operator()();

        cOperator operator = (int a);
        cOperator operator + (cOperator ob);

        bool operator > (cOperator ob);
        bool operator <= (cOperator ob);
        friend istream &operator >> (istream &cin,cOperator &obj);
        friend ostream &operator << (ostream &cout,cOperator &obj);
    public:
        int m_v;
};
//���룬�����������أ�
istream &operator >> (istream &cin,cOperator &obj){
    cin >> obj.m_v;
}
ostream &operator << (ostream &cout,cOperator &obj){
    cout << obj.m_v;
}

// ��ĺ���ʵ��
cOperator::cOperator(int b) : m_v(b){
    ;
}

int cOperator::operator++(int i){
    int iRV = m_v;
    if(m_v < 65535)
        m_v++;
    else 
        m_v = 0;
    return iRV;
}

int cOperator::operator++(){
    if(m_v < 65535)
        m_v++;
    else
        m_v = 0;
    return m_v;
}

int cOperator::operator() (){
    return m_v;
}

cOperator cOperator::operator=(int a){
    m_v = a;
    return *this;
}

cOperator cOperator::operator+(cOperator ob){
    m_v = m_v + ob.m_v;
    if(m_v > 66536)
        m_v = m_v - 65536;
    return *this;
}

bool cOperator::operator > (cOperator ob){
    if(m_v > ob.m_v)
        return true;
    else
        return false;
}

bool cOperator::operator <= (cOperator ob){
    if(m_v <= ob.m_v)
        return true;
    else
        return false;
}
//������
int main(){
    cOperator oco1,oco2(10);
    oco1 = ++oco2;
    cout << "ǰ׺++��" << oco1() << "=" << oco2() << endl;
    oco1 = oco2++;
    cout << "��׺++��" << oco1() << "<" << oco2() << endl;
    oco1 = 10;
    cout << "��ֵ=��" << oco1() << endl;
    oco2 = oco2 + oco1;
    cout << "���󣫶���" << oco1() << ";" << oco2() << endl;
    cout << "����>����" << (oco2 > oco1) << endl;
    cout << "���� <= ����" << (oco2 <= oco1) << endl;
    cin >> oco1;
    cout << oco1;
    return 0;
}
