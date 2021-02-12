//����������ģ��
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

    void Append(const Type &e){ //��ĩβ׷��Ԫ��
        if(size < maxsize){
            elem[size++] = e;
        }
        else{   //������������������
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

//����������ģ��
    //����ڵ���ģ��
template <class Type>
struct Node
{
    Type data;
    Node<Type> *next;
};
    //�ٶ���������������ģ��
template <class Type>
class Link
{
private:
    Node<Type> *head;
    Node<Type> *tail;
    Node<Type> *prev; //��βǰ����ʵ��ָ�����һ��Ԫ�ء�

public:
    Link(){
        head = prev = tail = NULL;
    }
    virtual ~Link(){
        while (head->next!=NULL)
        {
            Node<Type> *p = head->next;
            head->next = p->next;
            delete p; //�����ͷ�p��ָ�Ĵ洢�ռ�
        }
    }
    //��ĩβ׷��һ��Ԫ��
    void Append(const Type &e){
        Node<Type> *p =new Node<Type>;
        p->data = e;
        p->next = NULL;

        if(head == NULL){       //�������ʼ��
            head = prev = p;
            tail = p->next;     //tail������prev�ĺ�̵��Ǳ�����NULL
        }
        else{                   //�ǿ�����
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


//��д������ʾ����ģ��

template <class It>
void show(It begin,It end){
    for(It it = begin;it != end;it++){
        cout << *it << " ";
    }
    cout << endl;
}

//�������������ģ��

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
    
        void operator ++ (int) //���غ�׺++ �����
        {
            itptr++;
        }
        T operator * (){
            return *itptr;
        }
};

//�������������ģ��
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

