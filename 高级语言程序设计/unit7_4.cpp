#include <iostream>  // ����Ԥ��������
using namespace std; // ʹ�������ռ�std

template <typename T, typename U>
T Convert(U const &arg)
{
    return static_cast<T>(arg);
}

int main() // ������main()
{
    double d = 65.78;
    cout << Convert<int>(d) << endl;  // ��ʽʵ����
    cout << Convert<char>(d) << endl; // ��ʽʵ����

    system("PAUSE"); // ���ϵͳ��ʾ��Ϣ
    return 0;        // ����ֵ0, ���ز���ϵͳ
}
