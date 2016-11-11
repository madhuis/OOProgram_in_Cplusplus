/***********************************************************
NAME: ISHAN MADHU
DATE: MARCH 27th, 2015
PROGRAM: VectorN.cpp
USE: Class header file (VectorN.h).
************************************************************/

#include <iostream>
#include <stdexcept>
using namespace std;

#ifndef VECTORN_H
#define VECTORN_H

class VectorN
{
  friend ostream & operator<<(ostream &, const VectorN &);
  friend VectorN operator*(double, const VectorN&);

public:

  VectorN();
  VectorN(double, unsigned int);
  ~VectorN();
  VectorN(const VectorN&);
  VectorN(double[], unsigned int);
  VectorN &operator=(VectorN&);
  void clear();
  unsigned size()const;
  VectorN operator+(const VectorN&)const;
  VectorN operator-(const VectorN&)const;
  double operator*(const VectorN&)const;
  VectorN operator*(double)const;
  double operator[](int)const;
  double & operator[](int);
  double at(int)const throw(out_of_range);
  double& at(int) throw (out_of_range);
  bool operator==(const VectorN &)const;

private:

  unsigned int arySize;
  double* ary;

};
#endif

