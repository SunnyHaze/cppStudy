#pragma once
#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
    int num;
    string name;
    double basicSalary;
    double prize;

public:
    Employee(int number, string ename, double bsalary, double eprize) : num(number), name(ename), basicSalary(bsalary), prize(eprize)
    {
    }
    virtual void Show() const
    {
        cout << "编号：" << num << endl;
        cout << "姓名：" << name << endl;
        cout << "基本工资：" << basicSalary << endl;
        cout << "奖金：" << prize << endl;
    }
    virtual void ShowSalary() const
    {
        cout << "员工实发工资为：" << endl;
        cout << (prize + basicSalary) << endl;
    }
};
class Saleman : virtual public Employee
{
protected:
    double deductRate;
    double personAmount;

public:
    Saleman(int number, string ename, double bsalary, double eprize, double dRate, double pamount) : Employee(number, ename, bsalary, eprize), deductRate(dRate), personAmount(pamount) //num(number), name(ename), basicSalary(bsalary), prize(eprize)
    {
    }
    void Show() const
    {
        Employee::Show();
        cout << "提成比例：" << deductRate << endl;
        cout << "个人销售额：" << personAmount << endl;
    }
    void ShowSalary() const
    {
        cout << "销售员实发工资为：" << endl;
        cout << (basicSalary + prize + deductRate * personAmount) << endl;
    }
};
class Manager : virtual public Employee
{
protected:
    double totalDeductRate;
    double totalAmount;

public:
    Manager(int number, string ename, double bsalary, double eprize, double tRate, double tamount) : Employee(number, ename, bsalary, eprize), totalDeductRate(tRate), totalAmount(tamount) //num(number), name(ename), basicSalary(bsalary), prize(eprize)
    {
    }
    void Show() const
    {
        Employee::Show();
        cout << "经理提成比例：" << totalDeductRate << endl;
        cout << "总销售额：" << totalAmount << endl;
    }
    void ShowSalary() const
    {
        cout << "经理实发工资为：" << endl;
        cout << (basicSalary + prize + totalDeductRate * totalAmount) << endl;
    }
};
class SaleManager : public Manager, public Saleman
{
public:
    SaleManager(int number, string ename, double bsalary, double eprize, double dRate, double pamount, double tRate, double tamount) : Employee(number, ename, bsalary, eprize), Saleman(number, ename, bsalary, eprize, dRate, pamount), Manager(number, ename, bsalary, eprize, tRate, tamount)
    {
    }
    void Show() const
    {
        Employee::Show();
        cout << "提成比例：" << deductRate << endl;
        cout << "个人销售额：" << personAmount << endl;
        cout << "经理提成比例：" << totalDeductRate << endl;
        cout << "总销售额：" << totalAmount << endl;
    }
    void ShowSalary() const
    {
        cout << "销售经理实发工资为：" << endl;
        cout << (basicSalary + prize + deductRate * personAmount + totalDeductRate * totalAmount) << endl;
    }
};