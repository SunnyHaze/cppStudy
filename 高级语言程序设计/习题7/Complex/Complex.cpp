#include <iostream>
using namespace std;
template <typename T>
class Complex
{
private:
    T real;
    T image;

public:
    Complex() {}
    Complex(T REAL, T IMAGE) : real(REAL), image(IMAGE) {}
    ~Complex() {}
    void Show()
    {
        cout << "ÊµÊýÓò£º" << real;
        cout << "   ¸´ÊýÓò£º" << image << endl;
    }
    Complex<T> &operator+(const Complex<T> &b);
    Complex<T> &operator=(const Complex<T> &copy);
};
template <typename T>
Complex<T> &Complex<T>::operator+(const Complex<T> &b)
{
    real += b.real;
    image += b.image;
    return *this;
}
template <typename T>
Complex<T> &Complex<T>::operator=(const Complex<T> &copy)
{
    if (this != &copy)
    {
        image = copy.image;
        real = copy.real;
    }
    return *this;
}
int main()
{
    Complex<int> obj1(1, 2), obj2(2, 3), obj3(0, 0);
    obj1.Show();
    obj3 = obj1 + obj2;
    obj3.Show();

    Complex<double> obj4(1.1, 2.2), obj5(2.2, 3.3);
    obj4 = obj4 + obj5;
    obj4.Show();

    system("PAUSE");
    return 0;
}