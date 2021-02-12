#pragma once
#include <iostream>
#include <cstdlib>
#include "9_5Node.h"

template <class T>
class LinkList
{
    private:
        Node<T> *front,*tail;       //��ͷ�ͱ�βָ��
        Node<T> *PrePtr,*currPtr;   //��¼����ǰ����λ�õ�ָ�룬�ɲ����ɾ����Ŷ������
        int size;
        int position;           //��ǰԪ���ڱ��е�λ����ţ��ɺ���Resetʹ�á�
        //�����½ڵ㣬������Ϊ item��ָ����Ϊ ptrnext��
        Node<T>* GetNode(const T& item, Node<T> * ptrNext = nullptr);
        void CopyList(const LinkList<T> &L);

    public:
        LinkList(void);
        LinkList(const LinkList<T> &L);
        ~LinkList(void);
        LinkList<T> & operator = (const LinkList<T> &L);
        int ListSize() const;   //����������Ԫ�ظ���
        int ListEmpty() const;  //�ж������Ƿ�Ϊ��
        void Reset(int pos = 0);
        void Next(void);         //��preptr��currptr�ƶ�����һ���ڵ�
        int EndOfList(void) const;
        int CurrentPosition(void) const;    //�������ݳ�Աposition
        void InsertFront(const T &item);    //ͷ������
        void Inserttail(const T &item);     //β������
        void InsertAt(const T &item);       //�ڵ�ǰ�ڵ�֮ǰ����ڵ�
        void InsertAfter(const T &item);    //�ڵ�ǰ�ڵ�֮�����ڵ�

        T DeleteFront(void);                //ɾ��ͷ���
        void DeleteAt(void);                //ɾ����ǰ�ڵ�
        T &Data(void);                      //���ض��ڵ�ǰ�ڵ��Աdata������
        void ClearList(void);               //��������ͷ����нڵ���ڴ�ռ䣬��������������operator = ����
    };