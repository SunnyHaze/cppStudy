#include <iostream>
#include "date.cpp"
int main(){
    Date dl;
    dl.SetDate(2020,1,15);
    dl.Print();
    std::cout << "������������:" << dl.IsLeapYear() << std::endl;
    return 0;
}
