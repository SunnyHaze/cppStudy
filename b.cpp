#include <iostream>
int main()
{
void ChangeFunction(int* input, int n);
void PrintData(int* input, int n);
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
PrintData(a, 10);
ChangeFunction(a, 10);
PrintData(a, 10);
return 0;
}
