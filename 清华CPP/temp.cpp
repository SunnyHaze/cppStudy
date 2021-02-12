#include <iostream>
using namespace std;
float C(int m,int n){
    float value = 1;
    for(int i = 1; i <= m ; i++){
        value *= n - i + 1;
        value /= i;
    }
    return value;
}
int main(){
    int n;
    cout << C(2,3) << endl;
    return 0;
}