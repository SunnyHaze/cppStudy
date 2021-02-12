// Modified by @mikecovlee, 2020/2/17
#include <iostream>
#include <cstdlib>
#include <string>

enum ErrorType
{
    SizeError = 0,
    MemoryError = 1,
    OutOfRange = 2
};

std::string errorMsg[] = {
    "Invalid array size", "Memory allocation error", "Invalid index:"};

template <class T>
class Array
{
private:
    T *alist;
    int size;
    void Error(ErrorType error, int badIndex = 0) const;

public:
    Array() = delete;
    explicit Array(int = 50);
    Array(const Array<T> &A);
    ~Array();
    Array<T> &operator=(const Array<T> &rhs);
    T &operator[](int);
    operator T *() const;
    int ListSize() const;
    void Resize(int);
};

//Error实现输出错误信息的功能
template <class T>
void Array<T>::Error(ErrorType error, int badIndex) const
{
    std::cerr << errorMsg[error];
    if (error == OutOfRange)
        std::cerr << badIndex;
    std::cerr << std::endl;
    std::exit(0);
}

template <class T>
Array<T>::Array(int sz)
{
    if (sz <= 0)
        Error(Sizerror);
    size = sz;
    alist = new T[size];
    if (alist == nullptr)
        Error(MemoryError);
}

template <class T>
Array<T>::~Array()
{
    delete[] alist;
}

template <class T>
Array<T>::Array(const Array<T> &x)
{
    size = x.size;
    alist = new T[size];
    if (alist == nullptr)
        Error(MemoryError);
    T *srcptr = x.alist;
    T *destptr = alist;
    for (int n = x.size; n--;)
    {
        *destptr++ = *srcptr++;
    }
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    int n = rhs.size;
    if (size != n)
    {
        delete[] alist;
        alist = new T[n];
        if (alist == nullptr)
            Error(MemoryError);
        size = n;
    }
    T *destptr = alist;
    T *srcptr = rhs.alist;
    while (n--)
        *destptr++ = *rhs.alist++;
    return *this;
}

template <class T>
T &Array<T>::operator[](int n)
{
    if (n < 0 || n > size - 1)
        Error(OutOfRange, n);
    return alist[n];
}

//杩欎釜閲嶈浇姣旇緝閲嶈??
template <class T>
Array<T>::operator T *() const
{
    return alist;
}

template <class T>
int Array<T>::ListSize(void) const
{
    return size;
}

template <class T>
void Array<T>::Resize(int sz)
{
    if (sz < 0)
        Error(SizeError);
    if (sz == size)
        return;
    T *newlist = new T[sz];
    if (newlist == nullptr)
        Error(MemoryError);
    int n = (sz < size) ? sz : size;
    T *srcptr = alist;
    T *destptr = newlist;
    while (n--)
        *destptr++ = *srcptr++;
    delete[] alist;
    alist = newlist;
    size = sz;
}

int main()
{
    Array<int> a(50);
    for(int i = 0 ; i < 50 ; i++){
        a[i] = i + 1;
    }
    std::cout << std::endl;
    std::cout << a[4];

    return 0;
}
