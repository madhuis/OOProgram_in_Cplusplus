/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   April 28, 2015

   FUNCTION:   Class declaration/header file for the Shape class
*********************************************************************/

#include <iostream>
using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
  private:
  string color;

  public:
  Shape(const string&);
  virtual ~Shape();
  virtual void print() const;
  virtual double get_area() const = 0;
};
#endif

