#include<iostream>
#include<cstring>
#include<vector>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main(){
    vector<int> ivec = {1,2,3,4,5,6,7,8};
    for(auto &i : ivec){
        i *= i;
        cout << i << endl;
    }
    vector<int>::size_type index = 0;
    vector<unsigned> scores(11,0);/*
    unsigned grade;
    while(cin >> grade){
        if(grade <= 100)
            ++scores[grade / 10];
    }
    for(auto i : scores)
        cout << i << " ";
    cout << scores.size() << "!!!";*/
    vector<string> text;
    string temp;
    while (cin >> temp){
        text.push_back(temp);
    }
    for(auto &i : text){
        for(char &c : i){
            c = toupper(c);
        }
    }
    for(auto i : text){
        cout << i << " ";
    }
    
}