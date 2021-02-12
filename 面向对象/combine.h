#pragma once
#include <iostream>
using namespace std;
class item
{
private:
    int number;

public:
    item();
    item(int x);
    ~item();
    item operator+(item obj);
    item &operator=(item obj);
    int getnum();
};