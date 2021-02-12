#pragma once
#include <iostream>
#include <cstring>
class String
{
private:
    // ���ݳ�Ա
    char *strValue; // ��ֵ

public:
    // ���г�Ա
    String();
    String(const char *s);                 // ���캯��
    String(const String &copy);            // ���ƹ��캯��
    String &operator=(const String &copy); // ���ظ�ֵ�����
    ~String();                             // ��������
    void Show() const;                     // ��ʾ��
};
