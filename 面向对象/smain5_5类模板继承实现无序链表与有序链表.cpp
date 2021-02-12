#include <iostream>
#include <string>
using namespace std;
class CNode;

template <class Type>
class TLinkList{
public:
    TLinkList();            //���캯��
    virtual ~TLinkList();   //��������

    virtual bool insert(Type value);    //�������в���һ���ڵ㣬��ͷ����
    bool Delete(Type value);            //��������ɾ��ֵΪvalue�Ľڵ�
    bool Search(Type value);            //�����������Ƿ����ֵΪvalue�Ľڵ�
    bool Modify(Type v1,Type v2);       //���������нڵ�ֵΪv1�Ľڵ㣬���޸�Ϊv2
    bool findtail();
    virtual void Print();               //��������˳����������еĽڵ�ֵ
public:
    CNode *m_phead;                     //���ﱣ���������ͷ���ָ��
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
//��ģ��Ĺ��캯��
template <class Type>
TLinkList<Type>::TLinkList(){
    m_phead = NULL;
}
//TLinkList��ģ�����������
template <class Type>
TLinkList<Type>::~TLinkList(){
    CNode *p = m_phead;
    while(p != NULL){
        m_phead = p->m_pnext;
        delete p;
        p = m_phead;
    }
}

//����һ���½ڵ㣬��ֻ��ͷָ��������
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
//ɾ��ֵΪvalue�����нڵ�
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

//�����нڵ�ֵΪv1�Ľڵ�ȫ���޸�Ϊv2���޸ĳɹ�����true ����false
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

//��������˳��ӱ�ͷ��ʼȡ���ڵ�ֵ����ʾ
template <class Type>
void TLinkList<Type>::Print(){
    cout << "��TLinkList��ͷ��ʼ�ڵ��ֵһ��Ϊ��\n";
    //���������Զ���ÿ���ڵ��ֵ�������ն�����ʾ
    for(CNode *p = m_phead ; p != NULL ; p = p->m_pnext){
        cout <<p->m_value<<" ";
    }
    cout << endl;
}
//�����ú��������ڿ�βָ���Ƿ���ڣ������ڼ�������ѭ��
template <class Type>
bool TLinkList<Type>::findtail(){
    CNode *p = m_phead;
    while(p != NULL){
        p = p->m_pnext;
    }
    cout << "�ҵ���β��" << endl;
    return 1;
}

//TOderedLinkList��ģ��Ĺ��캯����
template <class Type>
TOrderedLinkList<Type>::TOrderedLinkList():TLinkList<Type>(){ //���������ԭ���Ĺ��캯����
    ;
}

//TOderedLinkList��ģ�����������
template<class Type>
TOrderedLinkList<Type>::~TOrderedLinkList(){
    ;
}

//TOderedLinkList�Ľڵ���뷽����������룻
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
        this->m_phead = ptemp; //�ڲ��ϵ���ģ������ģ��Ҫ ����������!!!!!!������Ҫ��һ�����������ǻᶪʧ��̬��
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
            //��P2ָ��p1��ǰ������Ҫ��������β���Ĳ��룩
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

//��������˳��ӱ�ͷ��ʼȡ���ڵ�ֵ����ʾ
template <class Type>
void TOrderedLinkList<Type>::Print(){
    cout <<"��TOrdererdLinkList��ͷ��ʼ���ڵ��ֵ����Ϊ:\n";
    //���������Զ���ÿһ���ڵ��ֵ�����ն�����ʾ
    for(CNode *p = this->m_phead ; p!= NULL ;p = p->m_pnext){
        cout << " " << p->m_value <<"";
    }
    cout << endl;
}

//�����������Ƿ�����ڵ�ֵΪvalue�Ľڵ㣬������򷵻�true��û���򷵻�false
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