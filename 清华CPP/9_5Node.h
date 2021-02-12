#pragma once
template <class T>
class Node
{
private:
    Node<T> *next;

public:
    T data;
    explicit Node(const T &item, Node<T> *ptrnext = nullptr);
    void InsertAfter(Node<T> *p); //在节点之后插入另外一个同类节点P
    Node<T> *DeleteAfter();       //删除本节点的后继节点，并返回地址
    Node<T> *NextNode() const;    //获取下一个节点的地址
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

//删除当前节点的后继节点，并返回被删除节点的地址
template <class T>
Node<T> *Node<T>::DeleteAfter()
{
    Node<T> *tempptr = next;
    if (next == nullptr)
        return nullptr;
    next = tempptr->next;
    return tempptr;
}