#include <iostream>
using namespace std;
int &check(int n)
{
    int temp = n;
    int &ref = temp;
    return ref;
}
void skip()
{
    const double &d = 4.2;
}
void snop()
{
    int i = 3;
    int &ri = i;
}
int main()
{
    int n;
    cin >> n;
    while (n)
    {
        int &result = check(n);
        skip();
        //snop();
        cout << result << endl;
        cin >> n;
    }
    system("PAUSE");
    return 0;
}
//��������һ�����÷��غ����ڵľֲ����������ã�ʵ���Ͽ�����һ���������õĵ�ַ�����ڴ洢�Ǹ��ֲ������ĵ�ַ������û���ٴ��������ø���
//����ñ����Ѿ������٣�Ҳ����ͨ����������ĵ�ַ�������ʸñ�����ֵ������ı��Ǹ��ڴ��ַ��
//�������֮���ٴ������������������ö�����ᷢ�����ǣ����·����Ǹ���ַ���᷵����д���ֵ��