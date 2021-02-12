#include <iostream>
using namespace std;
class sample
{
    public:
        sample(){}
        void Memberfunc(int a){
            i = a;
        }
        friend void Friendfunc(sample *,int);
        int geti(){
            return i;
        }
    private:
    int i;
};
void Friendfunc(sample *p1,int a){ // 友元函数没有命名空间，是单独的函数，不需要指出属于的类。代价就是需要将类写入形参列表中。
    p1->i = a;
}
int main(void){
    sample n1 , n2;
    sample *p = &n2;
    sample *p1 = new sample;
    n1.Memberfunc(1);
    p1->Memberfunc(4);
    Friendfunc(p,3);
    cout << n1.geti() <<" " << n2.geti() << p1->geti() << endl;
    delete p1;
    return 0;
}
