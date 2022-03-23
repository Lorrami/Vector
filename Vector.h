#pragma once

#include <iostream>

template <typename Type>
struct Vector
{
private:
    size_t m_MaxSize{};
public:
    Type* m_Array;
    size_t m_Size{};

    Vector();
    ~Vector();

    bool isEmpty();
    size_t Size();
    size_t Capacity();

    void Add(const Type& value);
public:
    template<typename DefType>
    friend std::ostream &operator<<(std::ostream &stream, const Vector& vector);
public:
    Type& operator[](size_t index)  {
        return m_Array[index];
    }
    const Type& operator[](size_t index) const {
        return m_Array[index];
    }
private:
    void AddMemory();

};
template<typename Type>
Vector<Type>::Vector()
{
    m_Array = new Type[1];
    m_MaxSize = 1;
}
template <typename Type>
Vector<Type>::~Vector()
{
    delete[] m_Array;
}
template<typename Type>
bool Vector<Type>::isEmpty()
{
    return m_Size == 0;
}
template<typename Type>
size_t Vector<Type>::Size()
{
    return m_Size;
}
template<typename Type>
size_t Vector<Type>::Capacity()
{
    return m_MaxSize;
}

template<typename Type>
void Vector<Type>::AddMemory()
{
    m_MaxSize *= 2;
    Type* tmp = m_Array;
    m_Array = new Type[m_MaxSize];
    for (auto i = 0; i < m_Size; ++i)
        m_Array[i] = tmp[i];
    delete[] tmp;
}

template<typename Type>
void Vector<Type>::Add(const Type& value)
{
    if (m_Size >= m_MaxSize)
        AddMemory();
    m_Array[m_Size] = value;
    m_Size++;
}

template<typename Type>
std::ostream &operator<<(std::ostream& os, const Vector<Type>& vector)
{
    for (auto i = 0; i < vector.m_Size; i++)
    {
        os << vector.m_Array[i] << std::endl;
    }
    return os;
}
