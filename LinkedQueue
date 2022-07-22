#pragma once

#include <exception>

template < typename T >
  class Linkedqueue {
    public:
      Linkedqueue();
    Linkedqueue(const Linkedqueue < T > & );
    Linkedqueue < T > & operator = (const Linkedqueue < T > & );
    ~Linkedqueue();
    T & front();
    const T & front() const;
    int size() const {
      return m_size;
    }
    void push(const T & );
    void pop();
    bool is_empty() const {
      return m_size == 0;
    }
    private:
      template < typename T >
      struct Node {
        T m_info;
        Node < T > * m_next;
        Node(const T & info): m_info(info), m_next(nullptr) {}
        Node(const Node < T > & ) = delete;
        Node < T > operator = (const Node < T > & ) = delete;
      };
    void deallocate();
    int m_size;
    Node < T > * m_front;
    Node < T > * m_rear;
  };
template < typename T >
  Linkedqueue < T > ::Linkedqueue(): m_size(0), m_front(nullptr), m_rear(nullptr) {}
template < typename T >
  Linkedqueue < T > ::Linkedqueue(const Linkedqueue < T > & other): m_size(other.m_size), m_front(nullptr), m_rear(nullptr) {
    const Node < T > * p1 = other.m_front;
    Node < T > * p2 = nullptr;
    while (p1 != nullptr) {
      Node < T > * temp = new Node < T > (p1 -> m_info);
      if (p1 == other.m_front) {
        m_front = temp;
      }
      if (p2 != nullptr) {
        p2 -> m_next = temp;
      }
      p2 = temp;
      p1 = p1 -> m_next;
    }
    m_rear = p2;
  }
template < typename T >
  Linkedqueue < T > & Linkedqueue < T > ::operator = (const Linkedqueue < T > & other) {
    if (this != & other) {
      deallocate();
      m_size = other.m_size;
      const Node < T > * p1 = other.m_front;
      Node < T > * p2 = nullptr;
      while (p1 != nullptr) {
        Node < T > * temp = new Node < T > (p1 -> m_info);
        if (p1 == other.m_front) {
          m_front = temp;
        }
        if (p2 != nullptr) {
          p2 -> m_next = temp;
        }
        p2 = temp;
        p1 = p1 -> m_next;
      }
      m_rear = p2;
    }
    return *this;
  }
template < typename T >
  Linkedqueue < T > ::~Linkedqueue() {
    deallocate();
  }
template < typename T >
  const T & Linkedqueue < T > ::front() const {
    if (m_size != 0) {
      return m_front -> m_info;
    }
    throw std::exception("The queue is empty.");
  }
template < typename T >
  T & Linkedqueue < T > ::front() {
    if (!is_empty()) {
      return m_front -> m_info;
    } else {
      throw std::exception("The queue is empty");
    }
  }
template < typename T >
  void Linkedqueue < T > ::push(const T & element) {
    Node < T > * tmp = new Node < T > (element);
    (m_size == 0) ? m_front = tmp: m_rear -> m_next = tmp;
    m_rear = tmp;
    ++m_size;
  }
template < typename T >
  void Linkedqueue < T > ::pop() {
    if (!is_empty()) {
      Node < T > * p1 = m_front -> m_next;
      delete m_front;
      m_front = p1;
      --m_size;
    } else {
      throw std::exception("The queue is empty");
    }
  }
template < typename T >
  void Linkedqueue < T > ::deallocate() {
    if (!is_empty()) {
      Node < T > * p1 = m_front;
      Node < T > * p2 = m_front -> m_next;
      while (is_empty() != 0) {
        delete p1;
        p1 = p2;
        p2 = (m_size != 1) ? p1 -> m_next : nullptr;
        --m_size;
      }
    }
  }
