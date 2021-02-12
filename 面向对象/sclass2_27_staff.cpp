#include "sclass2_27_staff.h"
int Staff::counter = 1000;
int main(){
    cout << "请输入员工个数: ";
    int n;
    cin >> n;
    while (n <= 0){
        cout << "非法人数！" << endl << "请重新输入人数：";
        cin >> n;
    }
    
    Staff *staff = new Staff[n];
    for(int i = 0 ; i < n ; i++){
        cout << "请输入员工" << staff[i].GetCounter() << "的月薪：";
        double s;
        cin >> s;
        staff[i].SetSalary(s);
    }
    for(int i = 0 ; i < n ; i++){
        cout << "编号" << staff[i].GetNumber() << "的员工的月薪是：" << staff[i].GetSalary() << endl;
    }
    delete [] staff;
    return 0;
}