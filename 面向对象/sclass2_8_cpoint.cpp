#include "sclass2_8_cpoint.h"
CPoint::CPoint(int x1,int y1){
    x = x1;
    y = y1;
}
CPoint::CPoint(CPoint & obj){
    x = obj.x;
    y = obj.y;
}
int CPoint::getx(){
    return x;
}
int CPoint::gety(){
    return y;
}