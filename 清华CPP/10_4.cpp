#include <iostream>
#include <stack>
using namespace std;
template <class T>
void popElements(T &s);

int main(){
    stack<int> intDequeStack;
    for(int i = 0 ; i < 10 ; i++){
        intDequeStack.push(i);
    }
    popElements(intDequeStack);;
    cout << endl;
}

template <class T>
void popElements(T &s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}