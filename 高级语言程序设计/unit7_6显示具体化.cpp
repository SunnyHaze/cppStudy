#include <iostream>
using namespace std;
// ��������ģ��
template <typename T, typename U>
T Convert(U const &arg)
{
    return static_cast<T>(arg);
}

// ��ʽ���廯��ע��const��ʹ��
template <> // ��Щ��������֧��ʹ��template<>ǰ׺��������ʱ����  ����Ŀǰ����Ҫ������������������������
            // �����廯���ָ���������Ϣʱ�����Խ���ǰ׺ע�͵���
char Convert<char>(double const &arg)
{
    return static_cast<char>(arg);
}

int main() // ������main()
{
    double d = 65.78;
    cout << Convert<char>(d) << endl; // ��ʽ���廯

    system("PAUSE"); // ���ϵͳ��ʾ��Ϣ
    return 0;        // ���ز���ϵͳ
}
