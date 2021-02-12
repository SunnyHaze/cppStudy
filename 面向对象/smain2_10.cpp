#ifndef _SCLASS2_10_CPOINT_H_
#define _SCLASS2_10_CPOINT_H_

#include <iostream>
using namespace std;
class Cpoint{
    public:
    Cpoint(){}
    ~Cpoint(){}
    Cpoint(float x1,float y1);
    void Move(float x1,float y1);
    float x;
    float y;
};
#endif
//以下为Cpoint 成员函数的类外实现；
Cpoint::Cpoint(float x1,float y1){
    x = x1;
    y = y1;
}

void Cpoint::Move(float x1,float y1){
    x = x1;
    y = y1;
}

int main(){
    Cpoint *p = new Cpoint[5];
    for(int i = 0 ; i < 5 ; i++){
        cout << p[i].x << " " << p[i].y << endl;
    }
    for(int i = 0 ; i < 5 ; i++){
        p[i].Move(i,i);
    }
    for(int i = 0 ; i < 5 ; i++){
        cout << p[i].x << " " << p[i].y << endl;
    }
    delete [] p;
    return 0;
}