#include "sclass2_6_date.cpp"
#include <iostream>
int main(){
    Date date1;
    if(1){
        Date date3(1999,99,99);//date3���������ڽ�������Date���У�
    }
    Date date2(2020,1,17);
    date2.~Date();
    cout << "hhhh";
    date1.Print();
    cout << endl;
    date2.Print();
    cout << endl;
    
}
