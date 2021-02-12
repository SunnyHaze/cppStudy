#ifndef __ADVANCED_PTR_
#define __ADVANCED_PTR_
#include <iostream>

template <typename T> //����ģ��������Ա��ɷ������
class advanced_ptr
{
public:
    advanced_ptr(T *p) : count(new int(1)), _ptr(p) {} //���캯������ʼ���������Լ�ָ�����
    advanced_ptr(advanced_ptr<T> &other) : count(&(++*other.count)), _ptr(other._ptr) {}
    //��ν�Ŀ������캯������һ��ҽ����ζ�ż�����Ҫ��1�����ⷢ����һ��ָ������ͷ����ڴ棬��һ�������С�Ұ��ַ�������
    T *operator->() { return _ptr; }
    T &operator*() { return *_ptr; }

    //���ص����������ͬ�ϣ�Ҫ���Ƽ������Ծ����Ƿ��ͷ��ڴ档
    advanced_ptr<T> &operator=(advanced_ptr<T> &other)
    {
        ++*other.count;                        //��ߵ�ӵ�����ұߵ�ָ��ĵ�ַ����ô�ұߵ�ָ���������һ�Լ���ʣ����������
        if (this->_ptr && 0 == --*this->count) //������ӵ��ptr������ֵ�Ѿ�Ϊ1��ֻʣ�Լ��������Լ������㽫��Դ�������٣��ͷ��ڴ档
        {
            delete count;
            delete _ptr;
            std::cout << "���������㣬�ڴ��ͷţ�"; //�����ã����ڹ۲��ڴ��ͷ����
        }
        this->_ptr = other._ptr; //��������ָ�������ת�ƹ�����
        this->count = other.count;
        return *this;
    }
    //�������������������ж�
    ~advanced_ptr()
    {
        std::cout << "��ͼ����ڴ�,count:" << *count << std::endl; //�����ã����ڹ۲����ٴ���
        if (--*count == 0)
        {
            delete count;
            delete _ptr;
            std::cout << "���������㣬�ڴ��ͷţ�\n"; //�����ã����ڹ۲��ڴ��ͷ����
        }
    }
    //ȡ�õ�ǰ����������ֵ�������ú���
    int getRef() { return *count; }

private:
    int *count; //������ָ��
    T *_ptr;    //����Դָ��
};
#endif