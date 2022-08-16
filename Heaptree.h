#pragma once

#include <exception>

#include <algorithm>

class Heap {
public:
  Heap();
  Heap(const Heap & );
  Heap & operator = (const Heap & );
  ~Heap();

  bool empty() {
    return m_size == 0;
  }
  int size() {
    return m_size;
  }
  const int max() {
    if (!empty()) {
      return m_data[1];
    } 
    else {
      throw std::exception("The tree is empty");
    }
  }
  void remove();
  void insert(int);
private:
    void deallocate();

  static const int Max_size = 30;
  int m_size;
  int m_max_size;
  int * m_data;
};
Heap::Heap(): m_size(0), m_max_size(Max_size), m_data(nullptr) {
  m_data = new int[m_max_size];
}
Heap::Heap(const Heap & other): m_size(other.m_size), m_max_size(other.m_max_size), m_data(nullptr) {
  m_data = new int[m_max_size];
  for (int i = 1; i <= m_size; i++) {
    m_data[i] = other.m_data[i];
  }
}
Heap & Heap::operator = (const Heap & other) {
  if (this != & other) {
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
Heap::~Heap() {
  deallocate();
}
void Heap::insert(int element) {
  if (m_size + 1 == m_max_size) {
    m_max_size *= 2;
    int * data = new int(m_max_size);
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
void Heap::remove() {
  if (empty()) {
    throw std::exception("The tree is empty");
  }
  m_data[1] = m_data[m_size--];
  int left = 1, right = left * 2;
  int Max = std::max(m_data[right], m_data[right + 1]);
  while (right != m_size && Max > m_data[left]) {
    int t = (Max == m_data[right] ? right : right + 1);
    std::swap(m_data[left], m_data[t]);
    left = t;
    right = left * 2;
    Max = std::max(m_data[right], m_data[right + 1]);
  }
}
void Heap::deallocate() {
  delete[] m_data;
}
