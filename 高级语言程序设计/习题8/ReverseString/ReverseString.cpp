#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
void ReverseShowString(char s[])
{
    size_t len = strlen(s);
    stack<char> temp;
    for (int i = 0; i < len; i++)
    {
        temp.push(s[i]);
    }
    for (int i = 0; i < len; i++)
    {
        cout << temp.top();
        temp.pop();
    }
    cout << endl;
}

int main()
{
    char a[50];
    string temp;
    cout << "请输入将要被翻转的字符串：\n";
    getline(cin, temp);
    strcpy(a, temp.c_str());
    ReverseShowString(a);

    system("PAUSE");
    return 0;
}