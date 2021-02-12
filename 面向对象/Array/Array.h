#pragma once
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
