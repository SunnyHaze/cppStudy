#include <iostream>
using namespace std;
// ������ģ��MyArray
template <typename T, int size>
class MyArray
{
private:
    // ˽�г�Ա:
    T *element; // ����ָ��洢���ݵĴ洢�ռ�
    //	T element[size];		// ���ڴ洢���ݵĴ洢�ռ�
public:
    // ���г�Ա:
    MyArray();                               // Ĭ�Ϲ��캯��ģ��
    MyArray(const T &v);                     // ���캯��ģ��
    MyArray(const MyArray &copy);            // ���ƹ��캯��ģ��
    virtual ~MyArray() { delete[] element; } // ��������ģ��
    T &operator[](int index);                // []���أ����Ԫ��ֵ
};
// Ĭ�Ϲ��캯��ģ��
template <typename T, int size>
MyArray<T, size>::MyArray()
{
    element = new T[size]; // ����洢�ռ�
    if (element == NULL)
    { // �����쳣�����׳�
        throw bad_alloc("�洢���");
    }
}

// ���캯��ģ��
template <typename T, int size>
MyArray<T, size>::MyArray(const T &v)
{
    element = new T[size]; // ����洢�ռ�
    if (element == NULL)
    { // �����쳣�����׳�
        throw bad_alloc();
    }
    for (int i = 0; i < size; i++)
    {
        element[i] = v; // Ԫ�س�ʼ��Ϊv
    }
}
template <typename T, int size>
MyArray<T, size>::MyArray(const MyArray &copy)
{
    element = new T[size]; // ����洢�ռ�
    if (element == NULL)
    { // �����쳣�����׳�
        throw bad_alloc();
    }
    for (int i = 0; i < size; i++)
    {
        element[i] = copy.element[i];
        // Ԫ�س�ʼ��Ϊcopy.element[i]
    }
}

// []���أ�����Ԫ��ֵ
template <typename T, int size>
T &MyArray<T, size>::operator[](int index)
{
    if (index < 0 || index >= size)
    { // �����쳣�����׳�
        throw out_of_range("����Խ��!");
    }
    return element[index]; // ����element[index]
}
int main() // ������main()
{
    try
    {
        MyArray<int, 6> iObj(0); // ���������ࣨ��ģ���ࣩ����
        for (int i = 0; i < 6; i++)
            iObj[i] = i * 3;
        MyArray<int, 6> myobj(iObj);
        for (int j = 0; j < 6; j++)
        {
            cout << "myobj[" << j << "] = " << myobj[j] << endl;
        }
        for (int j = 0; j < 6; j++)
            cout << "iObj[" << j << "] = " << iObj[j] << endl;
        cout << myobj[6];
    }
    catch (const out_of_range &excp)
    {
        cout << excp.what() << endl;
        return -1;
    }
    catch (const bad_alloc &excp)
    {
        cout << excp.what() << endl;
        return -2;
    }

    system("PAUSE"); // ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
    return 0;
}