/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Ishan Madhu
   LOGIN ID:   z1763923
   LOGON ID:   z1670789
   DUE DATE:   April 28, 2015

   FUNCTION:   Class implementation for the Shape class
*********************************************************************/
#include <iostream>
#include "Shape.h"
using namespace std;
/***************************************************************
   FUNCTION: Circle(const string&, int)

   USE: To initializes the Shape object's color

   ARGUMENTS: shapeColor -  a constant reference to a string
                            representing the color of the shape
***************************************************************/
Shape::Shape(const string& shapeColor)
{
  color = shapeColor;
}
/***************************************************************
   FUNCTION: ~Shape()

   USE: destructor

   ARGUMENTS: None
***************************************************************/
Shape::~Shape()
{

}
/***************************************************************
   FUNCTION: void print() const

   USE: It prints the Shape color

   ARGUMENTS: None
***************************************************************/
void Shape::print() const
{
  cout << color;
}

