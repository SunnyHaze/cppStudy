#include <iostream>
using namespace std;
class mouse
{
public:
    mouse() { cout << "�������" << endl; }
    ~mouse() {}
};
class game
{
public:
    game() { cout << "��ʼ��Ϸ��" << endl; }
    ~game() {}
};

class HardWare
{
private:
    mouse m;

public:
    HardWare() { cout << "����Ӳ������" << endl; }
    ~HardWare() {}
};
class SoftWare
{
private:
    game g;

public:
    SoftWare() { cout << "�����������" << endl; }
    ~SoftWare() {}
};
class COMSYS : public HardWare, public SoftWare
{
public:
    COMSYS() { cout << "�����˼����ϵͳ��" << endl; }
    ~COMSYS() {}
};

int main()
{
    COMSYS obj;
    system("PAUSE");
    return 0;
}