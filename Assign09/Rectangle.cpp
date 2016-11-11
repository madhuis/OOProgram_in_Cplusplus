/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   April 28, 2015

   FUNCTION:   Class implementation for the Rectangle class
*********************************************************************/
#include <iostream>
#include "Rectangle.h"
using namespace std;
/***********************************************************************
   FUNCTION: Rectangle(const string&, int, int)

   USE: It pnitializes the Rectangle object's color, height, and width

   ARGUMENTS:  rectangleColor -  a constant reference to a string
                 representing the color of the rectangle
               h - an integer representing the height of the
                 Rectangle
	       w - an integer representing the width of the
                 Rectangle
************************************************************************/
Rectangle::Rectangle(const string& rectangleColor, int h, int w): Shape(rectangleColor)
{
  height = h;
  width = w;
}
/******************************************************************
   FUNCTION: void print() const

   USE: It prints the color, area, height and width of the rectangle

   ARGUMENTS: None
*******************************************************************/
void Rectangle::print() const
{
  Shape::print();
  cout << " rectangle, height " << height << ", " << "width " << width << ", " << "area " << get_area() << endl;
}
/***************************************************************
   FUNCTION: double get_area() const

   USE: It calculates and returns the area of the rectangle

   ARGUMENTS: None
***************************************************************/
double Rectangle::get_area()const
{
  double area;

  area = width * height;

  return area;
}


