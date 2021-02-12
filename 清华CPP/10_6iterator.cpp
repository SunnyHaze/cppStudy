#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    const int N = sizeof(A) / sizeof(int);
    vector<int> col1(A, A + N);

    ostream_iterator<int> output(cout, " ");

    cout << "List col1 contains:";
    copy(col1.begin(), col1.end(), output);

    vector<int>::iterator pos = col1.begin();
    cout << "\nThe first element is:" << *pos;

    vector<int>::reverse_iterator rpos = col1.rbegin();
    cout << "\nThe last element is:" << *rpos << endl;

    back_insert_iterator<vector<int>> iter(col1);
    *iter = 77;
    back_inserter(col1) = 99;
    *iter = 88;
    for (int i = 1; i < 10; i++)
    {
        back_inserter(col1) = i;
    }
    copy(col1.begin(), col1.end(), output);
    cout << endl;
}