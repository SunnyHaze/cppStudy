#include "student.h"
#include <iostream>
#include "student.h"
Student::Student()
{
    std::cout << "�չ��캯�����ã�"
              << std::endl;
    stuName = "������";
    stuAge = 18;
    stuSex = 'm';
    stuNumber = "201900000000";
}

Student::~Student()
{
    ;
}

Student::Student(std::string name, int age, char sex, std::string number)
{
    stuName = name;
    stuAge = age;
    stuSex = sex;
    stuNumber = number;
}

Student::Student(const Student &stu)
{
    stuName = stu.stuName;
    stuAge = stu.stuAge;
    stuSex = stu.stuSex;
    stuNumber = stu.stuNumber;
}
void Student::PrintStudent()
{
    std::cout << "����:" << stuName << std::endl
              << "����:" << stuAge << std::endl;
    std::cout << "�Ա�:" << (stuSex == 'm' ? "boy" : "girl") << std::endl
              << "ѧ�ţ�" << stuNumber << std::endl
              << std::endl;
}
