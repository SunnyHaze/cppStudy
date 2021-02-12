#include<iostream>
#include <stdlib.h>
#include <time.h>
// ����������ɽ��������ı�������
using namespace std;
int main(){
    srand((unsigned)time(NULL)); //��ʼ��ʱ������
    int times = 10;
    int n;
    cin >> n;
    while(times--){
        int sum = 0;
        bool doors[3];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 3 ; j++)
                doors[j] = 0;
            int car = rand() % 3;
            doors[car] = 1;
            int people = rand() % 3;
            int host = rand() % 3;
            while(host == car || host == people)
                host = rand() % 3;
            for(int j = 0 ; j < 3 ; j++)
                if(j != host && j != people && doors[j] == 1)
                    sum ++;
        }
        cout << 1.0*sum/n << endl;
    }
}