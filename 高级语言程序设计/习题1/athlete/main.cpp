#include <iostream>
#include "athlete.h"
int main()
{
    Athlete ath("ÕÅÈý", 19, 'm', "³ª¡¢Ìø¡¢rap¡¢ÀºÇò");
    Athlete ath2;
    Athlete ath3(ath);
    ath2.PrintAthlete();
    ath3.PrintAthlete();
    ath.PrintAthlete();
    system("PAUSE");
    return 0;
}
