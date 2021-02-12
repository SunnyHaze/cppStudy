#ifndef _SCLASS4_11_NODE_H_
#define _SCLASS4_11_NODE_H_

#include <iostream>
#include <string>
using namespace std;

const int LEN = 20;
class CNodeArray;

class CNode{
    friend CNodeArray; //因为要先求取友元，所以在前方直接声明了 指针数组。
    friend ostream& operator << (ostream& cout,CNode& obj);
    friend istream& operator >> (istream& cin ,CNode& obj);
    static int sNodeNum;

public:
    CNode(string str);                          //构造函数
    CNode(const CNode &oCN);                    //拷贝函数
    virtual ~CNode();                           //析构函数
    CNode &operator = (const CNode &oCN);       //重载赋值运算符
    const CNode &operator , (const CNode &oCN); //重载逗号运算符
    int GetNumber(void);                        //返回当前sNodeNum，并且自增1；
    string *GetStr();                           //返回指向节点名字的字符串指针
    int &GetNodeNum();                          //返回节点的编号
private:
    string *m_pStr;
    int m_nodeNum;
};
//**********************************************
//声明节点数组类，它用于管理众多节点，它的数据成员和函数成员设计主要基于方便管理
// 众多节点的需要，为了操作简单，在本例中设计了一个长度为LEN的指针数组，数据的每一个成员都可以指向
// 一个CNode节点对象，当系统生成一个节点以后，就根据m_aIndex确定节点在数组中的位置，当节点销毁后，也不考虑收回
// 与其对应的元素指针以作他用，练习时，应从以下几个角度拓展：
// 1、考虑回收节点删除后的指针以作后用。
// 2、考虑设计一个比较小的数组（如长度为26），然后按照节点名字的首字母不同对应存放在不同的数组指针位置，名字首字母相同的节点按照链表方式
// 存放在其后。
// 3、其他功能的拓展，本程序的设计目的主要在于方便观察程序的执行过程。
//*******************************************************
class CNodeArray{
    friend CNode;
public:
    CNodeArray(int alenth = LEN);       //构造函数，默认数组长度为LEN个
    virtual ~CNodeArray(void);          //虚析构函数
    CNode operator [] (int i);          //重载 “【】”
    void* operator new (size_t size);   //重载 new
    void operator delete(void *p);      //重载delete
    bool Insert(CNode &obj);            //在数组中插入一个节点
    bool Delete(int index);             //在数组中删除一个节点
private:
    CNode *m_poCN[LEN];
    int m_aLenth;
    int m_aIndex;
};
#endif