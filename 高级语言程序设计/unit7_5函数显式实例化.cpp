#include <iostream>  // ����Ԥ��������
using namespace std; // ʹ�������ռ�std

template <class ElemType>
ElemType Max(const ElemType &x, const ElemType &y) // ��x,y�����ֵ
{
    return x < y ? y : x; // ����x,y�����ֵ
}

int main() // ������main()
{
    cout << "2��3.0�����ֵΪ" << Max(2.0, 3.0) << endl;
    // ��,�޷�����2,3.0ȷ��������ʽ�����ľ�������
    cout << "2��3.0�����ֵΪ" << Max<int>(2, 3.0) << endl;
    // ���2,3.0�����ֵ������ʾʵ����

    system("PAUSE"); // ���ϵͳ��ʾ��Ϣ
    return 0;        // ����ֵ0, ���ز���ϵͳ
}
