/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   April 28, 2015

   FUNCTION:   This program tests the shape classes made using
               inheritance and polymorphism.
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <iomanip>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

int main()
{
  // Create a vector of pointers to Shape objects
  vector <Shape *> shapes;

  // Dynamically create Circles, Rectangles, and Triangles
  Circle* c1 = new Circle("green", 10);
  Rectangle* r1 = new Rectangle("red", 8, 6);
  Triangle* t1 = new Triangle("yellow", 8, 4);
  Triangle* t2 = new Triangle("black", 4, 10);
  Circle* c2 = new Circle("orange", 5);
  Rectangle* r2 = new Rectangle("blue", 3, 7);

  // Add each object to the vector
  shapes.push_back(c1);
  shapes.push_back(r1);
  shapes.push_back(t1);
  shapes.push_back(t2);
  shapes.push_back(c2);
  shapes.push_back(r2);

  // Loop through the vector of  Shape pointers and print them
  cout << "Printing all shapes..." << endl;
  cout << endl;
  for(unsigned i = 0; i < shapes.size(); i++)
  {
     shapes[i]->print();
  }
  cout << endl;

  // Loop through the vector of Shape pointers again and print only the Triangle objects
  cout << "Printing only triangles..." << endl;
  cout << endl;
  for(unsigned i = 0; i < shapes.size(); i++)
  {
     Triangle* triPtr = dynamic_cast<Triangle *>(shapes[i]);
     if (triPtr != NULL)
     {
         triPtr -> print();
     }
  }

  // Loop through the vector of shape pointers and delete each object
  for(unsigned i = 0; i < shapes.size(); i++)
  {
    delete shapes[i];
  }

  return 0;
}


