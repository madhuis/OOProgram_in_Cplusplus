/***********************************************************
NAME: ISHAN MADHU
DATE: MARCH 27th, 2015
PROGRAM: VectorN.cpp
USE: FUNCTION DECLARATION OF FUNCTION HEADER(VectorN.h).
ARGUMENTS: SHOWN AND DEFINED ABOVE THE FUNCTION.
************************************************************/

#include "VectorN.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;


/***************************************************************
   FUNCTION: VectorN::VectorN()
   USE: Keep data.
   ARGUMENTS: No Arguments .
***************************************************************/

VectorN::VectorN()
{
  arySize = 0;
  ary = NULL;
}

/******************************************************************
   FUNCTION: VectorN::VectorN(double[] ary[], unsigned size)
   USE: Copies values into the vector and hold the number.
   ARGUMENTS: ary[]: an array of double values
	      size: the size of unsigned integers in the
        	     array of double values.
******************************************************************/

VectorN::VectorN(double arr[], unsigned size)
{
  arySize = size;
  ary = new double [size];
  for (unsigned i = 0; i < size; i++)
	ary[i] = arr[i];
}

/***************************************************************
   FUNCTION: VectorN::~VectorN()
   USE: destructor
   ARGUMENTS: No Arguments.
***************************************************************/

VectorN::~VectorN()
{
  delete [] ary;
}

/***************************************************************
   FUNCTION: VectorN::VectorN(const VectorN& other)
   USE: Copy constructor
   ARGUMENTS: &other: a constant object
***************************************************************/ 

VectorN::VectorN(const VectorN& other)
{
  arySize = other.arySize;

  ary = new double [other.arySize];

  for(unsigned i = 0; i < arySize; i++)
	 ary[i] = other.ary[i];
}

/***************************************************************
   FUNCTION:VectorN& VectorN:: VectorN operator=(VectorN& other)
   USE: Overloads the assignment operator
   ARGUMENTS: &other: a &object
***************************************************************/

VectorN& VectorN::operator=(VectorN & other)
{
  if(this != &other)
  {
     delete [] ary;
     arySize = other.arySize;
     ary = new double[arySize];
     for(unsigned i = 0; i < arySize; i++)
     {
	 ary[i] = other.ary[i];
     }
 }
  return *this;
}

/***************************************************************
   FUNCTION: ostream& operator<<(ostream & leftOperator, const VectorN & rightOperator)
   USE: Overloads the stream insertion operator
   ARGUMENTS: &leftOperator: an ostream object
	      &rightOperator: a constant VectorN object
***************************************************************/

ostream& operator<<(ostream & leftOperator, const VectorN & rightOperator)
{
  int i;
  leftOperator << " ( ";
  for (i = 0; i < (int) rightOperator.arySize - 1; ++i)
  {
        leftOperator << rightOperator.ary[i] << " , ";
  }
  if ( i < (int) rightOperator.arySize)
           leftOperator << rightOperator.ary[i];
  leftOperator << " ) ";
  return leftOperator;
}
/***************************************************************
   FUNCTION: void VectorN::clear()
   USE: Sets it back to vector of zero elements.
   ARGUMENTS: no arguments
***************************************************************/

void VectorN::clear()
{
  arySize = 0;
}

/***************************************************************
   FUNCTION: unsigned VectorN:: size() const
   USE: Returns the size of the vector.
   ARGUMENTS: no arguments
**************************************************************/

unsigned  VectorN::size() const
{
  return arySize;
}

/***************************************************************
   FUNCTION: VectorN VectorN::operator+(const VectorN&) const
   USE: Overloads the addition operator
   ARGUMENTS: &rightOperator: a constant object
***************************************************************/

VectorN VectorN::operator+(const VectorN & rightOperator)const
{
  VectorN result;
  if (arySize < rightOperator.arySize) 
  {
	result.arySize = arySize;
  }
  else
  {
	result.arySize = rightOperator.arySize;
  }
  result.ary = new double[result.arySize];
  for (unsigned i = 0; i < result.arySize; i++) 
	result.ary[i] = ary[i] +  rightOperator.ary[i];
  return result;
}

