#include <iostream>
using namespace std;
class B
{
public:
    virtual void F(const char *)
    {
        cout << "B::F(const char*)" << endl;
    }
    virtual void F(int) const
    {
        cout << "B::F(int) const" << endl;
    }
};
class D : public B
{
public:
    void F(int) const
    {
        cout << "D::F(int)" << endl;
    }
    void F(const char *)
    {
        cout << "D::F(const char*)" << endl;
    }
};
class E : public D
{
public:
    void F(int) const
    {
        cout << "E::F(int)" << endl;
    }
};
int main()
{
    D d;
    E e;
    B *p = &d;
    p->F(1);
    p->F("My String");
    p = &e;
    p->F(1);
    p->F("mystring");
    return 0;
}