#pragma once
#include <iostream>
#include <cstring>
class String
{
private:
    // 数据成员
    char *strValue; // 串值

public:
    // 公有成员
    String();
    String(const char *s);                 // 构造函数
    String(const String &copy);            // 复制构造函数
    String &operator=(const String &copy); // 重载赋值运算符
    ~String();                             // 析构函数
    void Show() const;                     // 显示串
};
