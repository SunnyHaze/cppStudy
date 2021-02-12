#include <iostream> // 编译预处理命令
#include <fstream>
using namespace std; // 使用命名空间std
int main()           // 主函数main()
{
    char ch;
    int letters = 0;
    fstream f;
    f.open("my_file.txt", ios::in);
    if (f.fail())
    {
        cout << "打开文件失败" << endl;
        exit(1);
    }
    char x;
    cout << "文件内容为:" << endl;
    while (!f.eof())
    {
        f >> x;
        cout << x;
        if (x >= 'A' && x <= 'Z')
            letters++;
    }
    cout << endl
         << "------------------" << endl;
    f.close();
    // ifstream infile("my_file.txt");
    // if (infile.fail())
    // {
    //     cout << "打开失败！" << endl;
    //     exit(2);
    // }
    // ch = infile.get();
    // while (!infile.eof())
    // {
    //     if (ch >= 'A' && ch <= 'Z')
    //         letters++;
    //     ch = infile.get();
    // }
    cout << "共有大写英文字母" << letters << "个!" << endl;
    // infile.close();
}