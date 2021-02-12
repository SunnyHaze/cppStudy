#include "sclass2_20_cstack.h"
void cstack::push_back(int idata){
    cnode *newnode = new cnode(idata,m_ptop);
    m_ptop = newnode;
}
//³öÕ»
int cstack::pop(void){
    cnode * tempnode = m_ptop;
    if(m_ptop){
        m_ptop = m_ptop->m_prenode;
        int tempdata = tempnode->m_idata;
        delete tempnode;
        return tempdata;
    }
    else
    {
        cout << "Õ»ÒÑ¿Õ" << endl;
        return 0;
    }
}