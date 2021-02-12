#include <iostream>
using namespace std;
const double pi = 3.1415926535;
class Circle{
    protected:
        double radius;
    public:
        void SetRadius(double r){
            radius = r;
        }
        double GetRadius(void) const{
            return radius;
        }
        double GetArea(void) const{
            return pi * radius * radius;
        }
        void print() const{
            cout << "半径为" << radius << "的圆的面积是" << GetArea() << endl;
        }
};
class cylinder : Circle{
    public:
        void SetHeight(double h){
            height = h;
        }
        void SetRadius(double r){
            Circle::SetRadius(r);
        }
        void GetRadius(void){
            Circle::GetRadius();
        }
        double GetHeight(void){
            return height;
        }
        double GetArea() const{
            return (2*pi*radius*radius + 2* pi * radius * height);
        }
        double GetVolume() const{
            return (pi * radius * radius * height);
        }
        void print() const{
            cout << "底半径是" << radius << "的圆柱体表面积是" << GetArea() << ",体积是" << GetVolume() << endl;
        }
    private:
        double height;
};
int main(){
    int n;
    cin >> n;
    cylinder c1;
    c1.GetRadius();
    c1.SetHeight(10.5);
    c1.SetRadius(12.5);
    cout <<c1.GetArea()<<" "<< c1.GetVolume();
    return 0;
}