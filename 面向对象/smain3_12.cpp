#include "sclass3_12_ceducation.cpp"

int main(){
    char flag = 'Y';
    while (toupper(flag) == 'Y')
    {
        cout << "��ѡ��¼�����1.���� 2.����Ա 3.���۾��� 4.������Ա����";
        int n;
        cin >> n;
        switch(n){
            case 1:
            {
                cmanager staff;
                staff.input();
                staff.setMdata();
                staff.output();
                staff.calculatesal();
                break;
            }
            case 2:
            {
                csaleman staff;
                staff.input();
                staff.setSdata();
                staff.output();
                staff.calculatesal();
                break;
            }
            case 3:
            {
                csalesmanager staff;
                staff.input();
                staff.setMdata();
                staff.setSdata();
                staff.output();
                staff.calculatesal();
                break;
            }
            case 4:
            {
                adminstaff staff;
                staff.input();
                staff.output();
                staff.calculatesal();
                break;
            }
           
            default:{
                cout << "ѡ������" << endl;
                break;
            }
            
        }
        cout << "�Ƿ����¼����Ϣ��Y/N��";
        cin >> flag;
    }
    return 0;
    
}