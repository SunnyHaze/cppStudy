#include <iostream>
using namespace std;
class demo{
    public:
        demo(int qq = 0) : i(qq){
            j = i;
        }
        static int Incr(){  //��̬��Ա�������߱� thisָ�� �����Բ��߱���  ����� ���в���������
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