#include <iostream>

#include <exception>

template < typename T >
  class Stack {
    public:
      Stack();
    Stack(const Stack < T > & );
    Stack < T > & operator = (const Stack < T > & );
    ~Stack();
    T & top() const;
    bool is_empty() const;
    int size() const;
    void push(T);
    void pop();
    private:
      T * m_data;
    int m_top;
    int m_max_size;
    static
    const int max_size = 100;
  };
template < typename T >
  Stack < T > ::Stack(): m_data(nullptr), m_top(-1), m_max_size(max_size) {
    m_data = new T[m_max_size];
  }
template < typename T >
  Stack < T > ::Stack(const Stack & other) {
    m_max_size = other.m_max_size;
    m_top = other.m_top;
    m_data = new T[m_max_size];
    for (int i = 0; i < m_max_size; i++) {
      m_data[i] = other.m_data[i];
    }

  }
template < typename T >
  Stack < T > & Stack < T > ::operator = (const Stack < T > & other) {
    delete[] m_data;
    m_max_size = other.m_max_size;
    m_top = other.m_top;
    for (int i = 0; i < m_max_size; i++) {
      m_data[i] = other.m_data[i];
    }
    return *this;
  }
template < typename T >
  Stack < T > ::~Stack() {
    delete[] m_data;
  }
template < typename T >
  T & Stack < T > ::top() const {
    if (!is_empty()) {
      return m_data[m_top];
    }
	else{
	    throw std::exception("The array is empty");
	  }
  }
template < typename T >
  bool Stack < T > ::is_empty() const {
    return m_top == -1;
  }
template < typename T >
  int Stack < T > ::size() const {
    return m_top + 1;
  }
template < typename T >
  void Stack < T > ::push(T element) {
    if (m_top + 1 == m_max_size) {
      m_max_size *= 2;
      T * tmp = new T[m_max_size];
      for (int i = 0; i < m_top; i++) {
        tmp[i] = m_data[i];
      }
      delete[] m_data;
      m_data = tmp;
    }
    m_top++;
    m_data[m_top] = element;
  }
template < typename T >
  void Stack < T > ::pop() {
    if (!is_empty()) {
      --m_top;
    } else {
      throw std::exception("The  stack is empty");
    }

  }
