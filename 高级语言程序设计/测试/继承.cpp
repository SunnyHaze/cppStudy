#include <iostream>
using namespace std;
class A
{
private:
    int a;

public:
    A(int x = 0) : a(x) {}
    void seta(int dick)
    {
        a = dick;
    }
    virtual void show() const { cout << "a=" << a << endl; }
};
class B : public A
{
protected:
    int b;

public:
    B(int x = 0, int y = 0) : A(x), b(y) {}
    void show() const
    {
        A::show();
        cout << "b=" << b << endl;
    }
};
int main()
{
    B objb(1, 2);
    A obja = objb;
    obja.show();

    A *pa = &obja;
    pa = &objb;
    obja.seta(100);
    pa->show();
    pa = &obja;
    pa->show();
}