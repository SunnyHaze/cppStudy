#pragma once
#include <string>
class Student
{
private:
    std::string stuName;
    int stuAge;
    char stuSex;
    std::string stuNumber;

public:
    Student();
    ~Student();
    Student(std::string name, int age, char sex, std::string number);
    Student(const Student &stu);
    void PrintStudent();
};
