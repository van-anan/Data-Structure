#pragma once

#include <exception>

#include <algorithm>
template<typename T>
class Heap {
public:
    Heap();
    Heap(const Heap<T>&);
    Heap<T>& operator = (const Heap<T>&);
    ~Heap();

    bool empty() {
        return m_size == 0;
    }
    int size() {
        return m_size;
    }
    const T& max() {
        if (!empty()) {
            return m_data[1];
        }
        else {
            throw std::exception("The tree is empty");
        }
    }
    void remove();
    void insert(const T&);
private:
    void deallocate();

    static const int Max_size = 30;
    int m_size;
    int m_max_size;
    T* m_data;
};
template<typename T>
Heap<T>::Heap() : m_size(0), m_max_size(Max_size), m_data(nullptr) {
    m_data = new int[m_max_size];
}
template<typename T>
Heap<T>::Heap(const Heap<T>& other) : m_size(other.m_size), m_max_size(other.m_max_size), m_data(nullptr) {
    m_data = new int[m_max_size];
    for (int i = 1; i <= m_size; i++) {
        m_data[i] = other.m_data[i];
    }
}
template<typename T>
Heap<T>& Heap<T>::operator = (const Heap<T>& other) {
    if (this != &other) {
        deallocate();
        m_size = other.m_size;
        m_max_size = other.m_max_size;
        m_data = new int[m_max_size];
        for (int i = 1; i < m_size; i++) {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}
template<typename T>
Heap<T>::~Heap() {
    deallocate();
}
template<typename T>
void Heap<T>::insert(const T& element) {
    if (m_size + 1 == m_max_size) {
        m_max_size *= 2;
        int* data = new int(m_max_size);
        for (int i = 1; i <= m_size; i++) {
            data[i] = m_data[i];
        }
        deallocate();
        m_data = data;
    }
    m_data[++m_size] = element;
    int t = m_size;
    while (t != 1 && m_data[t] > m_data[t / 2]) {
        std::swap(m_data[t], m_data[t / 2]);
        t /= 2;
    }
}
template<typename T>
void Heap<T>::remove() {
    if (empty()) {
        throw std::exception("The tree is empty");
    }
    m_data[1] = m_data[m_size--];
    int left = 1, right = left * 2;
    int Max = std::max(m_data[right], m_data[right + 1]);
    while (right <= m_size && Max > m_data[left]) {
        int t = (Max == m_data[right] ? right : right + 1);
        std::swap(m_data[left], m_data[t]);
        left = t;
        right = left * 2;
        Max = std::max(m_data[right], m_data[right + 1]);
    }
}
template<typename T>
void Heap<T>::deallocate() {
    delete[] m_data;
}
