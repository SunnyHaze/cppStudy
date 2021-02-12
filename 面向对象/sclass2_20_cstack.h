#ifndef _STACK_
#define _STACK_
#include "sclass2_20_cnode.h"
class cstack{
    public:
        cstack(void){
            m_ptop = 0;
        }
        void push_back(int idata);
        int pop(void);
    private:
        cnode *m_ptop; //我是头指针,栈顶指针
};
#endif