#include <iostream>
using namespace std;
void Func(char x, char y, char z)
{
    cout << x << " " << y << " " << z << endl;
}
int main()
{
    char a = 'a';
    Func(++a, ++a, ++a);
    system("PAUSE");
    return 0;
}