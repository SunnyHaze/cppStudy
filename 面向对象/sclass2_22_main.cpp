#include <iostream>
class time{
    public:
        time();
        time(int n){
            this->t = n;
        }
        // int gett(){
        //     return t;
        // }
        int gett() const{ //�������س�����ʵ��const��ȡ
            return t;
        }
    private:
        int t;
        const int pi = 3.14159;
};
using namespace std;
int main(){
    const class time t1(1);
    class time t2(2);
    cout << t2.gett() << endl;
    return 0;
}