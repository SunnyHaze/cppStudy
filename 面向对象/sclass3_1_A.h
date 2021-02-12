#ifndef _SCLASS_3_1_A_
#define _SCLASS_3_1_A_

#include <iostream>
using namespace std;
class A{
    public:
        void setx(int i);
        int getx(void) const;
        int z;
    protected:
        int y;
    private:
        int x;
};
class B : public A{
    public:
        void setvalue(int,int,int,int,int);
        void display(void) const;
    protected:
        int m;
    private:
        int n;
};
#endif
