#ifndef _STAFF_
#define _STAFF_

#include <iostream>
using namespace std;

class Staff{
    public:
        Staff(void){
            salary = 1000.0;
        }
        ~Staff(void){}
        void SetSalary(double ss){
            this->salary = ss;
            this->number = counter++;
        }
        double GetSalary(){
            return salary;
        }
        double GetNumber(){
            return number;
        }
        int GetCounter(){
            return counter;
        }

    private:
        double salary;
        int number;
        static int counter;
};
#endif