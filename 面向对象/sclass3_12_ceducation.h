#ifndef _SCLASS_3_12CEDUCATION_H_
#define _SCLASS_3_12CEDUCATION_H_

#include <iostream>
#include <cstring>
using namespace std;
const int LEN =50;

class ceducation{
    public:
        ceducation(){}
        ceducation(char cschool[],char cdegree);
        void getedu() ;
        void putedu() const;
    private:
        char m_cschool[LEN];
        char m_cdgree;
};

class staff{
    protected:
        ceducation Edu; //��������Ϊ�Ӷ���
        int m_istaffnum;
        char m_name[LEN];
        float m_rateattend; //������
        float m_basicsal;   //��������
        float m_prize;      //����
        static int s_counter;   //��ż�����
    public:
        staff(void){};
        ~staff(void){};
        void calculatesal(void);
        void output(void);
        void input(void);
};

class adminstaff : public staff{
    public:
        adminstaff(){};
        ~adminstaff(){};
        void calculatesal(void);
};

class cmanager : virtual public staff{
    public:
        cmanager(){};
        void setMdata(void);
        void calculatesal(void);
    protected:
        float m_fDeductRate;
        float m_fTAmount; //totalAmount;
};

class csaleman : virtual public staff{
    public:
        csaleman(){};
        void setSdata();
        void calculatesal();
    protected:
        float m_fDeductSRate;
        float m_fPAmount;   //personAmount
};
class csalesmanager : public csaleman , public cmanager{
    public:
        csalesmanager(){};
        void calculatesal();
};
int staff::s_counter = 1000;
#endif