#include <iostream> // ����Ԥ��������
#include <fstream>
using namespace std; // ʹ�������ռ�std
int main()           // ������main()
{
    char ch;
    int letters = 0;
    fstream f;
    f.open("my_file.txt", ios::in);
    if (f.fail())
    {
        cout << "���ļ�ʧ��" << endl;
        exit(1);
    }
    char x;
    cout << "�ļ�����Ϊ:" << endl;
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
    //     cout << "��ʧ�ܣ�" << endl;
    //     exit(2);
    // }
    // ch = infile.get();
    // while (!infile.eof())
    // {
    //     if (ch >= 'A' && ch <= 'Z')
    //         letters++;
    //     ch = infile.get();
    // }
    cout << "���д�дӢ����ĸ" << letters << "��!" << endl;
    // infile.close();
}