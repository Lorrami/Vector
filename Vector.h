#pragma once

#include <iostream>

template <typename Type>
struct Vector {
private:
    size_t m_MaxSize{};
public:
    Type *m_Array = nullptr;
    size_t m_Size{};

    Vector();
    Vector(const Vector &other);
    ~Vector();

    bool isEmpty();
    size_t Size();
    size_t Capacity();

    void Add(const Type& value);
    void Remove(size_t index);
private:
    void AddMemory();
public:
    template<typename DefType>
    friend std::ostream &operator<<(std::ostream &stream, const Vector& vector);
public:
    Type &operator[](size_t index)  {
        return m_Array[index];
    }
    const Type &operator[](size_t index) const {
        return m_Array[index];
    }
public:
    Type* begin() {
        return &m_Array[0];
    }
    const Type* begin() const {
        return &m_Array[0];
    }
    Type *end() {
        return &m_Array[m_Size];
    }
    const Type *end() const {
        return &m_Array[m_Size];
    }
    Vector &operator = (const Vector &other) {
        m_Array = new Type[m_MaxSize];

        for (auto it : other) {
            Add(it);
        }
        return *this;
    }
};
template<typename Type>
Vector<Type>::Vector() {
    m_MaxSize = 1;
    m_Array = new Type[m_MaxSize];
}
template <typename Type>
Vector<Type>::Vector(const Vector &other) : m_MaxSize(other.m_MaxSize), m_Array(other.m_Array) {
    *this = other;
}
template <typename Type>
Vector<Type>::~Vector() {
    delete[] m_Array;
}
template<typename Type>
bool Vector<Type>::isEmpty() {
    return m_Size == 0;
}
template<typename Type>
size_t Vector<Type>::Size() {
    return m_Size;
}
template<typename Type>
size_t Vector<Type>::Capacity() {
    return m_MaxSize;
}
template<typename Type>
void Vector<Type>::AddMemory() {
    m_MaxSize *= 2;
    Type *tmp = m_Array;
    m_Array = new Type[m_MaxSize];
    for (auto i = 0; i < m_Size; ++i)
        m_Array[i] = tmp[i];
    delete[] tmp;
}
template<typename Type>
void Vector<Type>::Add(const Type& value) {
    if (m_Size >= m_MaxSize)
        AddMemory();
    m_Array[m_Size] = value;
    m_Size++;
}
template<typename Type>
void Vector<Type>::Remove(size_t index) {
    for (auto i = index + 1; i < m_Size - 1; ++i) {
        m_Array[i - 1] = m_Array[i];
    }
    --m_Size;
}
template<typename Type>
std::ostream &operator<<(std::ostream &os, const Vector<Type> &vector) {
    for (auto i = 1; i < vector.m_Size; i++) {
        os << vector.m_Array[i] << std::endl;
    }
    return os;
}