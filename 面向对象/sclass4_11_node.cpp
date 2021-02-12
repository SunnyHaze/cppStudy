#include <iostream>
#include "sclass4_11_node.h"

//CNode的构造函数
CNode::CNode(string str){
    m_pStr = new string(str);
    if(m_pStr == NULL){
        cout << "内存分配失败" << endl;
        exit(0);
    }
    m_nodeNum = GetNumber();
    cout << "CNode全新创建节点，NO：" << m_nodeNum <<",name:" << *m_pStr << endl; 
}

//CNode 的拷贝构造函数
CNode::CNode(const CNode &oCN){
    m_pStr = new string (*oCN.m_pStr); //此处已经达成字符串赋值
    if(m_pStr == NULL){
        cout << "内存分配失败" << endl;
        exit(0);
    }
    m_nodeNum = GetNumber();
    cout << "CNode拷贝创建节点，NO：" << m_nodeNum << ",name"; 
}

//CNode 的析构函数
CNode::~CNode(){
    cout << "~CNode，NO：" << m_nodeNum << ",Name:" << *m_pStr << endl;
    delete m_pStr;
}

//重载Cnode的赋值运算符(允许节点名，节点编号相同的对象存在)
CNode& CNode::operator = (const CNode &ocn){
    cout << "CNode No:" << m_nodeNum <<",name" <<*m_pStr << "将要被覆盖。"<< endl;
    if(this == &ocn){ //如果对于自己赋值的，就直接返回自己，结束函数。
        return *this; 
    }
    delete m_pStr;
    m_pStr = new string (*ocn.m_pStr);
    if(m_pStr == NULL){
        cout << "内存分配失败。" << endl;
        exit(0);
    }
    m_nodeNum = ocn.m_nodeNum;
    cout <<"该节点已经覆盖为" << "CNode No:" << m_nodeNum << ",name" << *m_pStr << endl;
    return *this;
}

//重载cnode 的“，”运算符
const CNode &CNode::operator,(const CNode &ocn){
    return ocn;
} 

//重载CNode的输出运算符
ostream& operator << (ostream& scout,CNode& obj){
    scout << "Node Name:" << *(obj.GetStr() ) << ",";
    scout << "Node Name:" << obj.GetNodeNum() << "." << endl;
    return scout;
}

//重载cnode的输入运算符
istream& operator >> (istream& scin,CNode& obj){
    char s[81];
    cout << "please enter node name:";
    scin.getline(s,81,'\n');
    *(obj.GetStr() ) =s;
    cout << "pleas enter your node number:";
    scin >> obj.GetNodeNum();
    return scin;
}

//返回当前SNodeNum，并且自增1
int CNode::GetNumber(void){
    return sNodeNum < LEN ? sNodeNum++ : (sNodeNum = 0);
}

//返回指向节点名字的字符串指针
string *CNode::GetStr(){
    return m_pStr;
}

//返回节点的编号，也就是m_nodenum
int &CNode::GetNodeNum(void){
    return m_nodeNum;
}

//CNodeArray类的构造函数
CNodeArray::CNodeArray(int aLength){
    for(int i = 0; i < aLength ; i++){
        m_poCN[i] = NULL;
    }
    m_aLenth = aLength;     //数组长度设置
    m_aIndex = 0;           //当前节点下标设置为0
    cout << "CNodeArray,创建一个节点数组对象，lenth=："<<m_aLenth << endl;
}

//~CNodeArray的析构函数，确认m_poCN指向对象的指针的空间是否析构了
CNodeArray::~CNodeArray(void){
    for(int i = 0 ; i < m_aIndex ; i++){
        if(m_poCN[i] != NULL){
            delete m_poCN[i];
            cout << "delete:m_poCN[" << i << "]." << endl;
        }
    }
}
//简单的插入功能，将数组的CNode指针指向新节点而已
//为了安全，先对插入位置做好判断，如果原来有节点，报插入失败，返回。
bool CNodeArray::Insert(CNode &ocn){
    if(m_aIndex >= m_aLenth){
        cout << "对不起，超过了数组最大下标，不可再插入！" << endl;
        return false;
    }
    if(m_poCN[m_aIndex] != NULL){
        cout << "此处已经存在节点，不可再插入！" << endl;
        return false;
    }
    m_poCN[m_aIndex] = &ocn;
    cout<< "插入新节点，Pos：" << m_aIndex << ",NO:" << ocn.GetNodeNum()
        << ",NAME:" << *ocn.GetStr() << endl;
    m_aIndex++;
    return true; 
}

//这里不是链表操作，相当于delete一个节点，并使其节点为空即可
bool CNodeArray::Delete(int index){
    if(m_poCN[index] == NULL){
        cout <<"pos" << index << "=NULL 无需调用 delete运算符." << endl;
        return false;
    }
    delete m_poCN[index];
    m_poCN[index] == NULL;
    cout << "delete:m_poCN[" << index <<"], " << "pos" <<index
         << ",此位置指向的节点delete成功！" << endl;
    return true; 
}

//CNodeArray 的 “[]” 运算符重载，这里返回了一个对象，当[]被调用时
//可以观察到CNode的拷贝构造函数和析构函数的调用过程
CNode CNodeArray::operator[] (int i){
    if(i <= m_aIndex && i >= 0 ){
        return *m_poCN[i];
    }
    else {
        if(m_poCN[i] == NULL){
            cout << "没有元素，出错。" << endl;
            exit(0);
        }
        cout << "数组越界" << endl;
        exit(0);
    }
}

//重载CNodeArray的new运算符
void *CNodeArray::operator new(size_t size){
    cout << "调用CNodeArray自定义的new创建对象。\n";
    return malloc(size);
}

//重载CNodeArray的delete运算符
void CNodeArray::operator delete(void *p){
    cout << "调用CNodeArray自定义的delete销毁对象。"<<endl;
    free(p);
}


