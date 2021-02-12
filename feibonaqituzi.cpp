#include<iostream>
#include<math.h>
using namespace std;
int rabbit(int n){
    if( n == 1 || n == 2)
        return 1;
    else 
        return rabbit(n - 1) + rabbit(n - 2);
}
int main(){
    double n ;
    double a[20],b[20];
    for(int i = 0 ; i != 21 ; i++)
        a[i] = (( pow(( (1.0 + sqrt(5 )) ) / 2 , i + 1) - pow(( (1 - sqrt(5) ) / 2 ) , i + 1) ) / sqrt(5) );
    for(auto &j : a){
        printf("%lf ",j);
    }
    cout << endl;
    for(int i = 0 ; i != 20 ; i++){
        b[i] = rabbit(i + 1);
        cout << b[i] <<" ";
    }
}