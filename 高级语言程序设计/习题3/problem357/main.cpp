#include "problem357.h"
int main()
{
    try
    {
        solve obj;
        obj.result();
        system("PAUSE");
        return 0;
    }
    catch (const char *mess)
    {
        std::cout << mess << endl;
    }
}