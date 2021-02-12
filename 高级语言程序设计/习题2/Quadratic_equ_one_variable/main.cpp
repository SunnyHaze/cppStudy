#include "solve.h"
int main()
{
    try
    {
        std::cout << "请输入一元二次方程的系数：\n"
                  << "二次项系数：";
        int a, b, c;
        std::cin >> a;
        std::cout << "一次项系数：";
        std::cin >> b;
        std::cout << "常数项：";
        std::cin >> c;
        solve obj1(a, b, c);
        obj1.solute();
    }
    catch (const char *mess)
    {
        std::cout << mess << std::endl;
    }
    system("PAUSE");
    return 0;
}