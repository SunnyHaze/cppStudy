#include <iostream>
#include <string>
using namespace std;
class date
{
private:
    int month;
    int year;
    int day;

public:
    date(int y, int m, int d) : year(y), month(m), day(d) {}
    ~date() {}
    void setdata(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void getdate() const
    {
        cout << year << "��" << month << "��" << day << "��" << endl;
    }
};
class Person
{
private:
    string name;
    string sex;
    string id;
    date birth;

public:
    Person(string NAME, string SEX, string ID, int y, int m, int d) : name(NAME), sex(SEX), id(ID), birth(y, m, d)
    {
    }
    void show() const
    {
        cout << "������" << name << endl
             << "�Ա�" << sex << endl
             << "���֤�ţ�" << id << endl;
        birth.getdate();
    }
};

int main()
{
    Person obj("����", "��", "110110200011221111", 2000, 11, 22);
    obj.show();
    system("PAUSE");
    return 0;
}