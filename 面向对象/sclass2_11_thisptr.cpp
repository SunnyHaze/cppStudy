#include <iostream>
using namespace std;
class CPoint
{
    public:
    CPoint(){}
    ~CPoint(){}
    CPoint(float x1,float x2);
    void move(float x1,float x2);

    auto myself();
    void again(float x,float y);

    float x;
    float y;
};

auto CPoint::myself(){
    return *this;
}
//this 指针隐式省略掉了，所以才有成员函数可以直接对数据成员进行操作的情况出现
CPoint::CPoint(float x1,float y1){ 
    this->x = x1;
    this->y = y1;
}
//隐含原型为  void move(point *this,float x1,float y1)
void CPoint::move(float x1,float y1){ 
    this->x = x1;
    this->y = y1;
}
//利用this指针增强了 重名形参 和 数据成员 的可读性
void CPoint::again(float x,float y){
    this -> x = x;  
    this -> y = y;
}
int main(){
    CPoint *p1 = new CPoint(1,1);
    p1->move(10,10);
    cout << p1->x <<"," << p1->y << endl;
    delete p1;
    return 0;
    
}