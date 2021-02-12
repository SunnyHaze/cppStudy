#include "Date.h"
void Date::SetDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
Date::Date()
{
    year = 2000;
    month = 1;
    day = 1;
}
void Date::Print()
{
    std::cout << year << "/" << month << "/" << day << std::endl;
}
bool Date::IsLeapYear()
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
Date &Date::operator++()
{
    if (this->IsLeapYear())
        month_list[1] = 29;
    else
        month_list[1] = 28;
    day++;
    if (month_list[month - 1] < day)
    {
        day -= month_list[month - 1];
        month++;
    }
    if (month == 13)
    {
        month = 1;
        year++;
    }
    return *this;
}
Date::~Date()
{
    ;
}
Date::Date(const Date &obj)
{
    year = obj.year;
    month = obj.month;
    day = obj.day;
}
Date Date::operator++(int)
{
    Date temp(*this);
    if (this->IsLeapYear())
        month_list[1] = 29;
    else
        month_list[1] = 28;
    day++;
    if (month_list[month - 1] < day)
    {
        day -= month_list[month - 1];
        month++;
    }
    if (month == 13)
    {
        month = 1;
        year++;
    }
    return temp;
}
Date &Date::operator--()
{
    day--;
    if (this->IsLeapYear())
        month_list[1] = 29;
    else
        month_list[1] = 28;
    if (day == 0 && month == 1)
    {
        year--;
        day += month_list[11];
        month = 12;
    }
    else if (day == 0 && month != 1)
    {
        month--;
        day += month_list[month - 1];
    }
    return *this;
}

Date Date::operator--(int)
{
    Date temp(*this);
    day--;
    if (this->IsLeapYear())
        month_list[1] = 29;
    else
        month_list[1] = 28;
    if (day == 0 && month == 1)
    {
        year--;
        day += month_list[11];
        month = 12;
    }
    else if (day == 0 && month != 1)
    {
        month--;
        day += month_list[month - 1];
    }
    return temp;
}
