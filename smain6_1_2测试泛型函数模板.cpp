#include <iostream>
#include "smain6_1�Խ�����.cpp"
using namespace std;

int main(){

    int a[] = {1,2,3,4,5,6};
    int n = 6;
    Array<int> arr;
    for(int i = 0 ; i < n ; i++){
        arr.Append(a[i]);
    }
    Array<int> dick;
    for(int i = 0 ; i < 100 ; i++){
        dick.Append(i);
    }
    show(dick.begin(),dick.end() );
    ArrayIterator<int> begin(arr.begin() );
    ArrayIterator<int> end(arr.end() );
    cout << "����Ԫ�أ�";
    show(begin,end);

    return 0;    
}