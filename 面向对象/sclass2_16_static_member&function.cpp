#include <iostream>
using namespace std;
class demo{
    public:
        demo(int ii = 0) : i(ii){
            j = i;
        }
        static int Incr(){  //��̬��Ա�������߱� thisָ�� �����Բ��߱���  ����� ���в���������
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