#include "sclass2_6_date.h"
Date::~Date(){
    cout << "正在析构" << year << "年" << month << "月" << day << "日对象" << endl; //后创建的对象先析构 //仅仅是在消亡前执行的函数，并不是消亡的代表。
}
Date::Date(int y,int m, int d){
    year = y;
    month = m;
    day = d;
}
void Date::SetDate(int y,int m,int d){
    year = y;
    month = m;
    day = d;
}
int Date::IsLeapYear(){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;  
}
void Date::Print(){
    cout << year << "年" << month << "月" << day << "日";
}
