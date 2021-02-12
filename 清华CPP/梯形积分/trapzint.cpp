#include "trapzint.h"
double Trapz::operator () (double a,double b,double eps) const
{
    int done(0);
    int n;
    double h,Tn,T2n;
    n = 1;
    h = b - a;
    Tn = h * (f(a) + f(b)) / 2.0;
    while(!done){
        double temp(0.0); //进行一次尝试积分
        for(int k = 0 ; k < n ; k++){
            double x = a + (k + 0.5) * h;
            temp += f(x);
        }
        T2n = (Tn + h * temp) / 2.0;
        if(fabs(T2n - Tn) < eps) done = 1;
        else{
            Tn = T2n;
            n *= 2;
            h /= 2;
        }
    }
    return T2n;
}