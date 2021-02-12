#include <iostream>
using namespace std;
int main(){
    int arr[10000];
    char ch;
    int i = 0;
    while ((ch = cin.get() ) != '\n')
    {
        cin.unget();
        cin >> arr [i];
        i++;
    }
    for(int i = 0 ; i < 10 ; i++){
        cout <<arr[i]<< endl;
    }
    
}