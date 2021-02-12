#pragma once
#include <iostream>
#include <string>
class caller
{
private:
    std::string ID = "¿Õ";
    std::string userName = "Î´ÃüÃû";
    std::string userAddress = "²»Ïê";
    std::string callAddress = "²»Ïê";

public:
    caller();
    ~caller();
    void input();
    void cPolice();
    void cClinic();
    void cRestaurant();
    void printinfo();
};