/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   April 28, 2015
 
   FUNCTION:   Class declaration/header file for the Circle class
*********************************************************************/

#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
  private:
  int radius;

  public:
  Circle(const string&, int);
  virtual void print() const;
  virtual double get_area() const;
};
#endif

