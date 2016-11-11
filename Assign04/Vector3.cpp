// Class descripton

#include "Vector3.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/***************************************************************
   FUNCTION: Vector3 (float, float, float)

   USE: Initialize the data members to zero (0)

   ARGUMENTS: x, y, z : floating point numbers
***************************************************************/
Vector3::Vector3(float x, float y, float z)
{
  arr[0] = x;
  arr[1] = y;
  arr[2] = z;
}
/***************************************************************
   FUNCTION: operator <<(ostream&, const Vector3&)

   USE: << "overload" operator to send the class object to standard output

   ARGUMENTS: a. os: an ostream data member
              b. v: const class object
***************************************************************/
ostream& operator<<(ostream & os, const Vector3 & v)
{
  os << " ( " << v[0] << " , " << v[1] << " , " << v[2] << " ) ";
  return os;
}
/***************************************************************
   FUNCTION: operator +(const Vector3 v) const

   USE: Adds component of the operands in a vector

   ARGUMENTS: v: a const class object
***************************************************************/
// [temp_vector =  (Answer of the performed operation]

Vector3 Vector3::operator +(const Vector3 v) const
{
  Vector3 temp_vector;
  temp_vector[0] +=  v[0];
  temp_vector[1] +=  v[1];
  temp_vector[2] +=  v[2];
  return temp_vector;
}
/***************************************************************
   FUNCTION: operator -( const Vector3 v) const

   USE: Subtracts the components of the operands in a vector

   ARGUMENTS: v: a const class object ***************************************************************/ 
Vector3 Vector3::operator -(const Vector3 v) const
{

  Vector3 temp_vector;
  temp_vector[0] -= v[0];
  temp_vector[1] -= v[1];
  temp_vector[2] -= v[2];
  return temp_vector;
}
/***************************************************************
   FUNCTION: float operator *(const Vector3&v) const

   USE: Multiplies the vector

   ARGUMENTS:  v: a const class object
***************************************************************/
float Vector3 :: operator*(const Vector3& v) const
{
  Vector3 tempVector = *this;
  float temp_vector = 0;
  temp_vector += tempVector[0] * v[0];
  temp_vector += tempVector[1] * v[1];
  temp_vector += tempVector[2] * v[2];
  return temp_vector;
}
/***************************************************************
   FUNCTION: Vector3 operator*(const Vector3&)

   USE: Multiplies the vector

   ARGUMENTS: 1. v: floating point value
***************************************************************/
Vector3 Vector3:: operator*(float v)
{
  Vector3 temp_vector;

  temp_vector[0] *= v;
  temp_vector[1] *= v;
  temp_vector[2] *= v;
  return temp_vector;
}

/***************************************************************
   FUNCTION: Vector3 operator *(float os, const Vector3& v)

   USE: Multiplies the vector

   ARGUMENTS: v: const class object
***************************************************************/

Vector3 operator*(float os, const Vector3& v)
{
  Vector3 temp_vector = v;
  temp_vector[0] *= os;
  temp_vector[1] *= os;
  temp_vector[2] *= os;
  return temp_vector;
}
/********************************************************************************
   FUNCTION: operator [](int)

   USE: To Overload the subscript operator to accessor methods for the class.


   ARGUMENTS: Here, i = an integeer
**********************************************************************************/
float Vector3 :: operator [](int i) const
{
  return arr[i];
}
/**********************************************************************************


   FUNCTION: operator [](int)

   USE: To Overload the subscript operator to  accessor methods for the class

   ARGUMENTS: i: an integer value
**********************************************************************************/
float & Vector3 :: operator [](int i)
{
  return arr[i];
}
/***************************************************************
   FUNCTION: operator == (Vector3 & v) const

   USE: Compare the equality

   ARGUMENTS: v:  const class object
***************************************************************/

bool Vector3::operator==(const Vector3 & v) const
{
	if (arr[0] == v[0] && arr[1] == v[1] && arr[2] == v[2])
		return true;
	else
		return false;

}

