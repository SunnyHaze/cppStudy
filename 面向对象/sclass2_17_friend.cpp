#include <iostream>
#include <math.h>
using namespace std;

class point {
    public:
    point(double xx = 0 , double yy = 0){
        x = xx;
        y = yy;
    }
    double getx(){
        return x;
    }
    double gety(){
        return y;
    }
    friend double fDist(point *p1,point *p2);//������Ԫ��������ֱ�ӷ���������˽�г�Ա X y������Ϊû��thisָ�룬������Ҫ���ݶ���������ָ��ȥ����˽�����ݳ�Ա��
    private:
        double x,y;
};
double fDist(point *p1,point *p2){  //������point�ĳ�Ա������֪ʶһ����ͨ�ĺ��������Զ���ʱ������Ҫ����point::fdist
    double x = p1 -> x - p2 -> x;
    double y = p1 -> y - p2 -> y;
    return sqrt(x * x + y * y);
}

int main(){
    point *p1 = new point (1,1);
    point *p2 = new point (2,2);
    cout << "��������Ϊ��";
    cout << fDist(p1,p2) << endl;
    delete p1;
    delete p2;
    return 0;
     
}