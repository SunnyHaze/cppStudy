#include "advanced_ptr.cpp"
#include <iostream>
//�Խ��࣬���ڼ�����ָ��ʱ�ġ����塱�Ĺ���ʱ�������ʱ�䡣
class mytest
{
public:
    mytest() { std::cout << "mytest created!" << std::endl; }
    ~mytest() { std::cout << "mytest destroyed!" << std::endl; }
};
//ex1���ڲ�����һ�������ڸ߼�ָ��ĵ��ú����������
void ex1()
{
    std::cout << "---------------" << std::endl;
    std::cout << "Entering ex1" << std::endl;
    advanced_ptr<mytest> e1(new mytest); //��ʼ������һ���߼�ָ�����
    std::cout << "create e1" << std::endl;
    std::cout << "e1.count:" << e1.getRef() << std::endl;
    advanced_ptr<mytest> e2(e1); //��������ڶ����߼�ָ��
    std::cout << "create e2:" << std::endl;
    //���ڼ�⵱ǰ����ָ��ļ�����״̬�Ƿ�����
    std::cout << "e1.count:" << e1.getRef() << std::endl;
    std::cout << "e2.count:" << e2.getRef() << std::endl;
    auto e3 = e1; //��ֵ����������߼�ָ��
    std::cout << "e1.count:" << e1.getRef() << std::endl;
    //���ڼ�⵱ǰ����ָ��ļ�����״̬�Ƿ�����
    std::cout << "e2.count:" << e2.getRef() << std::endl;
    std::cout << "e3.count:" << e3.getRef() << std::endl;
    std::cout << "leaving ex" << std::endl;
    std::cout << "ex1 EXIT!!!!\n---------------"
              << std::endl;
}
//����֧��ex2���Ե�Ƕ�׺���
void ex2_surrport(advanced_ptr<mytest>) //�β��ڴ���������Ҳ�����˿����������������µĶ���
{
    std::cout << "Entering ex2_surrport" << std::endl;
    std::cout << "Leaving ex2_surrport" << std::endl;
}
//ex2���ڲ����ڲ�ͬ�ĺ����ڵĸ߼�ָ��ĵ��ú��������
void ex2()
{
    std::cout << "---------------" << std::endl;
    std::cout << "Entering ex2" << std::endl;
    advanced_ptr<mytest> p1(new mytest); //��ʼ����һ���߼�ָ�����
    //�۲������
    std::cout << "create p1" << std::endl;
    std::cout << "p1.count:" << p1.getRef() << std::endl;
    //���ø߼�ָ����Ϊ�β����õ�����ex2_surrport��
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