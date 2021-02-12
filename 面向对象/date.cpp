#include "date.h"
void Date::SetDate(int y,int m,int d){
    year = y;
    month = m;
    day = d;
}

void Date::Print(){
    std::cout << year << "/" << month << "/" << day << "/" << std::endl;
}
int Date::IsLeapYear(){
    return (year % 4 == 0 && year % 100 != 0) || year % 400 ==0;
}
