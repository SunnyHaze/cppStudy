#include <iostream>
#include "student.h"
int main()
{
    Student stu("ÕÅÈı", 19, 'm', "2019141460009");
    Student stu2;
    Student stu3(stu);
    stu2.PrintStudent();
    stu3.PrintStudent();
    stu.PrintStudent();
    system("PAUSE");
    return 0;
}
