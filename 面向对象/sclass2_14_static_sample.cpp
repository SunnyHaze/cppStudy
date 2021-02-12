#include <iostream>
using namespace std;
class point {
    public:
        point(){
            x = 0;
            y = 0;
            counter++;
        }
        ~point(){
            counter--;
        }
        point(float x,float y){
            this -> x = x;
            this -> y = y;
            counter++;
        }
        void move(float x,float y){
            this -> x = x;
            this -> y = y;
        }
        float getx(){
            return x;
        }
        float gety(){
            return y;
        }
        private:
            float x;
            float y;
        
        public:
            static int counter;
};
int point::counter = 0;
int main(){
    point p0;
    point *p1 = new point(1,1);
    point *p2 = new point(1,3);
    point *p3 = new point(3,3);
    cout << "已经创建的点的个数是："<< point::counter <<endl;
    delete p1;
    delete p2;
    delete p3;
    p0.~point();
    cout <<"已经创建得到的点的个数是：" << point::counter << endl;
    return 0;

}