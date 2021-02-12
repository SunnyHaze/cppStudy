#include <iostream>
#include "date.cpp"
int main(){
    Date dl;
    dl.SetDate(2020,1,15);
    dl.Print();
    std::cout << "此年是闰年吗:" << dl.IsLeapYear() << std::endl;
    return 0;
}
