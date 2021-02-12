#include "combine.h"
item::item()
{
    number = 0;
    cout << "正在创建对象" << endl;
}
item::~item()
{
    cout << "对象已经被析构" << endl;
}
item::item(int x)
{
    number = x;
    cout << "创建值为" << x << "的对象" << endl;
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