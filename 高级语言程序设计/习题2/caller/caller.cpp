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
    std::cout << "������8λID���룺";
    std::cin >> ID;
    if (ID.size() != 8)
        throw "IDλ���Ƿ���";
    std::cout << "�������û�����";
    std::cin >> userName;
    std::cout << "�������û���ַ��";
    std::cin >> userAddress;
    std::cout << "��������еأ�";
    std::cin >> callAddress;
}

void caller::printinfo()
{
    std::cout << "���������룺" << ID
              << std::endl
              << "�û�������" << userName
              << std::endl
              << "�û���ַ��" << userAddress
              << std::endl
              << "���еأ�" << callAddress << std::endl;
}

void caller::cPolice()
{
    std::cout << "���б�����" << std::endl;
    printinfo();
}

void caller::cClinic()
{
    std::cout << "���б����ң�" << std::endl;
    printinfo();
}
void caller::cRestaurant()
{
    std::cout << "���в�����" << std::endl;
    printinfo();
}
