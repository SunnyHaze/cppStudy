#include <iostream>
#ifndef _CNODE_H_
#define _CNODE_H_
using namespace std;

//class cstack;
//�ڵ㴦ֻ�洢�� ���� �� ��һ�ڵ��ַ
class cnode{
    public:
        cnode(int idata,cnode *pre){
            m_idata = idata;
            m_prenode = pre;
        }
        friend class cstack;
    private:
        int m_idata;
        cnode *m_prenode;
};
#endif