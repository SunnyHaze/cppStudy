#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int mult(int x, int y) { return x * y; }

class multclass
{
public:
    int operator()(int x, int y) const { return x * y; }
};

int main()
{
    int A[] = {1, 4, 3, 2, 5};
    const int N = sizeof(A) / sizeof(int);
    vector<int> col1(A, A + N);
    cout << "The result by muiltipling all elements in A is "
         << accumulate(A, A + N, 1, mult)
         << accumulate(A, A + N, 0, minus<int>() )
         << endl;
    int *b = A;
    cout << *b << *b++ << *b << ++*b << *b;
}