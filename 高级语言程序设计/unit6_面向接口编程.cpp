#include <iostream>
using namespace std;
const double PI = 3.1415926; // ����PI

// ������״��Shape����������
class Shape
{
public:
    // ���г�Ա:
    Shape() {}                          // ���캯��
    virtual ~Shape() {}                 // ��������
    virtual void Draw() const = 0;      // ��ͼ��
    virtual double GetArea() const = 0; // �������
};
// ����Բ��Circle
class Circle : public Shape
{
private:
    // ˽�г�Ա:
    double radius; // �뾶
public:
    // ���г�Ա:
    Circle(double r) : radius(r) {}                         // ���캯��
    void Draw() const { cout << "Բ" << endl; }             // ��ͼ��
    double GetArea() const { return PI * radius * radius; } // �������
};

// ����Բ������Pillar
class Pillar
{
    // ˽�г�Ա:
public:
    Shape &bottom; // ��, �˴�������ν�ġ��ϳ�/�ۺϡ�����
    double height; // ��
public:
    // ���г�Ա:
    Pillar(Shape &b, double h) : bottom(b), height(h) {}     // ���캯��
    void Draw() const { cout << "Բ����"; }                  // ��ͼ��
    double GetVolume() { return bottom.GetArea() * height; } // �������
};
int main() // ������main()
{
    Circle c(1.0);    // ��Բ����c
    Pillar p(c, 1.8); // ����Բ�������p
    p.bottom.Draw();
    cout << p.GetVolume() << endl; // ��ʾ�����Ϣ

    return 0; // ����ֵ0, ���ز���ϵͳ
}
