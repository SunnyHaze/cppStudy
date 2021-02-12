#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct student
{
    string name;
    int grade;
} stu;

int main()
{
    cout << "欢迎使用本系统，请选择如下功能：\n1.输入新信息到stu.dat当中\n2.显示当前stu.dat中已有信息\n";
    int location;
    cin >> location;
    string file = "stu.dat";
    while (location)
    {
        fstream f;
        switch (location)
        {
        case 1:
        {
            f.open("../"+file   , ios::out);
            f.close();
            f.open("../"+file, ios::in | ios::out);
            if (f.fail())
            {
                cout << "打开文件失败！" << endl;
                exit(1);
            }
            cout << "请输入学生数";
            int n;
            cin >> n;
            student stu[n];
            f << n << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << "请输入第" << i << "个学生的姓名：";
                cin >> stu[i - 1].name;
                f << stu[i - 1].name << " ";
                cout << "请输入第" << i << "个学生的成绩：";
                cin >> stu[i - 1].grade;
                f << stu[i - 1].grade << " ";
            }
            f.close();
            break;
        }
        case 2:
        {
            f.open("../"+file, ios::out | ios::app);
            f.close();
            f.open("../"+file, ios::in);
            if (f.fail())
            {
                cout << "打开文件失败！" << endl;
                exit(1);
            }
            string str;
            getline(f, str);
            int n = str[0] - '0';
            for (int i = 0; i < n; i++)
            {
                getline(f, str);
                cout << "序号：" << (i + 1) << "\t姓名：" << str;
                getline(f, str);
                cout << "\t成绩：" << str << endl;
            }
            f.close();
            break;
        }
        }
        cout << "\n1.输入新信息到stu.dat当中\n2.显示当前stu.dat中已有信息\n0.退出程序\n";
        cin >> location;
    }
}