#pragma once
#include <iostream>
#include <cstring>
class real //实数
{
public:
    bool positive = 1;        //用于判断正数还是负数
    bool point = 1;           //是否有小数点
    std::string decimal = ""; //小数点部分
    std::string value = "";   //用于存储整数部分

    std::string splus(std::string a, std::string b, int &jinwei);
    // std::string sminus(std::string a, std::string b, int &tuiwei);

public:
    real()
    {
        decimal = "0";
        point = 0;
        positive = 1;
        value = "0";
    }
    explicit real(const char *);
    ~real()
    {
        ;
    }
    void clear(){
        decimal = "";
        point = 0;
        positive = 0;
        value = "";
    }
    bool operator>(real obj);
    bool operator<(real obj);
    real operator+(real obj);
    real operator*(real obj);
    real operator=(real obj);
    real operator=(const char *indata);
    friend std::istream &operator>>(std::istream &is, const real &item);
    friend std::ostream &operator<<(std::ostream &os, const real &item);
};