#include <iostream>
using namespace std;
class solve
{
private:
    int a, b;
    void check(int a)
    {
        if (a <= 0)
            throw "一个负数，不正确！";
    }

public:
    solve()
    {
        cout << "请输入第一个整数：";
        cin >> a;
        check(a);
        cout << "请输入第二个整数：";
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
        cout << "请输入第一个整数：";
        cin >> a;
        check(a);
        cout << "请输入第二个整数：";
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
                cout << "第" << flag << "个能同时被3、5、7整除的整数为" << i << endl;
            }
        }
        if (!flag)
            cout << "范围内没有这样的整数。";
    }
};
