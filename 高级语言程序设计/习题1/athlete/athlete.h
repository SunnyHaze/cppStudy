#pragma once
#include <string>
class Athlete
{
private:
    std::string athName;
    int athAge;
    char athSex;
    std::string athSports;

public: 
    Athlete();
    ~Athlete();
    Athlete(std::string name, int age, char sex, std::string sports);
    Athlete(const Athlete &ath);
    void PrintAthlete();
};
