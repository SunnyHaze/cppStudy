#include <iostream>  // 编译预处理命令
using namespace std; // 使用命名空间std

template <typename T, typename U>
T Convert(U const &arg)
{
    return static_cast<T>(arg);
}

int main() // 主函数main()
{
    double d = 65.78;
    cout << Convert<int>(d) << endl;  // 显式实例化
    cout << Convert<char>(d) << endl; // 显式实例化

    system("PAUSE"); // 输出系统提示信息
    return 0;        // 返回值0, 返回操作系统
}
