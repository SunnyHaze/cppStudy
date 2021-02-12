#include "Vehicle.h"
#include <iostream>
using namespace std;
int main()
{
    Vehicle Aodi(4, 1000);
    Aodi.Show();
    cout << '\n';
    Car Baoma(4, 1000, 5);
    Baoma.Show();
    cout << '\n';
    Truck Dongfeng(4, 20000, 2, 50000);
    Dongfeng.Show();
    system("PAUSE");
    return 0;
}