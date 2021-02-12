#include <iostream>
using namespace std;
template <typename T>
T findmax(T *array, int num)
{
    T _max = array[0];
    for (int i = 1; i < num; i++)
    {
        if (array[i] > _max)
            _max = array[i];
    }
    return _max;
}
template <typename T>
T findsum(T *array, int num)
{
    T sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += array[i];
    }
    return sum;
}
int main()
{
    char a[5] = "brrx";
    cout << "a数组最大值为" << findmax(a, 4) << endl;
    cout << "a数组求和为" << static_cast<int>(findsum(a, 4)) << endl; //这有问题 ASCII码的加和会溢出！！！！所以是-66

    int b[10] = {9, 1, 10, 3, 6, 2, 5, 4, 8, 7};
    cout << "b数组最大值为" << findmax(b, 10) << endl;
    cout << "b数组求和为" << findsum(b, 10) << endl;

    double c[5] = {4.3, 3.14, 5.12, 6.5, 0.5};
    cout << "c数组最大值为" << findmax(c, 5) << endl;
    cout << "c数组求和为" << findsum(c, 5) << endl;

    system("PAUSE");
    return 0;
}