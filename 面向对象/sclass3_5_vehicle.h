#include <iostream>
using namespace std;
class vehicle{
    public:
        vehicle(int w,int wei){
            wheels = w;
            weight = wei;
        }
        void show(void) const{
            cout << "��̥����" << wheels << " ���أ�" << weight << "kg" << endl; 
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
            cout <<"�˽γ�������ؿͣ�"<<passenger_load<<"��"<<endl;
        vehicle::show();
        }
    private:
        int passenger_load;
};
