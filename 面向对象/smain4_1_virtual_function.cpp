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

circle::circle(double x, double y,double z,double r) : shape(x,y,z) , m_r(r){  //Ҫ��������Ĺ��췽ʽ�����ಢ����ֱ�Ӵ����˳�Ա������һ�ְ����ڵĹ�ϵ��

}

void circle::show() const{
    printf("x=%.2lf,y=%.2lf,z=%.2lf,r=%.2lf\n",m_x,m_y,m_z,m_r);
}

void reference(const shape &rocs){ //��������� ǿ�����޷� ����������ĳ�Ա������  �麯���� ���ͺ�󶨡�������
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

    //��������Ҳ�޷���ȡshape ���͵� show���� �� circle�������ࣩ�е����أ�
    reference(ocs);
    reference(occ);
    return 0;
}