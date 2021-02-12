#pragma once
template <class T>
class Node
{
private:
    Node<T> *next;

public:
    T data;
    explicit Node(const T &item, Node<T> *ptrnext = nullptr);
    void InsertAfter(Node<T> *p); //�ڽڵ�֮���������һ��ͬ��ڵ�P
    Node<T> *DeleteAfter();       //ɾ�����ڵ�ĺ�̽ڵ㣬�����ص�ַ
    Node<T> *NextNode() const;    //��ȡ��һ���ڵ�ĵ�ַ
};

template <class T>
Node<T>::Node(const T &item, Node<T> *ptrnext = nullptr) : data(item), next(ptrnext)
{
}

template <class T>
Node<T> *Node<T>::NextNode() const
{
    return next;
}

template <class T>
void Node<T>::InsertAfter(Node<T> *p)
{
    p->next = next;
    next = p;
}

//ɾ����ǰ�ڵ�ĺ�̽ڵ㣬�����ر�ɾ���ڵ�ĵ�ַ
template <class T>
Node<T> *Node<T>::DeleteAfter()
{
    Node<T> *tempptr = next;
    if (next == nullptr)
        return nullptr;
    next = tempptr->next;
    return tempptr;
}