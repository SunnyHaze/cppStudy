#include <iostream>
#include <string>
#include "bus.h"
int main()
{
    std::vector<std::string> station_list;
    std::string sta[5] = {"�ڰ�ɽ", "��ɽ", "��̨ɽ", "̩ɽ", "��ɽ"};
    for (int i = 0; i < 5; i++)
        station_list.push_back(sta[i]);
    bus mybus;
    std::cout << "��ѡ��վ���ʼ����ʽ��" << std::endl
              << "1.����Ĭ��Ԥ��վ�㣬2.�Լ�����վ��" << std::endl;
    int status = 1;
    std::cin >> status;
    switch (status)
    {
    case 1:
        mybus.initial(station_list);
        break;
    case 2:
        mybus.initial();
        break;
    default:
        break;
    }
    while (status)
    {
        std::cout << "������Ҫ���еĲ�����" << std::endl
                  << "1.��վ 2.�˳�����" << std::endl;
        std::cin >> status;
        switch (status)
        {
        case 1:
            mybus.report();
            break;
        case 2:
            mybus.~bus();
            status = 0;
            break;
        default:
            std::cout << "�Ƿ������֣����������룡" << std::endl;
            break;
        }
    }
    std::cout << "ѭ���Ѿ���ֹ��";
    system("PAUSE");
    return 0;
}