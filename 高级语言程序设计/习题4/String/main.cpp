#include <iostream>
#include "String.h"
int main()
{
    String s1("我是验证String的字符串常量"), s2, s3(s1);
    s2 = s1;
    s1.Show();
    s2.Show();
    s3.Show();
    system("PAUSE");
    return 0;
}