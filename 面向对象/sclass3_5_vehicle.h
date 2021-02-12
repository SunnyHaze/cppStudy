#include <iostream>
using namespace std;
class vehicle{
    public:
        vehicle(int w,int wei){
            wheels = w;
            weight = wei;
        }
        void show(void) const{
            cout << "轮胎数：" << wheels << " 车重：" << weight << "kg" << endl; 
        }
    private:
        int wheels;
        int weight;    
};
class car:public vehicle{
    public:
        car(int w,int wei,int p):vehicle(w,wei){
            passenger_load = p;
        }
        void show(void) const{
            cout <<"此轿车最多能载客："<<passenger_load<<"人"<<endl;
        vehicle::show();
        }
    private:
        int passenger_load;
};
