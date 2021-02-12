#include <iostream>
using namespace std;

class shape{
    public:
        virtual double calculatearea() const= 0; //定义一个纯虚函数
    protected:
        double m_area;
};

class circle : public shape{
    public:
        circle(double radius);
        double calculatearea() const;
    protected:
        double m_radius;
};

class rectangle:public shape{
    public:
        rectangle(double lenth , double width);
        double calculatearea() const;
    protected:
        double m_lenth;
        double m_width;
};

class square:public shape{
    public:
        square(double edge);
        double calculatearea() const;
    protected:
        double m_edge;
};

circle::circle(double radius) : m_radius(radius){

}

double circle::calculatearea() const{
    cout << "circle：" << 3.14*m_radius*m_radius << "." << endl;
    return 3.14*m_radius*m_radius;
}

rectangle::rectangle(double lenth,double width):m_lenth(lenth) , m_width(width){

}
double rectangle::calculatearea() const {
    cout << "rectangle：" << m_width * m_lenth << "." << endl;
    return m_width * m_lenth;
}

square::square(double edge) : m_edge(edge){

}
double square::calculatearea() const {
    cout << "square:" << m_edge * m_edge << "." << endl;
    return m_edge * m_edge;
}

void reference(shape &rocs){
    rocs.calculatearea();
}

int main(){
    shape* pocp;
    circle occ(10.0);
    rectangle ocr(6.18,5.0);
    square ocs(11.1);

    cout << "以下为指针重新覆盖 纯虚函数"<<endl;
    pocp = &occ;
    pocp->calculatearea();
    pocp = &ocr;
    pocp->calculatearea();
    pocp = &ocs;
    pocp->calculatearea();

    cout << endl;

    cout << "一下为引用调用 纯虚函数" << endl;   
    reference(occ);
    reference(ocr);
    reference(ocs);

    return 0;
}