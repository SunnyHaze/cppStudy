#include "sclass2_8_cpoint.cpp"
int main(){
    CPoint a(20,50);
    CPoint b(a);
    CPoint c = a;
    cout << "��a��������(" << a.getx()<<","<<a.gety()<<")" << endl;
    cout << "��b��������(" << b.getx()<<","<<b.gety()<<")" << endl;
    cout << "��c��������(" << c.getx()<<","<<c.gety()<<")" << endl;
}
