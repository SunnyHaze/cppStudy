#include "sclass2_20_cstack.cpp"
int main(){
    cstack stack;
    stack.push_back(1);
    stack.push_back(2);
    stack.push_back(3);
    for(int i = 0 ; i < 3; i++){
        cout << stack.pop() << endl;
    }
    stack.pop();
    stack.pop();
    return 0;
}
