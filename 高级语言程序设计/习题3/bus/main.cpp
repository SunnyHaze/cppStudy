#include <iostream>
#include <string>
#include "bus.h"
int main()
{
    std::vector<std::string> station_list;
    std::string sta[5] = {"第白山", "燕山", "五台山", "泰山", "衡山"};
    for (int i = 0; i < 5; i++)
        station_list.push_back(sta[i]);
    bus mybus;
    std::cout << "请选择站点初始化方式：" << std::endl
              << "1.采用默认预设站点，2.自己输入站点" << std::endl;
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
        std::cout << "请输入要进行的操作：" << std::endl
                  << "1.报站 2.退出程序" << std::endl;
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
            std::cout << "非法的数字！请重新输入！" << std::endl;
            break;
        }
    }
    std::cout << "循环已经终止！";
    system("PAUSE");
    return 0;
}