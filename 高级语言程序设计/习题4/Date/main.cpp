#include "Date.h"
#include <iostream>
using namespace std;
int main()
{
    Date d1;
    std::cout << "��������ʼ���ڣ�YY/MM/DD)��";
    int y, m, d;
    std::cin >> y >> m >> d;
    d1.SetDate(2012, 2, 25);
    int status = 1;
    while (status)
    {
        std::cout << "��������Ҫ���еĲ���" << endl
                  << "1.++  2.-- 3.�˳�" << endl;
        std::cin >> status;
        switch (status)
        {
        case 1:
            d1++;
            cout << d1;
            break;
        case 2:
            d1--;
            cout << d1;
            break;
        default:
            status = 0;
            break;
        }
    }
    return 0;
}