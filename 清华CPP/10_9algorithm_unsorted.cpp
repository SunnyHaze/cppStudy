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

    //�ҳ�ivector������Ԫ��ֵ��ȵĵ�һ��Ԫ�ء�
    cout << *adjacent_find(ivector.begin(), ivector.end()) << endl;

    //�ҳ�ivector������Ԫ��ֵΪ6��Ԫ�ظ�����
    cout << count(ivector.begin(), ivector.end(), 6) << endl;

    //�ҳ�ivector��С��7��Ԫ�ظ���
    cout << count_if(ivector.begin(), ivector.end(), bind2nd(less<int>(), 7)) << endl;

    //�ҳ�ivector��Ԫ��ֵΪ4�ĵ�һ��Ԫ������λ�õ�Ԫ��
    cout << *find(ivector.begin(), ivector.end(), 4) << endl;

    //�ҳ�ivector�д���2�ĵ�һ��Ԫ������λ�õ�Ԫ��
    cout << *find_if(ivector.begin(), ivector.end(), bind2nd(greater<int>(), 2)) << endl;

    //�ҳ�ivector�������� ivector1�����ֵ����һ��λ�ã�����������λ�õ�Ԫ��
    cout << *(find_end(ivector.begin(), ivector.end(), ivector1.begin(), ivector1.end()) + 3) << endl;

    //������ivector2��ivector�г��ֵ����λ��Ԫ��
    cout << *search(ivector.begin(),ivector.end(),ivector2.begin(),ivector2.end()) << endl;
    //������������3��6�����λ��Ԫ��
    cout << *search_n(ivector.begin(), ivector.end(), 3, 6, equal_to<int>()) << endl;
    //�ж���������ivector �� ivector3
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << accumulate(ivector.begin(),ivector.end(),0);
    cout << endl;

    return 0;
}