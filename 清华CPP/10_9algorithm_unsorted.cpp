#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9};
    vector<int> ivector(array, array + sizeof(array) / sizeof(int));
    int array1[] = {6, 6};
    vector<int> ivector1(array1, array1 + sizeof(array1) / sizeof(int));
    int array2[] = {5, 6};
    vector<int> ivector2(array2, array2 + sizeof(array2) / sizeof(int));
    int array3[] = {0, 1, 2, 3, 4, 5, 7, 7, 7, 9, 7};
    vector<int> ivector3(array3, array3 + sizeof(array3) / sizeof(int));

    //找出ivector中相邻元素值相等的第一个元素。
    cout << *adjacent_find(ivector.begin(), ivector.end()) << endl;

    //找出ivector中相邻元素值为6的元素个数；
    cout << count(ivector.begin(), ivector.end(), 6) << endl;

    //找出ivector中小于7的元素个数
    cout << count_if(ivector.begin(), ivector.end(), bind2nd(less<int>(), 7)) << endl;

    //找出ivector中元素值为4的第一个元素所在位置的元素
    cout << *find(ivector.begin(), ivector.end(), 4) << endl;

    //找出ivector中大于2的第一个元素所在位置的元素
    cout << *find_if(ivector.begin(), ivector.end(), bind2nd(greater<int>(), 2)) << endl;

    //找出ivector中子序列 ivector1所出现的最后一个位置，再往后三个位置的元素
    cout << *(find_end(ivector.begin(), ivector.end(), ivector1.begin(), ivector1.end()) + 3) << endl;

    //子序列ivector2在ivector中出现的起点位置元素
    cout << *search(ivector.begin(),ivector.end(),ivector2.begin(),ivector2.end()) << endl;
    //查找连续出现3个6的起点位置元素
    cout << *search_n(ivector.begin(), ivector.end(), 3, 6, equal_to<int>()) << endl;
    //判断两个区间ivector 和 ivector3
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << accumulate(ivector.begin(),ivector.end(),0);
    cout << endl;

    return 0;
}