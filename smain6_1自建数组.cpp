//定义数组类模板
#include <iostream>
using namespace std;


template <class Type>
class Array
{
private:
    Type *elem;
    int maxsize;
    int size;

public:
    Array(int sz = 3):maxsize(sz),size(0){
        elem = new Type[maxsize];
    }

    virtual ~Array(){
        delete []elem;
    }

    void Append(const Type &e){ //向末尾追加元素
        if(size < maxsize){
            elem[size++] = e;
        }
        else{   //数组已满，必须扩容
            Type *tmpelem = new Type[maxsize *= 2];
            for(int i = 0 ; i < size; i++){
                tmpelem[i] = elem[i];
            }
            delete elem;
            elem = tmpelem;
            elem[size++] = e;
        }
    }

    Type* begin(){
        return elem;
    }

    Type* end(){
        return elem + size;
    }
};

//定义链表类模板
    //定义节点类模板
template <class Type>
struct Node
{
    Type data;
    Node<Type> *next;
};
    //再定义真正的链表类模板
template <class Type>
class Link
{
private:
    Node<Type> *head;
    Node<Type> *tail;
    Node<Type> *prev; //表尾前驱，实际指向最后一个元素。

public:
    Link(){
        head = prev = tail = NULL;
    }
    virtual ~Link(){
        while (head->next!=NULL)
        {
            Node<Type> *p = head->next;
            head->next = p->next;
            delete p; //不断释放p所指的存储空间
        }
    }
    //向末尾追加一个元素
    void Append(const Type &e){
        Node<Type> *p =new Node<Type>;
        p->data = e;
        p->next = NULL;

        if(head == NULL){       //空链表初始化
            head = prev = p;
            tail = p->next;     //tail本身是prev的后继但是本身是NULL
        }
        else{                   //非空链表
            prev->next = p;
            prev = p;
            tail = p->next;
        }
    }
    Node<Type> *begin(){
        return head;
    }

    Node<Type> *end(){
        return tail;
    }
};


//编写泛型显示函数模板

template <class It>
void show(It begin,It end){
    for(It it = begin;it != end;it++){
        cout << *it << " ";
    }
    cout << endl;
}

//定义数组迭代器模板

template <class T>
class ArrayIterator
{
    private:
        T *itptr;
    
    public:
        ArrayIterator(T *p) : itptr(p){ };
        bool operator != (const ArrayIterator &it) const {
            return this->itptr != it.itptr;
        }
    
        void operator ++ (int) //重载后缀++ 运算符
        {
            itptr++;
        }
        T operator * (){
            return *itptr;
        }
};

//定义链表迭代器模板
template <class T>
class LinkIterator{
    private:
        T *itptr;
    public:
        LinkIterator(T *p) : itptr(p){}
        bool operator != (const LinkIterator &it) const{
            return this->itptr != it.itptr;                                                                                                                                 
        }
        void operator ++ (int){
            itptr = itptr->next;
        }
        T operator *(){
            return *itptr;
        }
};

template <class T>
ostream &operator << (ostream &out ,const Node<T> &nd){
    out << nd.data;
    return out;
}                                

