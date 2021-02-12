#include<iostream>
#include<cstring>
#include<vector>
#include<cctype>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main(){
    string str("some !!!thing !!!");
    decltype(str.size() ) punct_cnt = 0;
    for(char &c : str) //这里是引用，实际只是调用一下；
        if(!ispunct(c) )
            cout << c;
    cout << str[2] << endl;
    for(decltype(str.size() ) index = 0 ; index != str.size() && !isspace(str[index]) ; ++index)
        str[index] = toupper(str[index]);
    cout << str;
}