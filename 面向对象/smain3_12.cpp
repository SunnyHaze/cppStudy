#include "sclass3_12_ceducation.cpp"

int main(){
    char flag = 'Y';
    while (toupper(flag) == 'Y')
    {
        cout << "请选择录入类别（1.经理 2.销售员 3.销售经理 4.行政人员）：";
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
                cout << "选择有误" << endl;
                break;
            }
            
        }
        cout << "是否继续录入信息（Y/N）";
        cin >> flag;
    }
    return 0;
    
}