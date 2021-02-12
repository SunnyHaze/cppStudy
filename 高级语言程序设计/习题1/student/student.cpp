#include "student.h"
#include <iostream>
#include "student.h"
Student::Student()
{
    std::cout << "空构造函数调用！"
              << std::endl;
    stuName = "无名氏";
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
    std::cout << "姓名:" << stuName << std::endl
              << "年龄:" << stuAge << std::endl;
    std::cout << "性别:" << (stuSex == 'm' ? "boy" : "girl") << std::endl
              << "学号：" << stuNumber << std::endl
              << std::endl;
}
