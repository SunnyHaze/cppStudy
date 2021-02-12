#include <iostream>  //�麯�������������м̳й�ϵ������� �����Ҿ������Ǿ�̬��Ա������
#include <stdio.h>
using namespace std;

class shape{
    public:
        shape(double,double,double);
        virtual void show(void) const;
    protected:
        double m_x,m_y,m_z,m_area;
};

class circle : public shape{
    public:
        circle(double x,double y ,double z,double r);
        void show(void) const; 
    protected:
        double m_r;
};

class rectangle: public shape{
    public:
        rectangle(double x,double y ,double z,double l,double w);
        void show() const;
    protected:
        double m_len;
        double m_wid;
};

class square: public shape{
    public:
        square(double x,double y,double z,double edge);
        void show() const;
    protected:
        double m_edge;
};

shape::shape(double x, double y,double z):m_x(x),m_y(y),m_z(z){

}
void shape::show() const{
    printf("x=%.2lf,y=%.2lf,z=%.2lf,area=%.2lf\n",m_x,m_y,m_z,m_area);
}
circle::circle(double x, double y,double z,double r):shape(x,y,z),m_r(r){

}
void circle::show() const{
    printf("x=%.2lf,y=%.2lf,z=%.2lf,r=%.2lf\n",m_x,m_y,m_z,m_r);
}

rectangle::rectangle(double x,double y, double z, double len,double wid):shape(x,y,z),m_len(len),m_wid(wid){

}

void rectangle::show() const{
    printf("x=%.2lf,y=%.2lf,z=%.2lf,lenth=%.2lf,width=%.2f\n",m_x,m_y,m_z,m_len,m_wid);
}

square::square(double x,double y , double z, double edge):shape(x,y,z),m_edge(edge){

}

void square::show() const{
    printf("x=%.2lf,y=%.2lf,z=%.2lf,edge=%.2lf\n",m_x,m_y,m_z,m_edge);
}


// ��������������Զ�
void reference(const shape &rocs){
    rocs.show();
}

int main(){
    shape ocs(1,2,3);
    circle occ(10,20.1,30,100);
    rectangle ocr(1.1,1.2,1.3,5.4,5.5);
    square ocq(2.2,2.3,2.4,10.8);

    cout << "\n 1:ͨ����������õ����麯�����������ԡ���������������" << endl;
    reference(ocs);
    reference(occ);
    reference(ocr);
    reference(ocq);

    cout <<"\n 2:ͨ�������ָ������麯��ͬ�����������ԡ���������������" << endl;
    shape *p;
    p = &ocs;
    p->show();
    p = &occ;
    p->show();
    p = & ocr;
    p->show();
    p = &ocq;
    p->show();

    cout << "\n 3:ͨ��������ò����������ԣ������ñ�����ȷ����������������" << endl;
    ocs.show();
    occ.show();
    ocr.show();
    ocq.show();

    return 0;
}
