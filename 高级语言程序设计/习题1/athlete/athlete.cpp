#include "Athlete.h"
#include <iostream>
#include "Athlete.h"
Athlete::Athlete()
{
    std::cout << "�չ��캯�����ã�"
              << std::endl;
    athName = "������";
    athAge = 18;
    athSex = 'm';
    athSports = "����";
}

Athlete::~Athlete()
{
    ;
}

Athlete::Athlete(std::string name, int age, char sex, std::string sports)
{
    athName = name;
    athAge = age;
    athSex = sex;
    athSports = sports;
}

Athlete::Athlete(const Athlete &ath)
{
    athName = ath.athName;
    athAge = ath.athAge;
    athSex = ath.athSex;
    athSports = ath.athSports;
}
void Athlete::PrintAthlete()
{
    std::cout << "����:" << athName << std::endl
              << "����:" << athAge << std::endl;
    std::cout << "�Ա�:" << (athSex == 'm' ? "��" : "Ů") << std::endl
              << "������Ŀ��" << athSports << std::endl
              << std::endl;
}
