/***********************************************************
  FILE: Vector3.h
  AUTHOR: Ishan Madhu
  LOGON ID: z1763923
  DUE DATE: March 20th, 2015

  PURPOSE: declaration for the Vector3 Class
************************************************************/
#include <iostream>

using namespace std;


#ifndef VECTOR_H
#define VECTOR_H

class Vector3
{

  friend ostream & operator<<(ostream &, const Vector3 &);
  friend Vector3 operator*(float, const Vector3&);

private:

  float arr[3];

public:

  Vector3(float x = 0.0,float y = 0.0, float z = 0.0);
  Vector3 operator+(const Vector3) const;
  Vector3 operator-(const Vector3) const;

  Vector3 operator*(float);
  float operator*(const Vector3&)const;

  float operator[](int) const;
  float & operator[](int);
  bool operator==(const Vector3 &) const;

};
#endif

