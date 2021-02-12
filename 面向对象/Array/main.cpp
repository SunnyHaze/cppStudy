#include <iostream>
#include "Array.h"
int main()
{
    Array<int> a(10);
    for(int i = 0 ; i < 10 ; i++){
        a[i] = i + 1;
    }
    for(int i = 0 ; i < 15 ; i++){
        std:: cout << a[i] << std::endl;
    }
    return 0;
}