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
        std::cout << "�����빫������·��";
        std::cin >> b_line;
        std::cout << "�����빫�������ţ�";
        std::cin >> b_number;
        std::cout << std::endl
                  << "���ǵ�" << b_line << "·������·�ϵĵ�" << b_number << "�ų����ܸ���Ϊ��λ�˿ͷ���";
    }
    ~bus()
    {
        std::cout << "��ӭ�´�ʹ�ã�";
    }
    void initial()
    {
        std::cout << "�����뱾��·����վ����";
        std::cin >> b_sta_num;
        for (int i = 0; i != b_sta_num; i++)
        {
            std::cout << "�������" << i + 1 << "վ������:";
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
                  << "��" << station[b_local_num] << "��վ���ˣ�Ҫ�³��ĳ˿ͣ���Ӻ����³���\n"
                  << std::endl;
        b_local_num++;
        if (b_local_num == b_sta_num)
            b_local_num = 0;
    }
};