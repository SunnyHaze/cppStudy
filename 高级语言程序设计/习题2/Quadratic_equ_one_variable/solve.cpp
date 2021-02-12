#include "solve.h"
solve::solve()
{
    std::cout << "默认构造 x^2 + 2x + 1" << std::endl;
    constant = 1;
    primary = -2;
    second = 1;
}

solve::solve(float a, float b, float c)
{
    if (a - 0 < 1e-6)
        throw "最高次项不能为0！";
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
    std::cout << "请输入二次项系数：";
    std::cin >> constant;
    if (constant - 0 < 1e-6)
        throw "二次项系数不能为零！";
    std::cout << "请输入一次项系数：";
    std::cin >> primary;
    std::cout << "请输入常数项";
    std::cin >> second;
}

void solve::solute()
{
    int a = second, b = primary, c = constant;
    float delta;
    float x;
    delta = b * b - 4 * a * c;
    if (delta < -1e-6)
        std::cout << "该方程组无解！";
    if (delta < 1e-6 && delta > -1e-6)
    {
        x = -b / 2 / a;
        std::cout << "方程组的唯一解为：\nx=";
        printf("%3.f\n", x);
    }
    if (delta > 1e-6)
    {
        x = (-b + sqrt(delta)) / 2 / a;
        std::cout << "方程组的解为：\nx1=";
        printf("%3.f", x);
        x = (-b - sqrt(delta)) / 2 / a;
        std::cout << "\nx2=";
        printf("%3.f\n", x);
    }
}