#include "solve.h"
int main()
{
    try
    {
        std::cout << "������һԪ���η��̵�ϵ����\n"
                  << "������ϵ����";
        int a, b, c;
        std::cin >> a;
        std::cout << "һ����ϵ����";
        std::cin >> b;
        std::cout << "�����";
        std::cin >> c;
        solve obj1(a, b, c);
        obj1.solute();
    }
    catch (const char *mess)
    {
        std::cout << mess << std::endl;
    }
    system("PAUSE");
    return 0;
}