/***************************************************************
   FUNCTION: VectorN VectorN::operator-(const VectorN&)const
   USE: Overloads the subtraction operator
   ARGUMENTS: &rightOp: a constant object
***************************************************************/

VectorN VectorN::operator-(const VectorN & rightOperator)const
{
  VectorN result;
  if (arySize < rightOperator.arySize)
        result.arySize = arySize;
  else
        result.arySize = rightOperator.arySize;
  result.ary = new double[result.arySize];
  for(unsigned i = 0; i < result.arySize; i++)
	result.ary[i] = ary[i] - rightOperator.ary[i];
  return result;
}

/***************************************************************
   FUNCTION: double VectorN:operator*(const VectorN&)
   USE: Overloads the multplication operator
   ARGUMENTS: &rightOperator: a constant object
***************************************************************/

double VectorN::operator*(const VectorN& rightOperator)const
{
  double result = 0;
  unsigned elements;
  if (arySize < rightOperator.arySize)
        elements = arySize;
  else
        elements = rightOperator.arySize;

  for (unsigned i = 0; i < elements; i++)
  result += ary[i] * rightOperator.ary[i];
  return result;
}

/***************************************************************
   FUNCTION: VectorN  VectorN::operator*(double) const
   USE: Overloads the multiplication operator
   ARGUMENTS: rightOperator: a double rightOperator operator
***************************************************************/

VectorN VectorN::operator*(double rightOperator)const
{
  VectorN result = *this;
  for (unsigned i = 0; i < result.arySize; i++)
  	result.ary[i] *= rightOperator;
  return result;
}

/***************************************************************
   FUNCTION: VectorN operator*(double, const VectorN&)
   USE: Overloads the assignment operator
   ARGUMENTS: leftOperator: a double leftOperator operator
              rightOperator: a constant object
***************************************************************/

VectorN operator*(double leftOperator, const VectorN& rightOperator)
{
  VectorN result = rightOperator;
  for (unsigned i = 0; i < result.arySize; i++)
	result.ary[i] *= leftOperator;
  return result;
}

/***************************************************************
   FUNCTION: double VectorN::operator[](int temp) const
   USE: Overloads operator to get a value
   ARGUMENTS: int temp: an integer vector size value 
***************************************************************/

double VectorN::operator[](int temp)const
{
  return ary[temp];
}

/***************************************************************
   FUNCTION: double& VectorN::operator[](int temp)
   USE: Overloads operator to set the value
   ARGUMENTS: int temp: an integer vector size value
***************************************************************/

double& VectorN::operator[](int temp)
{
  return ary[temp];
}

/***************************************************************
   FUNCTION: double VectorN::at(int sub_value) const throw(out_of_range)
   USE:  error checking for the subscript operator
   ARGUMENTS: 1. int sub_value: subscript value
***************************************************************/

double VectorN::at(int sub_value) const throw(out_of_range)
{
  if( sub_value < 0 || sub_value >= (int) arySize)
	throw out_of_range("subscript is out of range");
	return ary[sub_value];
}

/***************************************************************
   FUNCTION: double& VectorN :: at(int sub_value) throw (out_of_range)
   USE:  error checking for the subscript operator
   ARGUMENTS: sub_value: integer subscript value
***************************************************************/

double& VectorN::at(int sub_value) throw(out_of_range)
{
  if( sub_value < 0 || sub_value >= (int) arySize)
	throw out_of_range("subscript is out of range");
	return ary[sub_value];
}

/***************************************************************
   FUNCTION: bool VectorN::operator==(const VectorN& rightOp)const
   USE: = Overload equality operator
   ARGUMENTS: 1. rightOperator: a constant operator
***************************************************************/

bool VectorN::operator==(const VectorN& rightOperator)const
{
  if (arySize != rightOperator.arySize)
	return false;
  else
  	return (ary[0] == rightOperator[0] && ary[1] == rightOperator[1] && ary[2] == rightOperator[2]);
}

