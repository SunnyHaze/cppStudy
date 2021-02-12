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
    friend double fDist(point *p1,point *p2);//利用友元函数方便直接访问类对象的私有成员 X y，但因为没有this指针，所以需要传递对象名或者指针去访问私有数据成员。
    private:
        double x,y;
};
double fDist(point *p1,point *p2){  //它不是point的成员函数，知识一个普通的函数，所以定义时并不需要声明point::fdist
    double x = p1 -> x - p2 -> x;
    double y = p1 -> y - p2 -> y;
    return sqrt(x * x + y * y);
}

int main(){
    point *p1 = new point (1,1);
    point *p2 = new point (2,2);
    cout << "两点间距离为：";
    cout << fDist(p1,p2) << endl;
    delete p1;
    delete p2;
    return 0;
     
}