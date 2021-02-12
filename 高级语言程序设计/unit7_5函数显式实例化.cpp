#include <iostream>  // 编译预处理命令
using namespace std; // 使用命名空间std

template <class ElemType>
ElemType Max(const ElemType &x, const ElemType &y) // 求x,y的最大值
{
    return x < y ? y : x; // 返回x,y的最大值
}

int main() // 主函数main()
{
    cout << "2和3.0的最大值为" << Max(2.0, 3.0) << endl;
    // 错,无法根据2,3.0确定类型形式参数的具体类型
    cout << "2和3.0的最大值为" << Max<int>(2, 3.0) << endl;
    // 输出2,3.0的最大值——显示实例化

    system("PAUSE"); // 输出系统提示信息
    return 0;        // 返回值0, 返回操作系统
}
