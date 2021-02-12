#include "caller.h"
#include <iostream>
int main()
{
    caller c1;
    try
    {
        c1.input();
        std::cout << "请输入呼叫对象：" << std::endl
                  << "1.保安   2.保健站    3.餐厅" << std::endl;
        int choose;
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            c1.cPolice();
            break;
        case 2:
            c1.cClinic();
            break;
        case 3:
            c1.cRestaurant();
            break;
        default:
            throw "错误的选择，没有指定对象！";
            break;
        }
    }
    catch (const char *mess)
    {
        std::cout << mess << std::endl;
    }
    catch (...)
    {
        std::cout << "出现其他异常！" << std::endl;
    }
    system("PAUSE");
    return 0;
}