#include "Athlete.h"
#include <iostream>
#include "Athlete.h"
Athlete::Athlete()
{
    std::cout << "空构造函数调用！"
              << std::endl;
    athName = "无名氏";
    athAge = 18;
    athSex = 'm';
    athSports = "暂无";
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
    std::cout << "姓名:" << athName << std::endl
              << "年龄:" << athAge << std::endl;
    std::cout << "性别:" << (athSex == 'm' ? "男" : "女") << std::endl
              << "体育项目：" << athSports << std::endl
              << std::endl;
}
