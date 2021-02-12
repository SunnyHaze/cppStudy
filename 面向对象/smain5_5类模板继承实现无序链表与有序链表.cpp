#include <iostream>
#include <string>
using namespace std;
class CNode;

template <class Type>
class TLinkList{
public:
    TLinkList();            //构造函数
    virtual ~TLinkList();   //析构函数

    virtual bool insert(Type value);    //在链表中插入一个节点，表头插入
    bool Delete(Type value);            //从链表中删除值为value的节点
    bool Search(Type value);            //查找链表中是否包含值为value的节点
    bool Modify(Type v1,Type v2);       //查找链表中节点值为v1的节点，并修改为v2
    bool findtail();
    virtual void Print();               //按照链表顺序输出链表中的节点值
public:
    CNode *m_phead;                     //这里保存了链表的头结点指针
};

template <class Type>
class TOrderedLinkList : public TLinkList<Type>{
public:
    TOrderedLinkList();
    virtual ~TOrderedLinkList();

public:
    virtual bool insert(Type value);
    virtual void Print();
};

class CNode{
    friend class TLinkList<int>;
    friend class TOrderedLinkList<int>;

public:
    CNode(int value);
    ~CNode();
private:
    int m_value;
    CNode *m_pnext;
    CNode *m_ppre;
};
CNode::CNode(int value){
    m_value = value;
    m_pnext = NULL;
    m_ppre = NULL;
}
CNode::~CNode(){
    ;
}
//类模板的构造函数
template <class Type>
TLinkList<Type>::TLinkList(){
    m_phead = NULL;
}
//TLinkList类模板的析构函数
template <class Type>
TLinkList<Type>::~TLinkList(){
    CNode *p = m_phead;
    while(p != NULL){
        m_phead = p->m_pnext;
        delete p;
        p = m_phead;
    }
}

//创建一个新节点，并只在头指针后面插入
template<class Type>
bool TLinkList<Type>::insert(Type value){
    CNode *ptemp = new CNode(value);
    if(ptemp == NULL){
        exit(0);
    }
    if(m_phead == NULL){
        ptemp->m_pnext = NULL;
        ptemp->m_ppre = NULL;
        m_phead = ptemp;
    }
    else{
        ptemp->m_pnext = m_phead;
        ptemp->m_ppre = NULL;
        m_phead->m_ppre = ptemp;
        m_phead = ptemp;
    }
    return true;
}
//删除值为value的所有节点
template<class Type>
bool TLinkList<Type>::Delete(Type value){
    int flag = 0;
    CNode *p1 = m_phead,*p2 = m_phead->m_pnext;
    while (p2 != NULL){
        if(p2->m_value == value){
            p1->m_pnext = p2->m_pnext;
            p2->m_pnext->m_ppre = p1;
            delete p2;
            p2 = p1->m_pnext;
            flag++;
        }
        else{
            p1 = p2;
            p2 = p1->m_pnext;
        }
    }
    return flag;
}

//将表中节点值为v1的节点全部修改为v2，修改成功返回true 否则false
template <class Type>
bool TLinkList<Type>::Modify(Type v1,Type v2){
    bool flag = false;
    for(CNode *p = m_phead ; p != NULL ; p = p->m_pnext){
        if(p->m_value == v1){
            p->m_value = v2;
            flag = true;
        }
    }
    return flag;
}

//按照链表顺序从表头开始取出节点值并显示
template <class Type>
void TLinkList<Type>::Print(){
    cout << "从TLinkList表头开始节点的值一次为：\n";
    //遍历链表以读出每个节点的值，并在终端上显示
    for(CNode *p = m_phead ; p != NULL ; p = p->m_pnext){
        cout <<p->m_value<<" ";
    }
    cout << endl;
}
//测试用函数，用于看尾指针是否存在，不存在即进入死循环
template <class Type>
bool TLinkList<Type>::findtail(){
    CNode *p = m_phead;
    while(p != NULL){
        p = p->m_pnext;
    }
    cout << "找到结尾！" << endl;
    return 1;
}

//TOderedLinkList类模板的构造函数。
template <class Type>
TOrderedLinkList<Type>::TOrderedLinkList():TLinkList<Type>(){ //这里调用了原来的构造函数。
    ;
}

//TOderedLinkList类模板的析构函数
template<class Type>
TOrderedLinkList<Type>::~TOrderedLinkList(){
    ;
}

//TOderedLinkList的节点插入方法，有序插入；
template <class Type>
bool TOrderedLinkList<Type>::insert(Type value){
    CNode *p1,*p2;
    CNode *ptemp = new CNode(value);
    if(ptemp==NULL){
        exit(0);
    }
    if(this->m_phead == NULL){
        ptemp->m_pnext = NULL;
        ptemp->m_ppre = NULL;
        this->m_phead = ptemp; //在不断的类模板生成模板要 声明定义域!!!!!!及其重要的一个特征，但是会丢失多态性
    }
    else{
        if(value < this->m_phead->m_value){
            ptemp->m_pnext = this->m_phead;
            ptemp->m_ppre = NULL;
            this->m_phead->m_ppre = ptemp;
            this->m_phead = ptemp;
        }
        else
        {
            //让P2指向p1的前驱（主要考虑链表尾部的插入）
            for(p2 = this->m_phead,p1=this->m_phead->m_pnext;p1!=NULL;p2=p1,p1=p1->m_pnext){
                if(value < p1->m_value){
                    (p1->m_ppre)->m_pnext = ptemp;
                    ptemp->m_ppre = p1->m_ppre;

                    ptemp->m_pnext = p1;
                    p1->m_ppre = ptemp;
                    break;
                }
            }
            if(p1==NULL){
                ptemp->m_pnext=NULL;
                ptemp->m_ppre=p2;
                p2->m_pnext = ptemp;
            }
        }
    }
    return true;
}

//按照链表顺序从表头开始取出节点值并显示
template <class Type>
void TOrderedLinkList<Type>::Print(){
    cout <<"从TOrdererdLinkList表头开始，节点的值依次为:\n";
    //遍历链表以读出每一个节点的值并在终端上显示
    for(CNode *p = this->m_phead ; p!= NULL ;p = p->m_pnext){
        cout << " " << p->m_value <<"";
    }
    cout << endl;
}

//查找链表中是否包含节点值为value的节点，如果有则返回true，没有则返回false
template <class Type>
bool TLinkList<Type>::Search(Type value){
    for(CNode *p = m_phead ; p!= NULL; p = p->m_pnext){
        if(p->m_value = value){
            return true;
        }
    }
    return false;
}

int main(){
    TLinkList<int> l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.insert(7);
    l.insert(8);
    l.Print();
    l.Delete(4);
    l.Print();
    cin.get();
}