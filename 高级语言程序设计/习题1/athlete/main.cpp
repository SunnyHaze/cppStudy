#include <iostream>
#include "athlete.h"
int main()
{
    Athlete ath("����", 19, 'm', "��������rap������");
    Athlete ath2;
    Athlete ath3(ath);
    ath2.PrintAthlete();
    ath3.PrintAthlete();
    ath.PrintAthlete();
    system("PAUSE");
    return 0;
}
