// �ļ�·����:s6_5\main_6_5.cpp
#include <iostream>  // ����Ԥ��������
using namespace std; // ʹ�������ռ�std

const double PI = 3.1415926; // ����PI

// ������������Ľӿ�CalcArea����������
class CalcArea
{
public:
    // ���г�Ա:
    virtual ~CalcArea() {}              // ��������
    virtual double GetArea() const = 0; // �������
};

// ������ͼ�ӿ�DrawPhoto����������
class DrawPhoto
{
public:
    // ���г�Ա:
    virtual ~DrawPhoto() {}        // ��������
    virtual void Draw() const = 0; // ��ͼ��
};

// ������״��Shape����������
class Shape : public CalcArea, public DrawPhoto
{
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
private:
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
    Circle c(1.0);                 // ��Բ����c
    Pillar p(c, 1.8);              // ����Բ�������p
    cout << p.GetVolume() << endl; // ��ʾ�����Ϣ

    return 0; // ����ֵ0, ���ز���ϵͳ
}
