#include "caller.h"
#include <iostream>
int main()
{
    caller c1;
    try
    {
        c1.input();
        std::cout << "��������ж���" << std::endl
                  << "1.����   2.����վ    3.����" << std::endl;
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
            throw "�����ѡ��û��ָ������";
            break;
        }
    }
    catch (const char *mess)
    {
        std::cout << mess << std::endl;
    }
    catch (...)
    {
        std::cout << "���������쳣��" << std::endl;
    }
    system("PAUSE");
    return 0;
}