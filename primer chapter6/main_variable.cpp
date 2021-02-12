#include<iostream>
#include<initializer_list>
#include<cstring>
using std::string;
using std::cout;
using std::cin;
using std::endl;
void error_msg(std::initializer_list<string> i1){
    // for(auto beg = i1.begin() ; beg != i1.end() ; ++beg)
    //     cout << *beg << " ";
    // cout << endl;
    for(const auto &elem : i1)
        cout << elem << " ";
    cout << endl;
}
int main(int argc ,char *argv[]){
    string a,b; 
    std::cin >> a >> b;
    if(a != b)
        error_msg({"functionX" , a , b});
    else
        error_msg({"functionX" , "okay"});
}
