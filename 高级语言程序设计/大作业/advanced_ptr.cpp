#ifndef __ADVANCED_PTR_
#define __ADVANCED_PTR_
#include <iostream>

template <typename T> //采用模板类设计以便达成泛型设计
class advanced_ptr
{
public:
    advanced_ptr(T *p) : count(new int(1)), _ptr(p) {} //构造函数，初始化计数器以及指针对象
    advanced_ptr(advanced_ptr<T> &other) : count(&(++*other.count)), _ptr(other._ptr) {}
    //所谓的拷贝构造函数，多一次医用意味着计数器要加1，以免发生了一个指针对象释放了内存，另一个还持有“野地址”的情况
    T *operator->() { return _ptr; }
    T &operator*() { return *_ptr; }

    //重载等于运算符，同上，要控制计数器以决策是否释放内存。
    advanced_ptr<T> &operator=(advanced_ptr<T> &other)
    {
        ++*other.count;                        //左边的拥有了右边的指针的地址，那么右边的指针计数器加一以计算剩余引用数。
        if (this->_ptr && 0 == --*this->count) //如果左侧拥有ptr并且其值已经为1（只剩自己在引用自己），便将其源数据销毁，释放内存。
        {
            delete count;
            delete _ptr;
            std::cout << "计数器清零，内存释放！"; //测试用，用于观测内存释放情况
        }
        this->_ptr = other._ptr; //正常将右指针的数据转移过来。
        this->count = other.count;
        return *this;
    }
    //析构函数，进行销毁判定
    ~advanced_ptr()
    {
        std::cout << "试图清除内存,count:" << *count << std::endl; //测试用，用于观测销毁次数
        if (--*count == 0)
        {
            delete count;
            delete _ptr;
            std::cout << "计数器清零，内存释放！\n"; //测试用，用于观测内存释放情况
        }
    }
    //取得当前计数器数数值，测试用函数
    int getRef() { return *count; }

private:
    int *count; //计数器指针
    T *_ptr;    //核心源指针
};
#endif