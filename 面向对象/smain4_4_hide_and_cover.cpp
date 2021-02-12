#include <iostream>
#include <string>

using namespace std;
class person{
    public:
        person(int age,string name);
        virtual void show(int age) const;
        virtual void show() const;
    protected:
        int m_age;
        string m_name;
};

class student : public person{
    protected:
        string m_grade;
    public:
        student(int age,string name,string grade);
        void show(int age) const;     //实现了对于含参show的重载；
};

//函数的构造文件：
person::person(int age,string name) : m_age(age),m_name(name){

}

void person::show(int age) const{
    cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
}

void person::show() const{
    cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
}

student::student(int age,string name,string grade) : person(age,name),m_grade(grade){

}

void student::show(int age) const{
    cout << "姓名：" << m_name << ",年龄:" << m_age << "成绩:" << m_grade << endl;
}

int main(){
    person *pocp;
    student ocs(8,"臭弟弟","Grade two");
    pocp = &ocs;
    ocs.show(1);
    // ocs.show(); 
    //无法调用基类中的同名重载成员函数，这属于被隐藏的成员函数。
    pocp->show(1);
    pocp->show(); //在虚函数情况下，可以实现对于重载函数的调用。利用指针调用隐藏的函数
    
    return 0;
}