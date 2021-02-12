#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;
int main()
{
    Circle obj1;
    Rectangle obj2;
    Shape *pointer;
    pointer = &obj1;
    pointer->Show();
    cout << endl;
    pointer = &obj2;
    pointer->Show();
    cout << endl;
    system("PAUSE");
    return 0;
}