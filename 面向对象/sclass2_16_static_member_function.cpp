#include <iostream>
using namespace std;
class demo{
    public:
        demo(int qq = 0) : i(qq){
            j = i;
        }
        static int Incr(){  //静态成员函数不具备 this指针 ，所以不具备对  类对象 进行操作的能力
            return ++j;
        }
        static int Incr(demo p){
            return p.i + j;
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