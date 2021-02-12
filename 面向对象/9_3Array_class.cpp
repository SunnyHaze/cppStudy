#ifndef  ARRAY_CLASS
#define ARRAY_CLASS

#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef NULL
const int NULL = 0;
#endif

enum ErrorType{
    invalidArraySize,memeoryAllocationError,indexOutOfRange
};

string errorMsg[] ={
    "Invalid array size","Memory allocation error","Invalid index:"
};

template <class T>
class Array
{
    private:
        T* alist;
        int size;
        void Error(ErrorType error,int badIndex = 0) const;
    
    public:
        Array(int sz = 50);
        Array(const Array<T> &A);
        ~Array(void);
        Array<T>& operator = (const Array<T> &rhs);
        T& operator[] (int i);
        operator T*(void) const;
        int ListSize(void) const;
        void Resize(int sz);
};
//Error实现输出错误信息的功能
template <class T>
void Array<T>::Error(ErrorType error,int badIndex) const{
    cout << errorMsg[error];
    if(error == indexOutOfRange)
        cout << badIndex;
    cout << endl;
    exit(0);
}

template <class T>
Array<T>::Array(int sz){
    cout <<"构造函数！";
    if(sz <= 0){
        Error(invalidArraySize);
    size = sz;
    alist = new T[size];
    if(alist == NULL)
        Error(memeoryAllocationError);
    }
    cout << "构造成功！";
}

template <class T>
Array<T>::~Array(){
    delete [] alist;
}

template <class T>
Array<T>::Array(const Array<T> &x){
    size = x.size;
    int n = x.size;
    alist = new T[size];
    if(alist == NULL)
        Error(memeoryAllocationError);
    T* srcptr = x.alist;
    T* destptr = alist;
    while(n--){
        *destptr++ = *srcptr++;
    }
}

template <class T>
Array<T>& Array<T>::operator = (const Array<T> &rhs){
    int n = rhs.size;

    if(size != n){
        delete [] alist;
        alist = new T[n];
        if(alist == NULL){
            Error(memeoryAllocationError);
        }
        size = n;
    }
    T* destptr = alist;
    T* srcptr = rhs.alist;
    while(n--)
        *destptr++ = *rhs.alist++;
    return *this;
}
template <class T>
T& Array<T>::operator [](int n){
    if(n < 0 || n > size -1){
        Error(indexOutOfRange,n);
    }
    cout << n <<"调用成功！";
    return alist[n];
}
//这个重载比较重要
template <class T>
Array<T>::operator T *() const{
    return alist;
}

template <class T>
int Array<T>::ListSize(void) const{
    return size;
}

template <class T>
void Array<T>::Resize(int sz){
    if(sz < 0){
        Error(invalidArraySize);
    }
    if(sz == size){
        return;
    }
    T* newlist = new T[sz];
    if(newlist == NULL)
        Error(memeoryAllocationError);
    int n = (sz < size) ? sz : size;
    T * srcptr = alist;
    T * destptr = newlist;
    while(n--)
        *destptr++ = *srcptr++;
    delete [] alist;
    alist = newlist;
    size = sz;
}
#endif

int main(){
    Array<int> a(50); //强数组的界限为50 超过50理应 由exit(0)退出
    a[60] = 1;
    a[55] = 2;

    for(int i = 0 ; i < 2 ; i++){
        cout << "kkk" << endl;
    }
}
