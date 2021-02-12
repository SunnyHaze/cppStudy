#include <iostream>
#include <string>
using namespace std;

class cinteger{
public:
    cinteger(int);
    void setitem(int);
    int getitem();
private:
    int m_item;
};

class cfloat{
public:
    cfloat(double);
    void setitem(double);
    double getitem();

private:
    double m_item;
};

cinteger::cinteger(int item){
    m_item = item;
}

int cinteger::getitem(){
    return m_item;
}

void cinteger::setitem(int item){
    m_item = item;
}

cfloat::cfloat(double item){
    m_item = item;
}
double cfloat::getitem(){
    return m_item;
}
void cfloat::setitem(double item){
    m_item = item;
}

int main(){
    cinteger obj1(128);
    cout << obj1.getitem() << endl;
    obj1.setitem(218);
    cout << obj1.getitem() << endl;

    cfloat obj2(2.18);
    cout << obj2.getitem() << endl;
    obj2.setitem(1.28);
    cout << obj2.getitem() << endl;
    return 0;
}
