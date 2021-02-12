#include "String.h"
String::String(const char *s)
{
    if (s == nullptr)
        s = "";
    strValue = new char[strlen(s) + 1];
    strcpy(strValue, s);
}
String::String()
{
    strValue = new char[1];
}
String::~String()
{
    delete[] strValue;
}
String::String(const String &obj)
{
    strValue = new char(strlen(obj.strValue) + 1);
    strcpy(strValue, obj.strValue);
}

String &String::operator=(const String &obj)
{
    if (this != &obj)
    {
        strValue = new char[strlen(obj.strValue) + 1];
        strcpy(strValue, obj.strValue);
    }
    return *this;
}

void String::Show() const
{
    std::cout << strValue << std::endl;
}