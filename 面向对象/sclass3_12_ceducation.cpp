#include "sclass3_12_ceducation.h"
ceducation::ceducation(char cschool[],char cdegree){
    strcpy(m_cschool,cschool);
    m_cdgree = cdegree;
}
void ceducation::getedu() {
    cout << endl <<"��ҵѧУ:";
    cin >> m_cschool;
    cout << endl << "���ѧ��:(ר��H������B��˶��M������D)   ";
    cin >> m_cdgree;
    m_cdgree = toupper(m_cdgree); 
}

void ceducation::putedu()const{
    cout << endl << "��ҵѧУ��" << m_cschool;
    cout << endl << "���ѧ����";
    switch(m_cdgree){
        case 'H':
            cout << "ר��" << endl;
            break;
        case 'B':
            cout << "����" << endl;
            break;
        case 'M':
            cout << "˶��" << endl;
            break;
        case 'D':
            cout << "����" << endl;
            break;
        default:
            cout << "��" << endl;
            break;
    }
}

void staff::input(){
    m_istaffnum = ++s_counter;
    cout <<endl<< "��������Ϊ" << m_istaffnum << "��Ա����������";
    cin >> m_name;
    Edu.getedu();
    cout << "�������ʣ�";
    cin >> m_basicsal;
    cout << "������:" ;
    cin >> m_rateattend;
    while(m_rateattend > 1.0 || m_rateattend < 0.0){
        cout << "�����ʲ��Ϸ�" << endl << "��������������ʣ�";
        cin >> m_rateattend;
    }
    cout << "����";
    cin >> m_prize;
}
void staff::output(){
    cout << endl << "��ʾԱ��" << m_name << "�Ļ�������:";
    cout << endl << "������ţ�" << m_istaffnum;
    Edu.putedu();
    cout << endl << "�������ʣ�" << m_basicsal;
    cout << endl << "����" << m_prize;
    cout << endl << "�����ʣ�" << m_rateattend * 100 << "%" << endl; 
}

void adminstaff::calculatesal(){
    cout << "����ʵ�����ʣ�"
    << m_basicsal + m_prize * m_rateattend <<"Ԫ" << endl;
}

void cmanager::setMdata(){
    cout << endl << "��˾�����۶";
    cin >> m_fTAmount;
    cout << endl << "��ɱ�����";
    cin >> m_fDeductRate;
}

void cmanager::calculatesal(){
    cout <<"����ʵ�����ʣ�";
    cout << m_basicsal + m_fTAmount * m_fDeductRate << "Ԫ" << endl;
}

void csaleman::setSdata(){
    cout << endl << "�������۶";
    cin >> m_fDeductSRate;
    cout << endl << "��ɱ�����";
    cin >> m_fPAmount;
}

void csaleman::calculatesal(){
    cout << "����ʵ�����ʣ�";
    cout << m_basicsal + m_fPAmount * m_fDeductSRate << "Ԫ" << endl;
}

void csalesmanager::calculatesal(){
    cout << "����ʵ�����ʣ�";
    cout << m_basicsal + m_fPAmount * m_fDeductSRate + m_fTAmount * m_fDeductRate << "Ԫ" << endl;
}
