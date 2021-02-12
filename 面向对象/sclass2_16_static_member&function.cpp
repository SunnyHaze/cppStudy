#include <iostream>
using namespace std;
class demo{
    public:
        demo(int ii = 0) : i(ii){
            j = i;
        }
        static int Incr(){  //静态成员函数不具备 this指针 ，所以不具备对  类对象 进行操作的能力
            return ++j;
        }
        private:
        int i;
        static int j;
};
int demo::j = 0;
int main(){
    cout << "j=" << demo ::Incr() << endl;
    return 0;
}