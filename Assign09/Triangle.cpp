/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   April 28, 2015

   FUNCTION:   Class implementation for the Triangle class
*********************************************************************/
#include <iostream>
#include "Triangle.h"
using namespace std;
/***********************************************************************
   FUNCTION: Triangle(const string&, int, int)

   USE: It Initializes the Triangle object's color, height, and base

   ARGUMENTS:  triangleColor -  a constant reference to a string
              			representing the color of the triangle
              h - an integer representing the height of the
                  Triangle
              b - an integer representing the bese of the
                  Triangle
************************************************************************/
Triangle::Triangle(const string& triangleColor, int h, int b): Shape(triangleColor)
{
  height = h;
  base = b;
}
/******************************************************************
   FUNCTION: void print() const

   USE: Prints the color, area, height and base of the triangle

   ARGUMENTS: None
*******************************************************************/
void Triangle::print() const
{
  Shape::print();
  cout << " triangle, " << "height " << height << ", " << "base " << base << ", area " << get_area() << endl;
}
/***************************************************************
   FUNCTION: double get_area() const

   USE: Calculates and returns the area of the triangle

   ARGUMENTS: None
***************************************************************/
double Triangle::get_area()const
{
  double area;
  area = .5 * base * height;
  return area;
}

