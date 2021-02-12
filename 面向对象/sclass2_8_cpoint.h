#ifndef _SCLASS2_8_CPOINT_H_
#define _SCLASS2_8_CPOINT_H_

#include <iostream>
using namespace std;

class CPoint{
    public:
        CPoint(int x1,int y1);
        CPoint(CPoint&obj);
        int getx(void);
        int gety(void);
    private:
    int x;
    int y;
};
#endif