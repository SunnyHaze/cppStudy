#include <iostream>
using namespace std;
class MelonMarcket
{
private:
    double weight;
    double unit_price;
    static int total_num;
    static double total_weight;
    static double total_price;

public:
    MelonMarcket(double w, double p)
    {
        weight = w;
        unit_price = p;
        cout << "SALE a melon, weight is:" << weight << "unit price is:" << unit_price << endl;
        total_weight += weight;
        total_num++;
        total_price += w * p;
    }
    ~MelonMarcket() {}
    void returnsale()
    {
        cout << "RETURN a melon,weight is:" << weight << "unit price is:" << unit_price << endl;
        total_num--;
        total_weight -= weight;
        total_price -= weight * unit_price;
    }
    static void show_num()
    {
        cout << "total number:" << total_num << endl;
    }
    static void show_cash()
    {
        cout << "total cash:" << total_price << endl;
    }
    static void show_weight()
    {
        cout << "total weight:" << total_weight << endl;
    }
    static void show_all()
    {
        show_num();
        show_cash();
        show_weight();
        cout << endl;
    }
};
double MelonMarcket::total_weight = 0;
int MelonMarcket::total_num = 0;
double MelonMarcket::total_price = 0;
int main()
{
    MelonMarcket mymarket1(10, 1.5);
    MelonMarcket::show_all();
    MelonMarcket mymarket2(10, 2.4);
    MelonMarcket::show_all();
    mymarket1.returnsale();
    MelonMarcket::show_all();
    system("pause");
    return 0;
}
