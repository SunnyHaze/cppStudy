#include "advanced_ptr.cpp"
#include <iostream>
//自建类，用于检测调用指针时的“载体”的构造时间和析构时间。
class mytest
{
public:
    mytest() { std::cout << "mytest created!" << std::endl; }
    ~mytest() { std::cout << "mytest destroyed!" << std::endl; }
};
//ex1用于测试在一个函数内高级指针的调用和销毁情况。
void ex1()
{
    std::cout << "---------------" << std::endl;
    std::cout << "Entering ex1" << std::endl;
    advanced_ptr<mytest> e1(new mytest); //初始化构造一个高级指针对象
    std::cout << "create e1" << std::endl;
    std::cout << "e1.count:" << e1.getRef() << std::endl;
    advanced_ptr<mytest> e2(e1); //拷贝构造第二个高级指针
    std::cout << "create e2:" << std::endl;
    //用于检测当前两个指针的计数器状态是否正常
    std::cout << "e1.count:" << e1.getRef() << std::endl;
    std::cout << "e2.count:" << e2.getRef() << std::endl;
    auto e3 = e1; //赋值构造第三个高级指针
    std::cout << "e1.count:" << e1.getRef() << std::endl;
    //用于检测当前三个指针的计数器状态是否正常
    std::cout << "e2.count:" << e2.getRef() << std::endl;
    std::cout << "e3.count:" << e3.getRef() << std::endl;
    std::cout << "leaving ex" << std::endl;
    std::cout << "ex1 EXIT!!!!\n---------------"
              << std::endl;
}
//用于支持ex2测试的嵌套函数
void ex2_surrport(advanced_ptr<mytest>) //形参在创建过程中也引用了拷贝变量，产生了新的对象
{
    std::cout << "Entering ex2_surrport" << std::endl;
    std::cout << "Leaving ex2_surrport" << std::endl;
}
//ex2用于测试在不同的函数内的高级指针的调用和销毁情况
void ex2()
{
    std::cout << "---------------" << std::endl;
    std::cout << "Entering ex2" << std::endl;
    advanced_ptr<mytest> p1(new mytest); //初始化第一个高级指针对象
    //观测其参数
    std::cout << "create p1" << std::endl;
    std::cout << "p1.count:" << p1.getRef() << std::endl;
    //将该高级指针作为形参引用到函数ex2_surrport中
    ex2_surrport(p1);
    std::cout << "Leaving ex2" << std::endl;
    std::cout << "---------------" << std::endl;
}

int main()
{
    ex1();
    ex2();
    return 0;
    system("PAUSE");
}