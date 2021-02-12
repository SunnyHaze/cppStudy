#include <iostream>
#include <cstring>
using namespace std;
class A
{
    private:
        friend class B;
        string *name;
        int age;
    public:
        A(const char *str,int n){
            name = new string(str);
            age = n;
        }
};
class B{
    public:
        void show(A x){
            cout << "name:" << *x.name << endl;
            cout << "age:" << x.age << endl;
        }
};
int main(){
    string myname("Mike");
    A a(myname.c_str(),99);
    B b;
    b.show(a);
    return 0;
}