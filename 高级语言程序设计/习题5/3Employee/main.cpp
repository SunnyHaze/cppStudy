#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;
int main()
{
    SaleManager mayun(0001, "����", 10000, 1, 0.1, 10000, 0.1, 10000);
    mayun.Show();
    mayun.ShowSalary();
    cout << endl;
    Saleman wangjian(0002, "����", 5000, 1000, 5000, 0.1);
    wangjian.Show();
    wangjian.ShowSalary();
    cout << endl;
    Manager zhangxiaolong(0003, "��С��", 6000, 1, 0.1, 6000);
    zhangxiaolong.Show();
    zhangxiaolong.ShowSalary();
    system("PAUSE");
    return 0;
}