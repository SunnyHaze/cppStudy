#include "time.h"
Time::Time() : hh(0), mm(0), ss(0)
{
    ;
}
Time::~Time()
{
    ;
}
Time::Time(int h, int m, int s) : hh(h), mm(m), ss(s)
{
    ;
}
void Time::PrintTime()
{
    std::cout << hh << ":" << mm << ":" << ss << std::endl;
}