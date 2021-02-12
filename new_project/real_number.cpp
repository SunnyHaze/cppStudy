#include "real_number.h"
#include <iterator>
#include <algorithm>
real::real(const char *in_data)
{
    std::string i_data(in_data);

    if (i_data.find(".") != std::string::npos)
    {
        point = 1;
        if (i_data[0] == '-')
        {
            positive = 0;
            for (int i = 1; i != i_data.find("."); i++)
            {
                value.push_back(i_data[i]);
            }
            for (int i = i_data.find(".") + 1; i != i_data.length(); i++)
            {
                decimal.push_back(i_data[i]);
            }
        }
        else
        {
            positive = 1;
            for (int i = 0; i != i_data.find("."); i++)
            {
                value.push_back(i_data[i]);
            }
            for (int i = i_data.find(".") + 1; i != i_data.length(); i++)
            {
                decimal.push_back(i_data[i]);
            }
        }
    }
    else
    {
        point = 0;
        if (i_data[0] == '-')
        {
            positive = 0;
            for (int i = 1; i != i_data.length(); i++)
            {
                value.push_back(i_data[i]);
            }
        }
        else
        {
            positive = 1;
            for (int i = 0; i != i_data.length(); i++)
            {
                value.push_back(i_data[i]);
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, const real &item)
{
    if (!item.positive)
        std::cout << "-";
    if (item.point)
        std::cout << item.value << "." << item.decimal;
    else
        std::cout << item.value;
    return os;
}

std::string real::splus(std::string a, std::string b, int &jinwei)
{
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int x[a.length() + 1],y[b.length() + 1];
    for (int i = 0; i != a.length(); i++)
    {
        x[i] = a[i] - '0';
    }
    for (int i = 0; i != b.length(); i++)
    {
        y[i] = b[i] - '0';
    }
    int max = a.length() > b.length() ? a.length() : b.length();
    int jw = 0;
    for (int i = 0; i <= max; i++)
    {
        x[i] += y[i] + jw;
        jw = x[i] / 10;
        x[i] %= 10;
    }
    for(auto i:x){
        std::cout << "!!!" << i << std::endl;
    }
    std::string temp;
    int ii = max;
    while(x[ii]== 0)
        ii--;
    while (ii>=0)
    {
        temp.push_back(x[ii] + '0');
        ii--;
    }
        std::cout << a << " " << b << " " << max <<" " << temp << std::endl;
    std::cout << temp;
    std::reverse(temp.begin(), temp.end());
    return temp;
}

real real::operator+(real obj)
{
    real temp;
    temp.decimal.clear();
    temp.value.clear();
    if (value >= obj.value)
    {
        temp.positive = positive;
    }
    int jinwei = 0;
    value = splus(value, obj.value, jinwei);
    return *this;
}

real real::operator=(real obj)
{
    decimal = obj.decimal;
    value = obj.value;
    point = obj.point;
    positive = obj.positive;
    return *this;
}