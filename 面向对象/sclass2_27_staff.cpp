#include "sclass2_27_staff.h"
int Staff::counter = 1000;
int main(){
    cout << "������Ա������: ";
    int n;
    cin >> n;
    while (n <= 0){
        cout << "�Ƿ�������" << endl << "����������������";
        cin >> n;
    }
    
    Staff *staff = new Staff[n];
    for(int i = 0 ; i < n ; i++){
        cout << "������Ա��" << staff[i].GetCounter() << "����н��";
        double s;
        cin >> s;
        staff[i].SetSalary(s);
    }
    for(int i = 0 ; i < n ; i++){
        cout << "���" << staff[i].GetNumber() << "��Ա������н�ǣ�" << staff[i].GetSalary() << endl;
    }
    delete [] staff;
    return 0;
}