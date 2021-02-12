#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
    int A[] = {1, 4, 3, 2, 5};
    const int N = sizeof(A) / sizeof(int);
    vector<int> col1(A, A + N);
    ostream_iterator<int> output(cout, " ");
    cout << "Vector co1 contains£º";
    copy(col1.begin(), col1.end(), output);
    sort(col1.begin(), col1.end());
    cout << "\nAfter sorted in ascending order col1 cotains:";
    copy(col1.begin(), col1.end(), output);

    sort(col1.begin(), col1.end(), greater<int>());
    cout << "\nAfter sorted in descending ordercol1 contains:";
    copy(col1.begin(), col1.end(), output);

    cout << endl;
}