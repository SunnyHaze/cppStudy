#pragma once
#include <iostream>
#include <string>
using namespace std;
class Shape
{
public:
    virtual void Show() const = 0;
};
class Rectangle : public Shape
{
private:
    int a, b, c;

public:
    Rectangle()
    {
        a = 1;
        b = 1;
        c = 1;
    }
    Rectangle(int a, int b, int c) : a(a), b(b), c(c)
    {
    }
    void Show() const
    {
        cout << "三角形的三边长为：" << a << " " << b << " " << c << endl;
    }
};
class Circle : public Shape
{
private:
    int r;

public:
    Circle()
    {
        r = 1;
    }
    Circle(int r) : r(r)
    {
    }
    void Show() const
    {
        cout << "圆形的半径为：" << r << endl;
    }
};