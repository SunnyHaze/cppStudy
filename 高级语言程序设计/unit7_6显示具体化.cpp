#include <iostream>
using namespace std;
// 声明函数模板
template <typename T, typename U>
T Convert(U const &arg)
{
    return static_cast<T>(arg);
}

// 显式具体化，注意const的使用
template <> // 有些编译器不支持使用template<>前缀。当编译时对这  这行目前必须要！！！！！！！！！！！！
            // 个具体化部分给出出错信息时，可以将该前缀注释掉。
char Convert<char>(double const &arg)
{
    return static_cast<char>(arg);
}

int main() // 主函数main()
{
    double d = 65.78;
    cout << Convert<char>(d) << endl; // 显式具体化

    system("PAUSE"); // 输出系统提示信息
    return 0;        // 返回操作系统
}
