#pragma once
#include <iostream>

#include <vector>

#include <cmath>

class Polynom {
  friend std::ostream & operator << (std::ostream & out,const Polynom & other);
  public:
    typedef std::vector < std::pair < double, int >> Information;
  Polynom();
  Polynom(const Information & );
  Polynom(const Polynom & );
  Polynom & operator = (const Polynom & );
  ~Polynom();

  Polynom & operator += (const Polynom & );
  Polynom & operator *= (const Polynom & );
  Polynom & operator *= (double);

  Polynom & derivative();
  double count_value(double) const;
  void deallocate();
  private:
    struct Node {
      double m_coefficient;
      int m_exponent;
      Node * m_next;

      Node(double coefficient, int exponent): m_coefficient(coefficient), m_exponent(exponent), m_next(nullptr) {}
      Node(const Node & ) = delete;
      Node & operator = (const Node & ) = delete;
    };
  int m_exponent;
  Node * m_head;
};
Polynom operator + (Polynom,const Polynom & );
Polynom operator * (Polynom,const Polynom & );
Polynom operator * (Polynom,const double);

