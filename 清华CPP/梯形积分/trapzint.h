#include <iostream>
#include <cmath>
using namespace std;

class F
{
public:
    virtual double operator ()(double x) const = 0;
};
class Fun : public F
{
public:
    double operator()(double x) const{
        return log(1.0 + x) / (1.0 + x * x);
    }
};

class Integ
{
    virtual double operator () (double a,double b,double eps) const = 0;
};

class Trapz : public Integ
{
private:
    const F &f;

public:
    Trapz(const F &pf) : f(pf){}
    double operator () (double a,double b,double eps) const;
};

