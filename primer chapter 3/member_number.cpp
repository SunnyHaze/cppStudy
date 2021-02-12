#include<iostream>
#include<cstring>
#include<vector>
#include<cctype>
#include<iterator>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main(){
    string str("01234567");
    const string hexdigits = "0123456789ABCDEF";
    string result;
    string::size_type n;
    string::iterator it;
    it = str.begin();
    string::iterator end = str.end();
    auto mid = it + (end - it) / 2 ;
    cout << *it << " " << *--end << " " << *mid << endl;
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    int *p1 = a + 4;
    int *p2 = a + 4;
    cout << p1 << endl;
    p1 += p1 - p2;
    cout << p1;
    vector<int> ivec(std::begin(a) + 1, std::end(a) - 1);
    for(auto i : ivec){
        cout << i << " ";
    }
/*    while(cin >> n){]
        if(n < hexdigits.size() )
            result += hexdigits[n];
    }
    cout << result;
*/}