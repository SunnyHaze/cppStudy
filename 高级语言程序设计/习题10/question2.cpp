#include <iostream>
using namespace std;
int &check(int n)
{
    int temp = n;
    int &ref = temp;
    return ref;
}
void skip()
{
    const double &d = 4.2;
}
void snop()
{
    int i = 3;
    int &ri = i;
}
int main()
{
    int n;
    cin >> n;
    while (n)
    {
        int &result = check(n);
        skip();
        //snop();
        cout << result << endl;
        cin >> n;
    }
    system("PAUSE");
    return 0;
}
//正常创建一个引用返回函数内的局部变量的引用，实际上开辟了一个关于引用的地址，用于存储那个局部变量的地址，若是没有再次生成引用覆盖
//即便该变量已经被销毁，也可以通过引用所存的地址正常访问该变量的值，不会改变那个内存地址。
//但如果在之后再次在其他函数生成引用对象，则会发生覆盖，重新访问那个地址，会返回新写入的值。