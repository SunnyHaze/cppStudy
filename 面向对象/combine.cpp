#include "combine.h"
item::item()
{
    number = 0;
    cout << "���ڴ�������" << endl;
}
item::~item()
{
    cout << "�����Ѿ�������" << endl;
}
item::item(int x)
{
    number = x;
    cout << "����ֵΪ" << x << "�Ķ���" << endl;
}
item item::operator+(item obj)
{
    item temp(obj.getnum() + this->getnum());
    return temp;
}

item &item::operator=(item obj)
{
    this->number = obj.number;
    return *this;
}

int item::getnum()
{
    return number;
}