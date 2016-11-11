/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   April 28, 2015

   FUNCTION:   Class declaration/header file for the Rectangle class
*********************************************************************/

#include <iostream>
#include "Shape.h"
#include <string>

using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle : public Shape
{
  private:
  int height;
  int width;

  public:
  Rectangle(const string&, int, int);
  virtual void print() const;
  virtual double get_area() const;

};
#endif


