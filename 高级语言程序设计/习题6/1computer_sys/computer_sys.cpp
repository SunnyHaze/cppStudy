#include <iostream>
using namespace std;
class mouse
{
public:
    mouse() { cout << "单击鼠标" << endl; }
    ~mouse() {}
};
class game
{
public:
    game() { cout << "开始游戏！" << endl; }
    ~game() {}
};

class HardWare
{
private:
    mouse m;

public:
    HardWare() { cout << "创建硬件对象" << endl; }
    ~HardWare() {}
};
class SoftWare
{
private:
    game g;

public:
    SoftWare() { cout << "创建软件对象" << endl; }
    ~SoftWare() {}
};
class COMSYS : public HardWare, public SoftWare
{
public:
    COMSYS() { cout << "创建了计算机系统类" << endl; }
    ~COMSYS() {}
};

int main()
{
    COMSYS obj;
    system("PAUSE");
    return 0;
}