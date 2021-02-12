#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(){
    deque<double> value;
    deque<double> member;
    value.push_front(2.2);
    value.push_front(3.5);
    value.push_back(1.1);
    cout << "value contains:";
    for(int i = 0 ; i < value.size() ; i++){
        cout << value[i] << ' ';
    }
    value.pop_front();
    cout << "after pop front value contains";
    copy(value.begin(),value.end(),member.begin());

    value[1] = 5.4;

    for(auto i : member)
        cout << i;

    cout << "\nAfter pop_fornt values contains:";
    copy(value.begin(),value.end(),member);

    for(auto i : member)
        cout << i;
        
    cout << endl;
    return 0;
}