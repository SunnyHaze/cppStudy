#include "sclass2_6_date.h"
Date::~Date(){
    cout << "��������" << year << "��" << month << "��" << day << "�ն���" << endl; //�󴴽��Ķ��������� //������������ǰִ�еĺ����������������Ĵ���
}
Date::Date(int y,int m, int d){
    year = y;
    month = m;
    day = d;
}
void Date::SetDate(int y,int m,int d){
    year = y;
    month = m;
    day = d;
}
int Date::IsLeapYear(){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;  
}
void Date::Print(){
    cout << year << "��" << month << "��" << day << "��";
}
