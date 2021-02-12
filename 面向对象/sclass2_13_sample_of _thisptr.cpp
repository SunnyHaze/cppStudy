#ifndef _SCLASS2_13_SAMPLE_H_
#define _SCLASS2_13_SAMPLE_H_

#include <iostream>
using namespace std;
class sample{
    public:
        sample(int a = 1);
        sample add(sample a1,sample a2);
        int getn();
    private:
        int n;
};
sample::sample(int a){
    n = a;
}
sample sample::add(sample a1,sample a2 ){
    this ->  n = a1.n + a2.n;
    return (*this);
}

int sample::getn(){
    return n;
}  
#endif
int main(){
    sample k1,k2(10);
    sample k3;
    k3.add(k1,k2);
    cout << k1.getn << "," << k2.getn << "," << k3; 
}
