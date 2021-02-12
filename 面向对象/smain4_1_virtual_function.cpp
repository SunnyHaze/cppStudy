#include <iostream>
#include <stdio.h>
using namespace std;
class shape{
    public:
        shape(double,double,double);
        void show(void) const;
    protected:
        double m_x,m_y,m_z;
};

class circle : public shape{
    public:
        circle(double x,double y ,double z,double r);
        void show(void) const; 
    protected:
        double m_r;
};

shape::shape(double x,double y,double z):m_x(x), m_y(y), m_z(z) {

}

void shape::show() const{
    printf("x=%.2lf,y=%.2lf,z=%.2lf\n",m_x,m_y,m_z);
}

circle::circle(double x, double y,double z,double r) : shape(x,y,z) , m_r(r){  //要明晰基类的构造方式，基类并不是直接创建了成员，而是一种包含于的关系；

}

void circle::show() const{
    printf("x=%.2lf,y=%.2lf,z=%.2lf,r=%.2lf\n",m_x,m_y,m_z,m_r);
}

void reference(const shape &rocs){ //基类的引用 强调其无法 调用派生类的成员函数。  虚函数起到 “滞后绑定”的作用
    rocs.show();
}
int main(){
    shape ocs(1.0,2.0,3.0);
    circle occ(10.0,20.1,30.0,100.0);

    // shape *pocs;
    // pocs = &ocs;
    // pocs->show();
    // pocs = &occ;
    // pocs->show();
    // occ.show();

    //利用引用也无法调取shape 类型的 show函数 于 circle（派生类）中的重载；
    reference(ocs);
    reference(occ);
    return 0;
}