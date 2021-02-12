#include "solve.h"
solve::solve()
{
    std::cout << "Ĭ�Ϲ��� x^2 + 2x + 1" << std::endl;
    constant = 1;
    primary = -2;
    second = 1;
}

solve::solve(float a, float b, float c)
{
    if (a - 0 < 1e-6)
        throw "��ߴ����Ϊ0��";
    constant = c;
    primary = b;
    second = a;
}

solve::~solve()
{
    ;
}

void solve::input()
{
    std::cout << "�����������ϵ����";
    std::cin >> constant;
    if (constant - 0 < 1e-6)
        throw "������ϵ������Ϊ�㣡";
    std::cout << "������һ����ϵ����";
    std::cin >> primary;
    std::cout << "�����볣����";
    std::cin >> second;
}

void solve::solute()
{
    int a = second, b = primary, c = constant;
    float delta;
    float x;
    delta = b * b - 4 * a * c;
    if (delta < -1e-6)
        std::cout << "�÷������޽⣡";
    if (delta < 1e-6 && delta > -1e-6)
    {
        x = -b / 2 / a;
        std::cout << "�������Ψһ��Ϊ��\nx=";
        printf("%3.f\n", x);
    }
    if (delta > 1e-6)
    {
        x = (-b + sqrt(delta)) / 2 / a;
        std::cout << "������Ľ�Ϊ��\nx1=";
        printf("%3.f", x);
        x = (-b - sqrt(delta)) / 2 / a;
        std::cout << "\nx2=";
        printf("%3.f\n", x);
    }
}