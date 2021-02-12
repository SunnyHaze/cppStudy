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
        cout << "请输入出版物名称：";
        cin >> title;
        cout << "请输入价格：";
        cin >> price;
    }
    virtual void Show() const
    {
        cout << "图书名：" << title << endl;
        cout << "价格：" << price << endl;
    }
};
class Book : public Publication
{
private:
    int page;

public:
    void GetData()
    {
        cout << "正在创建图书对象" << endl;
        Publication::GetData();
        cout << "请输入页数：";
        cin >> page;
    }
    void Show() const
    {
        cout << endl;
        Publication::Show();
        cout << "页数：" << page << endl;
    }
};
class Tape : public Publication
{
private:
    float playTime;

public:
    void GetData()
    {
        cout << "正在创建磁带对象" << endl;
        Publication::GetData();
        cout << "请输入磁带播放时长";
        cin >> playTime;
    }
    void Show() const
    {
        cout << endl;
        Publication::Show();
        cout << "播放时长为：" << playTime << endl;
    }
};