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
    const string hexdigits = "0123456789ABCDEF";
    string result;
    string::size_type n;
    while(cin >> n){
        if(n < hexdigits.size() )
            result += hexdigits[n];
    }
    cout << result;
}