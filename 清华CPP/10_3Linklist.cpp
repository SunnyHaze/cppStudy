#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int> Link;
    int i, key, item;
    for(i = 0 ; i < 10 ; i++){
        cin >> item;
        Link.push_front(item);
    }
    cout << "List:";
    list<int>::iterator p = Link.begin();
    while(p != Link.end()){
        cout << *p++ << " ";

    }
    cout << endl;
    cout << "������һ����Ҫɾ��������:";
    cin >> key;
    Link.remove(key);
    cout << "List:";
    p = Link.begin();
    while(p != Link.end()){
        cout << *p << " ";
        p++;
    }
    cout << endl;
}