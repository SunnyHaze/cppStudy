#include <iostream>
using namespace std;
template <typename T>
class complex{
private:
    T x;
    T y;

public:
    complex(T xx,T yy) : x(xx) ,y(yy){}
    void get(){
        cout << "X:" << x << "," << "Y:" << y << endl;
    }
    complex operator + (const complex &ob){
        this->x = this->x + ob.x;
        this->y = this->y + ob.y;
        return *this; 
    }
    friend ostream &operator << (ostream &out ,const complex<T> &ob){
        cout << "X:" << ob.x << " Y:" << ob.y << endl;
        return out;
    }
};

// template <typename T>


int main(){
    complex<double> A(1.2,3.4);
    complex<double> B(3.2,4.5);
    cout << A + B;
    return 0;
}
