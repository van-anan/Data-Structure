#include "Polynom.h"
std::ostream & operator << (std::ostream & out,const Polynom & other) {
  Polynom::Node * ptr = other.m_head -> m_next;
  while (ptr != other.m_head) {
    if (ptr -> m_coefficient != 1) {
      std::cout << ptr -> m_coefficient;
    }
    std::cout << "x^" << ptr -> m_exponent;
    if (ptr -> m_next != other.m_head) {
      std::cout << " + ";
    }
    ptr = ptr -> m_next;
  }
  std::cout << std::endl;
  return out;
}
Polynom::Polynom(): m_exponent(-1), m_head(nullptr) {
  m_head = new Node(0, -1);
  m_head -> m_next = m_head;
}
Polynom::Polynom(const Information & other): m_exponent(-1), m_head(nullptr) {
  m_head = new Node(0, -1);
  m_head -> m_next = m_head;
  Node * prev = m_head, * ptr = nullptr;
  for (unsigned int i = 0; i < other.size(); ++i) {
    ptr = new Node(other[i].first, other[i].second);
    prev -> m_next = ptr;
    prev = prev -> m_next;
  }
  if (ptr != nullptr) {
    ptr -> m_next = m_head;
    m_exponent = other[0].second;
  }
}
Polynom::Polynom(const Polynom & other): m_exponent(other.m_exponent), m_head(nullptr) {
  m_head = new Node(0, -1);
  m_head -> m_next = m_head;
  Node * ptr = m_head;
  Node * prev = other.m_head -> m_next, * tmp = nullptr;
  while (prev != other.m_head) {
    tmp = new Node(prev -> m_coefficient, prev -> m_exponent);
    ptr -> m_next = tmp;
    ptr = tmp;
    prev = prev -> m_next;
  }
  if (tmp != nullptr) {
    tmp -> m_next = m_head;
  }
}
Polynom & Polynom::operator = (const Polynom & other) {
  if (this != & other) {
    deallocate();
    m_exponent = other.m_exponent;
    m_head = new Node(0, -1);
    m_head -> m_next = m_head;
    Node * ptr = m_head;
    Node * prev = other.m_head -> m_next, * tmp = nullptr;
    while (prev != other.m_head) {
      tmp = new Node(prev -> m_coefficient, prev -> m_exponent);
      ptr -> m_next = tmp;
      ptr = tmp;
      prev = prev -> m_next;
    }
    if (tmp != nullptr) {
      tmp -> m_next = m_head;
    }
  }
  return *this;
}
Polynom::~Polynom() {
  deallocate();
}
Polynom & Polynom::operator += (const Polynom & other) {
  Node * prev = m_head;
  Node * this_current = m_head -> m_next;
  Node * other_current = other.m_head -> m_next;
  while (other_current != other.m_head) {
    if (this_current -> m_exponent == other_current -> m_exponent) {
      this_current -> m_coefficient += other_current -> m_coefficient;
      if (this_current -> m_coefficient == 0) {
        prev -> m_next = this_current -> m_next;
        delete this_current;
        this_current = prev;
      }
      prev = this_current;
      this_current = this_current -> m_next;
      other_current = other_current -> m_next;
    } else if (this_current -> m_exponent < other_current -> m_exponent) {
      Node * tmp = new Node(other_current -> m_coefficient, other_current -> m_exponent);
      tmp -> m_next = this_current;
      prev -> m_next = tmp;
      prev = tmp;
      other_current = other_current -> m_next;
    } else {
      prev = this_current;
      this_current = this_current -> m_next;
    }
  }
  this_current = m_head -> m_next;

  while (this_current != m_head) {
    Node * ptr1 = this_current;
    Node * ptr = this_current -> m_next;
    while (ptr != m_head) {

      if (this_current -> m_exponent == ptr -> m_exponent) {
        this_current -> m_coefficient += ptr -> m_coefficient;
        ptr1 -> m_next = ptr -> m_next;
        delete ptr;
        ptr = ptr1 -> m_next;
      } else {
        ptr = ptr -> m_next;
        ptr1 = ptr1 -> m_next;
      }
    }
    this_current = this_current -> m_next;
  }
  m_exponent = m_head -> m_next -> m_exponent;
  return *this;
}
Polynom & Polynom::operator *= (const Polynom & object) {
  Polynom y;
  const Node * pointer1 = object.m_head -> m_next;
  Node * pointer2 = m_head -> m_next;
  while (pointer1 != object.m_head) {
    Polynom x;
    Node * pointer3 = x.m_head;
    while (pointer2 != m_head) {
      double coefficient = pointer1 -> m_coefficient * pointer2 -> m_coefficient;
      int exponent = pointer1 -> m_exponent + pointer2 -> m_exponent;
      Node * tmp = new Node(coefficient, exponent);
      tmp -> m_next = x.m_head;
      pointer3 -> m_next = tmp;
      pointer3 = tmp;
      pointer2 = pointer2 -> m_next;
    }
    y += x;
    pointer1 = pointer1 -> m_next;
    pointer2 = m_head -> m_next;
  }
  m_exponent = y.m_exponent;
  return *this = y;
}
Polynom & Polynom::operator *= (const double k) {
  Node * current = m_head -> m_next;
  while (current != m_head) {
    current -> m_coefficient *= k;
    current = current -> m_next;

  }
  return *this;
}
Polynom & Polynom::derivative() {
  Node * current = m_head -> m_next;
  Node * prev = m_head;
  while (current != m_head) {
    if (current -> m_exponent == 0) {
      Node * ptr = current -> m_next;
      delete current;
      prev -> m_next = ptr;
      current = ptr;
      continue;
    }
    current -> m_coefficient *= current -> m_exponent--;
    prev = current;
    current = current -> m_next;
  }
  --m_exponent;
  return *this;
}
double Polynom::count_value(double k) const {
  double sum = 0;
  Node * current = m_head -> m_next;
  while (current != m_head) {
    sum += current -> m_coefficient * pow(k, current -> m_exponent);
    current = current -> m_next;
  }
  return sum;
}
void Polynom::deallocate() {
  Node * current = m_head -> m_next, * ptr = m_head -> m_next;;
  while (current != m_head) {
    current = current -> m_next;
    delete ptr;
    ptr = current;
  }
  delete m_head;
}
Polynom operator + (Polynom P1,const Polynom & P2) {
  return P1 += P2;
}
Polynom operator * (Polynom P1,const Polynom & P2) {
  return P1 *= P2;
}
Polynom operator * (Polynom P1,const double k) {
  return P1 *= k;
}
