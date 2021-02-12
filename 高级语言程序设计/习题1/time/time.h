#pragma once
#include <iostream>
class Time
{
private:
    int hh;
    int mm;
    int ss;

public:
    Time();
    ~Time();
    Time(int h, int m, int s);
    void PrintTime();
};