#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
class Array
{
private:
    T *pos;
    int n;

public:
    Array(int size)
    {
        pos = new T[size];
        if (pos == NULL)
        {
            throw bad_alloc();
        }
        n = size;
    }
    ~Array()
    {
        delete[] pos;
    }
    T &operator[](int loc)
    {
        if (loc > n)
        {
            cout << "索引超过最大值" << endl;
            return pos[0];
        }
        else
        {
            return pos[loc];
        }
    }
};
int main()
{
    Array<int> obj1(5);
    for (int i = 0; i < 5; i++)
        obj1[i] = i + 1;
    for (int i = 0; i < 5; i++)
        cout << obj1[i] << " ";
    cout << endl;

    char source[10] = "Dreams";
    Array<char> obj2(strlen(source));
    for (int i = 0; i < strlen(source); i++)
        obj2[i] = source[i];
    for (int i = 0; i < strlen(source); i++)
        cout << obj2[i];
    cout << endl;

    system("PAUSE");
    return 0;
}