#ifndef  _SCLASS2_6_DATE_H_
#define _SCLASS2_6_DATE_H_

#include <iostream>
using namespace std;

class Date{
    public:
        Date(int y = 2000,int m = 1,int d = 1);
        ~Date();
        void SetDate(int y,int m,int d);
        int IsLeapYear();
        void Print();
    private:
        int year;
        int month;
        int day;
};
#endif