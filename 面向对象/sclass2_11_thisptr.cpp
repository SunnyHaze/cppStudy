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
//this ָ����ʽʡ�Ե��ˣ����Բ��г�Ա��������ֱ�Ӷ����ݳ�Ա���в������������
CPoint::CPoint(float x1,float y1){ 
    this->x = x1;
    this->y = y1;
}
//����ԭ��Ϊ  void move(point *this,float x1,float y1)
void CPoint::move(float x1,float y1){ 
    this->x = x1;
    this->y = y1;
}
//����thisָ����ǿ�� �����β� �� ���ݳ�Ա �Ŀɶ���
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