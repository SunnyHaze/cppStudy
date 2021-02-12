#include "combine.cpp"
int main()
{
    item dick1(1);
    item dick2(100);
    dick1 = dick1 + dick2;
    cout << dick1.getnum();
}