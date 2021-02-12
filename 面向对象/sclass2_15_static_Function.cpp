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
        static int getCounter(){ //static 必须要写以表明其为静态成员函数。
            return counter;
        }
        private:
            float x;
            float y;
            static int counter;
};
int point::counter = 0;
int main(){
    point p0;
    point *p1 = new point(1,1);
    point *p2 = new point(1,3);
    point *p3 = new point(3,3);
    cout << "已经创建的点的个数是："<< point::getCounter() << endl; //直接通过类名访问静态成员函数，无需找一个变量，具有“全局性”
    delete p1;
    delete p2;
    delete p3;
    p0.~point();
    cout <<"已经创建得到的点的个数是：" << point::getCounter() << endl;
    return 0;

}