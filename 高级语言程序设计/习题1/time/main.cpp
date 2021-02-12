#include "time.h"
#include <iostream>
int main()
{
    Time clock1;
    clock1.PrintTime();
    Time clock2(23, 1, 34);
    clock2.PrintTime();
    system("PAUSE");
    return 0;
}