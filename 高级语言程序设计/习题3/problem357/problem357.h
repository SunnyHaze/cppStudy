#include <iostream>
using namespace std;
class solve
{
private:
    int a, b;
    void check(int a)
    {
        if (a <= 0)
            throw "һ������������ȷ��";
    }

public:
    solve()
    {
        cout << "�������һ��������";
        cin >> a;
        check(a);
        cout << "������ڶ���������";
        cin >> b;
        check(b);
    }
    solve(int x, int y) : a(x), b(y)
    {
        ;
    }
    ~solve()
    {
        ;
    }
    void input()
    {
        cout << "�������һ��������";
        cin >> a;
        check(a);
        cout << "������ڶ���������";
        cin >> b;
        check(b);
    }
    void result()
    {
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int flag = 0;
        for (int i = a; i <= b; i++)
        {
            if (i % 105 == 0)
            {
                flag++;
                cout << "��" << flag << "����ͬʱ��3��5��7����������Ϊ" << i << endl;
            }
        }
        if (!flag)
            cout << "��Χ��û��������������";
    }
};
