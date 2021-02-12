#include "sclass2_8_cpoint.cpp"
int main(){
    CPoint a(20,50);
    CPoint b(a);
    CPoint c = a;
    cout << "点a的坐标是(" << a.getx()<<","<<a.gety()<<")" << endl;
    cout << "点b的坐标是(" << b.getx()<<","<<b.gety()<<")" << endl;
    cout << "点c的坐标是(" << c.getx()<<","<<c.gety()<<")" << endl;
}
