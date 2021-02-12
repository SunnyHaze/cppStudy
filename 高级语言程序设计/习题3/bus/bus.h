#include <iostream>
#include <string>
#include <vector>
class bus
{
private:
    std::vector<std::string> station;
    int b_number;
    int b_line;
    int b_sta_num;
    int b_local_num = 0;

public:
    bus()
    {
        std::cout << "请输入公交车线路：";
        std::cin >> b_line;
        std::cout << "请输入公交车车号：";
        std::cin >> b_number;
        std::cout << std::endl
                  << "这是第" << b_line << "路公交线路上的第" << b_number << "号车，很高兴为各位乘客服务！";
    }
    ~bus()
    {
        std::cout << "欢迎下次使用！";
    }
    void initial()
    {
        std::cout << "请输入本线路共有站数：";
        std::cin >> b_sta_num;
        for (int i = 0; i != b_sta_num; i++)
        {
            std::cout << "请输入第" << i + 1 << "站的名称:";
            std::string b_station;
            std::cin >> b_station;
            station.push_back(b_station);
        }
    }

    void initial(std::vector<std::string> obj)
    {
        station = obj;
        b_sta_num = obj.size();
    }
    void report()
    {
        std::cout << std::endl
                  << "【" << station[b_local_num] << "】站到了，要下车的乘客，请从后门下车。\n"
                  << std::endl;
        b_local_num++;
        if (b_local_num == b_sta_num)
            b_local_num = 0;
    }
};