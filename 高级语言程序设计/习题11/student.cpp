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
    cout << "��ӭʹ�ñ�ϵͳ����ѡ�����¹��ܣ�\n1.��������Ϣ��stu.dat����\n2.��ʾ��ǰstu.dat��������Ϣ\n";
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
                cout << "���ļ�ʧ�ܣ�" << endl;
                exit(1);
            }
            cout << "������ѧ����";
            int n;
            cin >> n;
            student stu[n];
            f << n << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << "�������" << i << "��ѧ����������";
                cin >> stu[i - 1].name;
                f << stu[i - 1].name << " ";
                cout << "�������" << i << "��ѧ���ĳɼ���";
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
                cout << "���ļ�ʧ�ܣ�" << endl;
                exit(1);
            }
            string str;
            getline(f, str);
            int n = str[0] - '0';
            for (int i = 0; i < n; i++)
            {
                getline(f, str);
                cout << "��ţ�" << (i + 1) << "\t������" << str;
                getline(f, str);
                cout << "\t�ɼ���" << str << endl;
            }
            f.close();
            break;
        }
        }
        cout << "\n1.��������Ϣ��stu.dat����\n2.��ʾ��ǰstu.dat��������Ϣ\n0.�˳�����\n";
        cin >> location;
    }
}