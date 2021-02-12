#pragma once
#include <iostream>
#include <string>
using namespace std;
class Publication
{
private:
    string title;
    float price;

public:
    virtual void GetData()
    {
        cout << "��������������ƣ�";
        cin >> title;
        cout << "������۸�";
        cin >> price;
    }
    virtual void Show() const
    {
        cout << "ͼ������" << title << endl;
        cout << "�۸�" << price << endl;
    }
};
class Book : public Publication
{
private:
    int page;

public:
    void GetData()
    {
        cout << "���ڴ���ͼ�����" << endl;
        Publication::GetData();
        cout << "������ҳ����";
        cin >> page;
    }
    void Show() const
    {
        cout << endl;
        Publication::Show();
        cout << "ҳ����" << page << endl;
    }
};
class Tape : public Publication
{
private:
    float playTime;

public:
    void GetData()
    {
        cout << "���ڴ����Ŵ�����" << endl;
        Publication::GetData();
        cout << "������Ŵ�����ʱ��";
        cin >> playTime;
    }
    void Show() const
    {
        cout << endl;
        Publication::Show();
        cout << "����ʱ��Ϊ��" << playTime << endl;
    }
};