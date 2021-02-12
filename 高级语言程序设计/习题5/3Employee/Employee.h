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
        cout << "��ţ�" << num << endl;
        cout << "������" << name << endl;
        cout << "�������ʣ�" << basicSalary << endl;
        cout << "����" << prize << endl;
    }
    virtual void ShowSalary() const
    {
        cout << "Ա��ʵ������Ϊ��" << endl;
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
        cout << "��ɱ�����" << deductRate << endl;
        cout << "�������۶" << personAmount << endl;
    }
    void ShowSalary() const
    {
        cout << "����Աʵ������Ϊ��" << endl;
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
        cout << "������ɱ�����" << totalDeductRate << endl;
        cout << "�����۶" << totalAmount << endl;
    }
    void ShowSalary() const
    {
        cout << "����ʵ������Ϊ��" << endl;
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
        cout << "��ɱ�����" << deductRate << endl;
        cout << "�������۶" << personAmount << endl;
        cout << "������ɱ�����" << totalDeductRate << endl;
        cout << "�����۶" << totalAmount << endl;
    }
    void ShowSalary() const
    {
        cout << "���۾���ʵ������Ϊ��" << endl;
        cout << (basicSalary + prize + deductRate * personAmount + totalDeductRate * totalAmount) << endl;
    }
};