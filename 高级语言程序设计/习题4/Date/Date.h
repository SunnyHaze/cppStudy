#pragma once
#include <iostream>
class Date
{
public:
    Date();
    ~Date();
    Date(const Date &obj);
    void SetDate(int y, int m, int d);
    bool IsLeapYear();
    void Print();
    Date &operator++();
    Date operator++(int);
    Date &operator--();
    Date operator--(int);

private:
    int year;
    int month;
    int day;
    int month_list[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    friend std::ostream &operator<<(std::ostream &out, Date &obj)
    {
        std::cout << obj.year << "/" << obj.month << "/" << obj.day << std::endl;
        return out;
    }
};
