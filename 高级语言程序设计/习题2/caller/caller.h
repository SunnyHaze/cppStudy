#pragma once
#include <iostream>
#include <string>
class caller
{
private:
    std::string ID = "��";
    std::string userName = "δ����";
    std::string userAddress = "����";
    std::string callAddress = "����";

public:
    caller();
    ~caller();
    void input();
    void cPolice();
    void cClinic();
    void cRestaurant();
    void printinfo();
};