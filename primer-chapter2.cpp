#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
struct sales_data {
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};
#endif

int main(){
    sales_data data1,data2;
    double price=0;
    cin>> data2.bookNo>>data2.units_sold>>price;
    data2.revenue=data2.units_sold * price;
    cin>> data1.bookNo>>data1.units_sold>>price;
    data1.revenue=data1.units_sold * price;
    if(data1.bookNo == data2.bookNo){
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout<<  data1.bookNo << " " <<totalCnt
            << " " << totalRevenue << " ";
        if(totalCnt != 0)
            cout<<1.0*totalRevenue/totalCnt << std::endl;
        else
        {
            cout<<"(no sales)"<<endl;
        }
        return 0;            
    }
    else {
        std::cerr<<"Data must refer to the same ISBN"<<endl;
        return -1;
    }
    /*
    int i=42;
    const int i1=i;
    const int &i2=i1;
    const int &i3=i1*2;
    int &i4=i;
    int a[10],b[10],c[10];//一个长度为10的数组占了48位 但长度为10的占了400位
    cout<<i1<<i2<<i3<<i4<<endl;
    cout<<&i2<<" "<<&i3;
    cout<<&a<<" "<<&b<<" "<<&c<<endl;
    cout<<&a-&b<<" "<<&b-&a;

    typedef double wages;
    wages ad;
    cin>>ad;
    cout<<ad;

    using money=double;
    money adc;
    decltype(adc) x=10.0;
    return 0;
    */
   return 0;
}