#include <iostream>
using namespace std;
template <typename T>
void outputArray(const T * array,const int count){
    for(int i = 0 ; i != count ;i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
int main(){
    double a[] = {1.1,2.2,3.3,4.4,5.5};
    int b[] = {1,2,3,4,5};
    char c[] = {'a','b','c','d'};
    outputArray(a,5);
    outputArray(b,5);
    outputArray(c,4);
    return 0;
}