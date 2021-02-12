#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
    vector<int> A(10);
    int n;
    int primecount = 0, i, j;
    cout << "Enter a value >= 2 as upper limit for prime numbers:";
    cin >> n;
    A[primecount++] = 2;
    for(int i = 3 ; i < n ; i += 2)
    {
        if(primecount == A.size() )
            A.resize(primecount + 10);
        j = 3;
        while(j <= i/2 && i % j != 0)
            j += 2;
        
        if(j > i / 2)
            A[primecount++] = i;
    }
    for(i = 0 ; i < primecount; i++){
        cout << A[i] << "\t";
        if((i+1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}