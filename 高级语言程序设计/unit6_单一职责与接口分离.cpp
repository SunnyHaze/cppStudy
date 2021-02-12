// 文件路径名:s6_5\main_6_5.cpp
#include <iostream>  // 编译预处理命令
using namespace std; // 使用命名空间std

const double PI = 3.1415926; // 常量PI

// 声明计算面积的接口CalcArea——抽象类
class CalcArea
{
public:
    // 公有成员:
    virtual ~CalcArea() {}              // 析构函数
    virtual double GetArea() const = 0; // 返回面积
};

// 声明画图接口DrawPhoto——抽象类
class DrawPhoto
{
public:
    // 公有成员:
    virtual ~DrawPhoto() {}        // 析构函数
    virtual void Draw() const = 0; // 画图形
};

// 声明形状类Shape——抽象类
class Shape : public CalcArea, public DrawPhoto
{
};

// 声明圆类Circle
class Circle : public Shape
{
private:
    // 私有成员:
    double radius; // 半径
public:
    // 公有成员:
    Circle(double r) : radius(r) {}                         // 构造函数
    void Draw() const { cout << "圆" << endl; }             // 画图形
    double GetArea() const { return PI * radius * radius; } // 返回面积
};

// 声明圆柱体类Pillar
class Pillar
{
    // 私有成员:
private:
    Shape &bottom; // 底, 此处就是所谓的“合成/聚合”重用
    double height; // 高
public:
    // 公有成员:
    Pillar(Shape &b, double h) : bottom(b), height(h) {}     // 构造函数
    void Draw() const { cout << "圆柱体"; }                  // 画图形
    double GetVolume() { return bottom.GetArea() * height; } // 返回体积
};
int main() // 主函数main()
{
    Circle c(1.0);                 // 定圆对象c
    Pillar p(c, 1.8);              // 定义圆柱体对象p
    cout << p.GetVolume() << endl; // 显示相关信息

    return 0; // 返回值0, 返回操作系统
}
