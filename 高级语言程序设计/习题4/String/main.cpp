#include <iostream>
#include "String.h"
int main()
{
    String s1("������֤String���ַ�������"), s2, s3(s1);
    s2 = s1;
    s1.Show();
    s2.Show();
    s3.Show();
    system("PAUSE");
    return 0;
}