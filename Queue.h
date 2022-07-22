#include<iostream>

#include <exception>

class queue {
  public:
    queue();
  queue(const queue & );
  queue & operator = (const queue & );
  ~queue();
  bool is_empty() const {
    return m_front == -1;
  }
  int size() const {
    if (m_rear <= m_front) return m_max_size - m_front + m_rear;
    else {
      if ((m_rear == m_max_size) && (m_front != m)) return m_rear - m_front;
      else {
        return m_rear;
      }

    }
  }
  int front() const;
  void push(int);
  void pop();
  void print() {
    for (int i = 0; i < size(); i++) {
      std::cout << m_data[i] << std::endl;
    }
  }
  public:
    int m_front;
  int m_rear;
  int * m_data;
  int m_max_size;
  const static int max_size = 6;
  int m = 0;

};
queue::queue(): m_front(-1), m_rear(0), m_data(nullptr), m_max_size(max_size) {
  m_data = new int[m_max_size];
}
queue::queue(const queue & other): m_front(other.m_front), m_rear(other.m_rear), m_max_size(other.m_max_size) {
  m_data = new int[m_max_size];
  for (int i = 0; i < m_max_size; i++) {
    m_data[i] = other.m_data[i];
  }
}
queue & queue::operator = (const queue & other) {
  delete[] m_data;
  m_front = other.m_front;
  m_rear = other.m_rear;
  m_max_size = other.m_max_size;
  m_data = new int[m_max_size];
  for (int i = 0; i < size() + m_front; i++) {
    m_data[i] = other.m_data[i];
  }
  return *this;
}
queue::~queue() {
  delete[] m_data;
}
int queue::front() const {
  if (!is_empty()) {
    return m_front;
  } else {
    throw std::exception("The queue is empty");
  }
}
void queue::push(int element) {

  if (size() == m_max_size) {

    m_max_size *= 2;
    int * tmp = new int[m_max_size];
    for (int i = 0; i < size(); i++) {
      tmp[i] = m_data[i];
    }
    delete[] m_data;
    m_data = tmp;
    m_rear = m_max_size / 2;
    m_front = 0;
    m = 0;
  }
  if (size() == 1) {
    m_front = 0;
  }

  if (m_rear != m_max_size) {
    m_data[m_rear] = element;
    m_rear++;
  } else if (m_front != m) {
    m_rear = m;
    m_data[m_rear] = element;
    m++;
    m_rear++;
  }

}

void queue::pop() {
  if (!is_empty()) {
    m_data[m_front] = NULL;
    m_front++;

  }
  if(m_front==m_max_size){
    m_front=0;
  }
  else {
    throw std::exception("The queue is empty");
  }
}/*
int main() {
  queue a;
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);

  try {
    a.pop();
  } catch (const std::exception & t) {
    std::cout << t.what();
  }

  a.push(7);
  a.push(8);
  a.push(9);
  a.push(10);
  try {
    a.pop();
  } catch (const std::exception & t) {
    std::cout << t.what();
  }
  a.push(11);
  a.push(12);
  a.push(13);
  a.push(14);
  a.push(15);
  a.pop();
  a.push(16);
  a.push(17);
  queue b;
  b = a;
  b.print();

}*/
