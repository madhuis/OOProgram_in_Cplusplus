/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   April 28, 2015

   FUNCTION:   Class declaration/header file for the Triangle class
*********************************************************************/
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include "Shape.h"
using namespace std;

class Triangle : public Shape
{
  private:
  int height;
  int base;

  public:
  Triangle(const string&, int, int);
  virtual void print() const;
  virtual double get_area() const;
};
#endif

