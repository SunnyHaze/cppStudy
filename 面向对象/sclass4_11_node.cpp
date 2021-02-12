#include <iostream>
#include "sclass4_11_node.h"

//CNode�Ĺ��캯��
CNode::CNode(string str){
    m_pStr = new string(str);
    if(m_pStr == NULL){
        cout << "�ڴ����ʧ��" << endl;
        exit(0);
    }
    m_nodeNum = GetNumber();
    cout << "CNodeȫ�´����ڵ㣬NO��" << m_nodeNum <<",name:" << *m_pStr << endl; 
}

//CNode �Ŀ������캯��
CNode::CNode(const CNode &oCN){
    m_pStr = new string (*oCN.m_pStr); //�˴��Ѿ�����ַ�����ֵ
    if(m_pStr == NULL){
        cout << "�ڴ����ʧ��" << endl;
        exit(0);
    }
    m_nodeNum = GetNumber();
    cout << "CNode���������ڵ㣬NO��" << m_nodeNum << ",name"; 
}

//CNode ����������
CNode::~CNode(){
    cout << "~CNode��NO��" << m_nodeNum << ",Name:" << *m_pStr << endl;
    delete m_pStr;
}

//����Cnode�ĸ�ֵ�����(����ڵ������ڵ�����ͬ�Ķ������)
CNode& CNode::operator = (const CNode &ocn){
    cout << "CNode No:" << m_nodeNum <<",name" <<*m_pStr << "��Ҫ�����ǡ�"<< endl;
    if(this == &ocn){ //��������Լ���ֵ�ģ���ֱ�ӷ����Լ�������������
        return *this; 
    }
    delete m_pStr;
    m_pStr = new string (*ocn.m_pStr);
    if(m_pStr == NULL){
        cout << "�ڴ����ʧ�ܡ�" << endl;
        exit(0);
    }
    m_nodeNum = ocn.m_nodeNum;
    cout <<"�ýڵ��Ѿ�����Ϊ" << "CNode No:" << m_nodeNum << ",name" << *m_pStr << endl;
    return *this;
}

//����cnode �ġ����������
const CNode &CNode::operator,(const CNode &ocn){
    return ocn;
} 

//����CNode����������
ostream& operator << (ostream& scout,CNode& obj){
    scout << "Node Name:" << *(obj.GetStr() ) << ",";
    scout << "Node Name:" << obj.GetNodeNum() << "." << endl;
    return scout;
}

//����cnode�����������
istream& operator >> (istream& scin,CNode& obj){
    char s[81];
    cout << "please enter node name:";
    scin.getline(s,81,'\n');
    *(obj.GetStr() ) =s;
    cout << "pleas enter your node number:";
    scin >> obj.GetNodeNum();
    return scin;
}

//���ص�ǰSNodeNum����������1
int CNode::GetNumber(void){
    return sNodeNum < LEN ? sNodeNum++ : (sNodeNum = 0);
}

//����ָ��ڵ����ֵ��ַ���ָ��
string *CNode::GetStr(){
    return m_pStr;
}

//���ؽڵ�ı�ţ�Ҳ����m_nodenum
int &CNode::GetNodeNum(void){
    return m_nodeNum;
}

//CNodeArray��Ĺ��캯��
CNodeArray::CNodeArray(int aLength){
    for(int i = 0; i < aLength ; i++){
        m_poCN[i] = NULL;
    }
    m_aLenth = aLength;     //���鳤������
    m_aIndex = 0;           //��ǰ�ڵ��±�����Ϊ0
    cout << "CNodeArray,����һ���ڵ��������lenth=��"<<m_aLenth << endl;
}

//~CNodeArray������������ȷ��m_poCNָ������ָ��Ŀռ��Ƿ�������
CNodeArray::~CNodeArray(void){
    for(int i = 0 ; i < m_aIndex ; i++){
        if(m_poCN[i] != NULL){
            delete m_poCN[i];
            cout << "delete:m_poCN[" << i << "]." << endl;
        }
    }
}
//�򵥵Ĳ��빦�ܣ��������CNodeָ��ָ���½ڵ����
//Ϊ�˰�ȫ���ȶԲ���λ�������жϣ����ԭ���нڵ㣬������ʧ�ܣ����ء�
bool CNodeArray::Insert(CNode &ocn){
    if(m_aIndex >= m_aLenth){
        cout << "�Բ��𣬳�������������±꣬�����ٲ��룡" << endl;
        return false;
    }
    if(m_poCN[m_aIndex] != NULL){
        cout << "�˴��Ѿ����ڽڵ㣬�����ٲ��룡" << endl;
        return false;
    }
    m_poCN[m_aIndex] = &ocn;
    cout<< "�����½ڵ㣬Pos��" << m_aIndex << ",NO:" << ocn.GetNodeNum()
        << ",NAME:" << *ocn.GetStr() << endl;
    m_aIndex++;
    return true; 
}

//���ﲻ������������൱��deleteһ���ڵ㣬��ʹ��ڵ�Ϊ�ռ���
bool CNodeArray::Delete(int index){
    if(m_poCN[index] == NULL){
        cout <<"pos" << index << "=NULL ������� delete�����." << endl;
        return false;
    }
    delete m_poCN[index];
    m_poCN[index] == NULL;
    cout << "delete:m_poCN[" << index <<"], " << "pos" <<index
         << ",��λ��ָ��Ľڵ�delete�ɹ���" << endl;
    return true; 
}

//CNodeArray �� ��[]�� ��������أ����ﷵ����һ�����󣬵�[]������ʱ
//���Թ۲쵽CNode�Ŀ������캯�������������ĵ��ù���
CNode CNodeArray::operator[] (int i){
    if(i <= m_aIndex && i >= 0 ){
        return *m_poCN[i];
    }
    else {
        if(m_poCN[i] == NULL){
            cout << "û��Ԫ�أ�����" << endl;
            exit(0);
        }
        cout << "����Խ��" << endl;
        exit(0);
    }
}

//����CNodeArray��new�����
void *CNodeArray::operator new(size_t size){
    cout << "����CNodeArray�Զ����new��������\n";
    return malloc(size);
}

//����CNodeArray��delete�����
void CNodeArray::operator delete(void *p){
    cout << "����CNodeArray�Զ����delete���ٶ���"<<endl;
    free(p);
}


