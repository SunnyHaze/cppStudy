#pragma once
#include <iostream>
#include <stdio.h>
#include <cmath>
class solve
{
private:
    float constant;
    float primary;
    float second;

public:
    solve();
    solve(float a, float b, float c); //��float,float,float)�����Σ�һ�Σ�������
    ~solve();
    void input();
    void solute();
};