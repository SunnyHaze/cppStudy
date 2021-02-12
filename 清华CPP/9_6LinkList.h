#pragma once
#include <iostream>
#include <cstdlib>
#include "9_5Node.h"

template <class T>
class LinkList
{
    private:
        Node<T> *front,*tail;       //表头和表尾指针
        Node<T> *PrePtr,*currPtr;   //记录表单当前遍历位置的指针，由插入和删除错哦做更新
        int size;
        int position;           //当前元素在表中的位置序号，由函数Reset使用。
        //生成新节点，数据域为 item，指针域为 ptrnext；
        Node<T>* GetNode(const T& item, Node<T> * ptrNext = nullptr);
        void CopyList(const LinkList<T> &L);

    public:
        LinkList(void);
        LinkList(const LinkList<T> &L);
        ~LinkList(void);
        LinkList<T> & operator = (const LinkList<T> &L);
        int ListSize() const;   //返回链表中元素个数
        int ListEmpty() const;  //判定链表是否为空
        void Reset(int pos = 0);
        void Next(void);         //将preptr和currptr移动到下一个节点
        int EndOfList(void) const;
        int CurrentPosition(void) const;    //返回数据成员position
        void InsertFront(const T &item);    //头结点插入
        void Inserttail(const T &item);     //尾结点插入
        void InsertAt(const T &item);       //在当前节点之前插入节点
        void InsertAfter(const T &item);    //在当前节点之后插入节点

        T DeleteFront(void);                //删除头结点
        void DeleteAt(void);                //删除当前节点
        T &Data(void);                      //返回对于当前节点成员data的引用
        void ClearList(void);               //清空链表，释放所有节点的内存空间，并被析构函数、operator = 调用
    };