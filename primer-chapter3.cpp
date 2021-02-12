#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
void cctype(string x){
    for(auto c : x)
        if(isdigit(c))
        cout << c << endl;
}
void daxiezhuanhuan(string x){
    for(auto &c : x)
        c = toupper(c);
    cout << x << endl;
}

int main(){
    int n=9;
    //cin >> n;
    string s1="!!!";
    string s2(s1);      //复刻s1为副本
    string s3 = s1;     
    string s4("value"); //初始化为副本
    string s5 = "value";//初始化为副本
    string s6(n,'c');   //初始化为n个c的字符串
 //   cout<<s1<<s2<<s3<<s4<<s5<<s6;
    string line={"NI1 shi2 shabi3!"};
    /*
    while (getline(cin,line))
    {
        cout<<line.size()<<endl;
    }
    return 0;
    */
 
   cctype(line);
   daxiezhuanhuan(line);
}


