#include "Publication.h"
#include <iostream>
using namespace std;
int main()
{
    Book Science;
    Science.GetData();
    Tape machel;
    machel.GetData();
    cout << endl;
    Science.Show();
    machel.Show();
    system("PAUSE");
    return 0;
}