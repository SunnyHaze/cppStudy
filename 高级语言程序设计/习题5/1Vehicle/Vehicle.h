#pragma once
#include <iostream>
using namespace std;
class Vehicle
{
protected:
    int wheels;
    double weight;

public:
    Vehicle(int whe, double wei) : wheels(whe), weight(wei) {}
    virtual void Show() const
    {
        cout << "轮子数：" << wheels << endl
             << "重量：" << weight << endl;
    }
};
class Car : private Vehicle
{
private:
    int passengerLoad;

public:
    Car(int wheels, double weight, int passload) : Vehicle(wheels, weight), passengerLoad(passload) {}
    void Show() const
    {
        Vehicle::Show();
        cout << "载人数：" << passengerLoad << endl;
    }
};
class Truck : private Vehicle
{
private:
    int passengerload;
    double payload;

public:
    Truck(int wheels, double weight, int passload, double pload) : Vehicle(wheels, weight), passengerload(passload), payload(pload) {}
    void Show() const
    {
        Vehicle::Show();
        cout << "载人数：" << passengerload << endl;
        cout << "载重量：" << payload << endl;
    }
};