#include <iostream>
#include <string>
using namespace std;

template <class Type>
class Tclass
{
public:
    Tclass(Type);
    void setitem(Type);
    Type getitem();
protected:
    Type m_item;
};

template <class Type>
Tclass<Type>::Tclass(Type item){
    m_item = item;
}
template <class Type>
void Tclass<Type>::setitem(Type item){
    m_item = item;
}
template <class Type>
Type Tclass<Type>::getitem(){
    return m_item;
}

class better : public Tclass<int>{
public:
    better(int a){
        m_item = a;    
    }
    void reset(int a){
        m_item = a;
    }
};

template <class Type>
class best : public Tclass<Type>{
public:
    void reset(Type a){
        m_item = a;
    }
};
int main(){
    Tclass<int> obj1(128);
    cout << obj1.getitem() << endl;
    obj1.setitem(218);
    cout << obj1.getitem() << endl;

    Tclass<double> obj2(21.8);
    cout << obj2.getitem() << endl;
    obj2.setitem(11.1);
    cout << obj2.getitem() << endl;
    
    better a(100);
    cout << a.getitem() << "!!!!!" << endl;
    
    return 0; 


}