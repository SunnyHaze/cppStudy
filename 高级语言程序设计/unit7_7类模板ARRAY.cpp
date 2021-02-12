#include <iostream>
using namespace std;
// 声明类模板MyArray
template <typename T, int size>
class MyArray
{
private:
    // 私有成员:
    T *element; // 用于指向存储数据的存储空间
    //	T element[size];		// 用于存储数据的存储空间
public:
    // 公有成员:
    MyArray();                               // 默认构造函数模板
    MyArray(const T &v);                     // 构造函数模板
    MyArray(const MyArray &copy);            // 复制构造函数模板
    virtual ~MyArray() { delete[] element; } // 析构函数模板
    T &operator[](int index);                // []重载：输出元素值
};
// 默认构造函数模板
template <typename T, int size>
MyArray<T, size>::MyArray()
{
    element = new T[size]; // 分配存储空间
    if (element == NULL)
    { // 发现异常，并抛出
        throw bad_alloc("存储溢出");
    }
}

// 构造函数模板
template <typename T, int size>
MyArray<T, size>::MyArray(const T &v)
{
    element = new T[size]; // 分配存储空间
    if (element == NULL)
    { // 发现异常，并抛出
        throw bad_alloc();
    }
    for (int i = 0; i < size; i++)
    {
        element[i] = v; // 元素初始化为v
    }
}
template <typename T, int size>
MyArray<T, size>::MyArray(const MyArray &copy)
{
    element = new T[size]; // 分配存储空间
    if (element == NULL)
    { // 发现异常，并抛出
        throw bad_alloc();
    }
    for (int i = 0; i < size; i++)
    {
        element[i] = copy.element[i];
        // 元素初始化为copy.element[i]
    }
}

// []重载：给出元素值
template <typename T, int size>
T &MyArray<T, size>::operator[](int index)
{
    if (index < 0 || index >= size)
    { // 发现异常，并抛出
        throw out_of_range("数组越界!");
    }
    return element[index]; // 返回element[index]
}
int main() // 主函数main()
{
    try
    {
        MyArray<int, 6> iObj(0); // 定义类属类（即模板类）对象
        for (int i = 0; i < 6; i++)
            iObj[i] = i * 3;
        MyArray<int, 6> myobj(iObj);
        for (int j = 0; j < 6; j++)
        {
            cout << "myobj[" << j << "] = " << myobj[j] << endl;
        }
        for (int j = 0; j < 6; j++)
            cout << "iObj[" << j << "] = " << iObj[j] << endl;
        cout << myobj[6];
    }
    catch (const out_of_range &excp)
    {
        cout << excp.what() << endl;
        return -1;
    }
    catch (const bad_alloc &excp)
    {
        cout << excp.what() << endl;
        return -2;
    }

    system("PAUSE"); // 调用库函数system( )，输出系统提示信息
    return 0;
}