#include <iostream>
#include "smain6_1�Խ�����.cpp"
using namespace std;
int main(){
    int a[] = {1,2,3,4,5,6,7};
    int n = 7;
    Link<int> ll;
    for(int i = 0 ; i < n ;i++){
        ll.Append(a[i]);
    }
    LinkIterator<Node<int>> begin(ll.begin());
    LinkIterator<Node<int>> end(ll.end());
    cout << "����Ԫ��";
    show(begin,end);
    return 0;
}