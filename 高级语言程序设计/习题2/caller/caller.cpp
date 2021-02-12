#include "caller.h"
caller::caller()
{
    ;
}
caller::~caller()
{
    ;
}
void caller::input()
{
    std::cout << "请输入8位ID号码：";
    std::cin >> ID;
    if (ID.size() != 8)
        throw "ID位数非法！";
    std::cout << "请输入用户名：";
    std::cin >> userName;
    std::cout << "请输入用户地址：";
    std::cin >> userAddress;
    std::cout << "请输入呼叫地：";
    std::cin >> callAddress;
}

void caller::printinfo()
{
    std::cout << "呼叫器号码：" << ID
              << std::endl
              << "用户姓名：" << userName
              << std::endl
              << "用户地址：" << userAddress
              << std::endl
              << "呼叫地：" << callAddress << std::endl;
}

void caller::cPolice()
{
    std::cout << "呼叫保安！" << std::endl;
    printinfo();
}

void caller::cClinic()
{
    std::cout << "呼叫保健室！" << std::endl;
    printinfo();
}
void caller::cRestaurant()
{
    std::cout << "呼叫餐厅！" << std::endl;
    printinfo();
}
