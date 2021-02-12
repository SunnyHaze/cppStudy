#include "sclass3_12_ceducation.h"
ceducation::ceducation(char cschool[],char cdegree){
    strcpy(m_cschool,cschool);
    m_cdgree = cdegree;
}
void ceducation::getedu() {
    cout << endl <<"毕业学校:";
    cin >> m_cschool;
    cout << endl << "最高学历:(专科H、本科B、硕研M、博研D)   ";
    cin >> m_cdgree;
    m_cdgree = toupper(m_cdgree); 
}

void ceducation::putedu()const{
    cout << endl << "毕业学校：" << m_cschool;
    cout << endl << "最高学历：";
    switch(m_cdgree){
        case 'H':
            cout << "专科" << endl;
            break;
        case 'B':
            cout << "本科" << endl;
            break;
        case 'M':
            cout << "硕研" << endl;
            break;
        case 'D':
            cout << "博研" << endl;
            break;
        default:
            cout << "空" << endl;
            break;
    }
}

void staff::input(){
    m_istaffnum = ++s_counter;
    cout <<endl<< "请输入编号为" << m_istaffnum << "号员工的姓名：";
    cin >> m_name;
    Edu.getedu();
    cout << "基本工资：";
    cin >> m_basicsal;
    cout << "出勤率:" ;
    cin >> m_rateattend;
    while(m_rateattend > 1.0 || m_rateattend < 0.0){
        cout << "出勤率不合法" << endl << "请重新输入出勤率：";
        cin >> m_rateattend;
    }
    cout << "奖金：";
    cin >> m_prize;
}
void staff::output(){
    cout << endl << "显示员工" << m_name << "的基本数据:";
    cout << endl << "工作编号：" << m_istaffnum;
    Edu.putedu();
    cout << endl << "基本工资：" << m_basicsal;
    cout << endl << "奖金：" << m_prize;
    cout << endl << "出勤率：" << m_rateattend * 100 << "%" << endl; 
}

void adminstaff::calculatesal(){
    cout << "当月实发工资："
    << m_basicsal + m_prize * m_rateattend <<"元" << endl;
}

void cmanager::setMdata(){
    cout << endl << "公司总销售额：";
    cin >> m_fTAmount;
    cout << endl << "提成比例：";
    cin >> m_fDeductRate;
}

void cmanager::calculatesal(){
    cout <<"当月实发工资：";
    cout << m_basicsal + m_fTAmount * m_fDeductRate << "元" << endl;
}

void csaleman::setSdata(){
    cout << endl << "个人销售额：";
    cin >> m_fDeductSRate;
    cout << endl << "提成比例：";
    cin >> m_fPAmount;
}

void csaleman::calculatesal(){
    cout << "当月实发工资：";
    cout << m_basicsal + m_fPAmount * m_fDeductSRate << "元" << endl;
}

void csalesmanager::calculatesal(){
    cout << "当月实发工资：";
    cout << m_basicsal + m_fPAmount * m_fDeductSRate + m_fTAmount * m_fDeductRate << "元" << endl;
}
