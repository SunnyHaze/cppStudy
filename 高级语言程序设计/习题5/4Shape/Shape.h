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
        cout << "�����ε����߳�Ϊ��" << a << " " << b << " " << c << endl;
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
        cout << "Բ�εİ뾶Ϊ��" << r << endl;
    }
};