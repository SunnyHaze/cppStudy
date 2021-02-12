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
        void show(int age) const;     //ʵ���˶��ں���show�����أ�
};

//�����Ĺ����ļ���
person::person(int age,string name) : m_age(age),m_name(name){

}

void person::show(int age) const{
    cout << "������" << m_name << "�����䣺" << m_age << endl;
}

void person::show() const{
    cout << "������" << m_name << "�����䣺" << m_age << endl;
}

student::student(int age,string name,string grade) : person(age,name),m_grade(grade){

}

void student::show(int age) const{
    cout << "������" << m_name << ",����:" << m_age << "�ɼ�:" << m_grade << endl;
}

int main(){
    person *pocp;
    student ocs(8,"���ܵ�","Grade two");
    pocp = &ocs;
    ocs.show(1);
    // ocs.show(); 
    //�޷����û����е�ͬ�����س�Ա�����������ڱ����صĳ�Ա������
    pocp->show(1);
    pocp->show(); //���麯������£�����ʵ�ֶ������غ����ĵ��á�����ָ��������صĺ���
    
    return 0;
}