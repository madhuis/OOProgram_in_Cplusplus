/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   April 28, 2015

   FUNCTION:   Class implementation for the Circle class
*********************************************************************/
#include <iostream>
#include "Circle.h"
using namespace std;

/***************************************************************
   FUNCTION: Circle(const string&, int)

   USE: To initialize  the Circle object's color and radius

   ARGUMENTS:  circleColor -  a constant reference to a string
              		      representing the color of the circle
                r - an integer representing the radius of the
                    circle.
***************************************************************/
Circle::Circle(const string& circleColor, int r): Shape(circleColor)
{
  radius = r;
}
/***************************************************************
   FUNCTION: void print() const

   USE: It prints the color, radius and area of the circle

   ARGUMENTS: None
***************************************************************/
void Circle::print() const
{
  Shape::print();
  cout << " circle, radius " << radius << ", " << "area " << get_area() << endl;
}

/***************************************************************
   FUNCTION: double get_area() const

   USE: it calculates and returns the area of the circle

   ARGUMENTS: None
***************************************************************/
double Circle::get_area() const
{
  double area;
  const double pi = 3.14159;
  area = pi * radius * radius;

  return area;

}
