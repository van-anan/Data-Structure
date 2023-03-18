#pragma once

#include <exception>

template < typename T >
  class LinkedList {
    public:
      template < typename T1 >
      struct Node {
        T1 m_info;
        Node < T1 > * m_next;
        Node < T1 > * m_previous;
        Node(T1 info): m_info(info), m_next(nullptr), m_previous(nullptr) {}
        Node(const Node < T1 > & ) = delete;
        Node < T1 > & operator = (const Node < T1 > & ) = delete;
      };
    public:
      LinkedList();
    LinkedList(const LinkedList < T > & );
    LinkedList(T * , int);
    LinkedList < T > & operator = (const LinkedList < T > & );
    ~LinkedList();
    void insert(const T & , int);
    void remove(int);
    T & head() const {
      return m_head -> m_info;
    }
    int size() const {
      return m_size;
    }
    void deallocate();

    private:
      Node < T > * m_head;
    int m_size;
  };
template < typename T >
  LinkedList < T > ::LinkedList(): m_size(0), m_head(nullptr) {}
template < typename T >
  LinkedList < T > ::LinkedList(const LinkedList < T > & other): m_size(other.m_size), m_head(nullptr) {
    if (m_size != 0) {
      int size = m_size - 1;
      Node < T > * tmp = new Node < T > (other.m_head -> m_info);
      m_head = tmp;
      Node < T > * pointer1 = other.m_head -> m_next;
      while (size != 0) {
        Node < T > * new_tmp = new Node < T > (pointer1 -> m_info);
        tmp -> m_next = new_tmp;
        new_tmp -> m_previous = tmp;
        tmp = new_tmp;
        pointer1 = pointer1 -> m_next;
        --size;
      }
    }
  }
template < typename T >
  LinkedList < T > ::LinkedList(T * data, int size): m_size(size), m_head(nullptr) {
    Node < T > * first = new Node < T > (data[0]);
    m_head = first;
    for (int i = 1; i < size; i++) {
      Node < T > * p1 = new Node < T > (data[i]);
      first -> m_next = p1;
      p1 -> m_previous = first;
      first = p1;
    }
  }
template < typename T >
  LinkedList < T > & LinkedList < T > ::operator = (const LinkedList & other) {
    if ((other.m_size != 0) && (this != & other)) {
      deallocate();
      m_size = other.m_size;
      int size = m_size - 1;
      Node < T > * tmp = new Node < T > (other.m_head -> m_info);
      m_head = tmp;
      Node < T > * pointer1 = other.m_head -> m_next;
      while (size != 0) {
        Node < T > * new_tmp = new Node < T > (pointer1 -> m_info);
        tmp -> m_next = new_tmp;
        new_tmp -> m_previous = tmp;
        tmp = new_tmp;
        pointer1 = pointer1 -> m_next;
        --size;
      }
    }
    return *this;
  }
template < typename T >
  LinkedList < T > ::~LinkedList() {
    deallocate();
  }
template < typename T >
  void LinkedList < T > ::insert(const T & element, int index) {
    if (index <= 0) {
      throw std::exception("wrong index");
    }
    if (index > m_size + 1) {
      index = m_size + 1;
    }
    Node < T > * new_tmp = new Node < T > (element);
    if (index == 1) {
      if (m_size != 0) {
        new_tmp -> m_next = m_head;
        m_head -> m_previous = new_tmp;
      }

      m_head = new_tmp;
      m_size++;
      return;
    }

    Node < T > * tmp = m_head;
    for (int i = 1; i < index - 1; i++) {
      tmp = tmp -> m_next;
    }
    if (index == m_size + 1) {
      new_tmp -> m_previous = tmp;
      tmp -> m_next = new_tmp;
      m_size++;
      return;
    }
    Node < T > * ptr1 = tmp -> m_next;
    tmp -> m_next = new_tmp;
    new_tmp -> m_previous = tmp;
    new_tmp -> m_next = ptr1;
    ptr1 -> m_previous = new_tmp;
    m_size++;

  }
template < typename T >
  void LinkedList < T > ::remove(int index) {
    if (index <= 0) {
      throw std::exception("Index is out of range");
    }
    if (m_size == 0) {
      throw std::exception("The list is empty");
    }
    if (index > m_size + 1) {
      index = m_size;
    }
    Node < T > * p1 = m_head;
    if (index == 1) {
      if (m_size != 1) {
        m_head -> m_next -> m_previous = nullptr;
        m_head = m_head -> m_next;
      }
      delete p1;
      m_size--;
      return;
    }
    for (int i = 1; i < index; i++) {
      p1 = p1 -> m_next;
    }
    if (m_size == index) {

      p1 -> m_previous -> m_next = nullptr;
      delete p1;
      m_size--;
      return;
    }
    p1 -> m_next -> m_previous = p1 -> m_next;
    p1 -> m_previous -> m_next = p1 -> m_next;
    delete p1;
    m_size--;

  }
template < typename T >
  void LinkedList < T > ::deallocate() {
    if (m_size != 0) {
      Node < T > * p1 = m_head;
      Node < T > * p2 = m_head -> m_next;
      while (m_size != 0) {
        delete p1;
        p1 = p2;
        if (m_size == 1) {
          p2 = nullptr;
        } else {
          p2 = p2 -> m_next;
        }
        --m_size;

      }
    }
  }
