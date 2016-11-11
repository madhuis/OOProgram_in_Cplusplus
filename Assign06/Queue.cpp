/******************************************************************
   FILE:      Queue.cpp
   AUTHOR:    ISHAN MADHU
   LOGON ID:  z1763923
   DUE DATE:  April 7, 2015
   PURPOSE:   the class definations
******************************************************************/

#include <iostream>
#include <queue>
#include "Queue.h"
#include <stdexcept>
using namespace std;

/***************************************************************
   FUNCTION: Queue()

   USE: To Initialize a Queue object 

   ARGUMENTS: None.
***************************************************************/
Queue::Queue()
{
  qCap = 1;
  qArray = new int[qCap];
  qSize = 0;
  qFront = 0;
  qRear = -1;
}
/***************************************************************
   FUNCTION: ~Queue()

   USE: To delete the dynamic data[destructor].

   ARGUMENTS: None.
***************************************************************/
Queue::~Queue()
{
  delete [] qArray;
}

/***************************************************************
   FUNCTION: Queue(const Queue& other)

   USE:  A Copy Constructor

   ARGUMENTS: other: a constant Queue object
***************************************************************/
Queue::Queue(const Queue & other)
{
  qSize = other.qSize;
  qCap = other.qCap;
  qRear = other.qRear;
  qFront = other.qFront;

  qArray = new int[qCap];


  // To copy contents of dynamic storage.

  for(unsigned i = 0; i < qSize; i++)
  {
	qArray[i] = other.qArray[i];
  }
}
/***************************************************************
   FUNCTION: Queue operator=(const Queue& other)

   USE: As an Assignment Operator

   ARGUMENTS: other: a constant Queue object
***************************************************************/
Queue& Queue::operator=(const Queue & other)
{
  if(this != &other)
  {
    delete [] qArray;
    qSize = other.qSize;
    qCap = other.qCap;
    qRear = other.qRear;
    qFront = other.qFront;
    qArray = new int[qCap];

    for(unsigned i = 0; i < qSize; i++)
    {
      qArray[i] = other.qArray[i];

    }

  }
  return *this;
}
/***************************************************************
   FUNCTION: ostream& operator<<(ostream& leftop, const Queue& rightop)

   USE: Overloads the stream insertion operator

   ARGUMENTS: leftOp: an ostream object
	      rightOp: a constant Queue object
***************************************************************/
ostream & operator<<(ostream & leftOp, const Queue& rightOp)
{
  int current, i;
  for (current = rightOp.qFront, i = 0; i < (int) rightOp.qSize; ++i)
  {
    leftOp << rightOp.qArray[current] << ' ';

    current = (current + 1) % rightOp.qCap;
  }
  return leftOp;
}
/***************************************************************
   FUNCTION: void clear()

   USE: Clears the Queue object

   ARGUMENTS: None.
***************************************************************/
void Queue::clear()
{
  qSize = 0;
  qFront = 0;
  qRear = qCap = -1;
}
/***************************************************************
   FUNCTION: unsigned size()const

   USE: Returns the queue size

   ARGUMENTS: None.
***************************************************************/
unsigned Queue::size()const
{
  return qSize;
}
/***************************************************************
   FUNCTION: unsigned capacity()const

   USE: Returns the queue capacit

   ARGUMENTS: None.
***************************************************************/
unsigned Queue::capacity()const
{
  return qCap;
}
/***************************************************************
   FUNCTION: bool empty()const

   USE: To check the queue is empty or not

   ARGUMENTS: None.
***************************************************************/
bool Queue::empty()const
{
  if (qSize == 0)
	return true;
  else
	return false;
}
/***************************************************************
   FUNCTION: int front()const

   USE: Returns the front part of the queue if not empty

   ARGUMENTS: None.
***************************************************************/
int Queue::front()const
{
  if(empty())
	throw underflow_error("queue underflow on front()");
  else
	return qArray[qFront];
  return qArray[qFront];
}
/***************************************************************
   FUNCTION: int back()const

   USE: Returns the back part of the queue array

   ARGUMENTS: None.
***************************************************************/
int Queue::back()const
{
  if(empty())
        throw underflow_error("queue underflow on back()");
  else
	return qArray[qRear];
  return qArray[qRear];
}
/***************************************************************
   FUNCTION: void push(int)

   USE: To Insert an item in the queue

   ARGUMENTS: item: an integer
***************************************************************/
void Queue::push(int item)
{
  if(qSize == qCap)
    reserve(qCap * 2);

  qRear = (qRear + 1) % qCap;
  qArray[qRear] = item;
  qSize++;
}
/***************************************************************
   FUNCTION: void pop()

   USE: Removes the front item of the queue array

   ARGUMENTS: None.
***************************************************************/
void Queue::pop()
{
  if(empty()) //check if queue is empty
    throw underflow_error("queue underflow on pop()");

  qFront = (qFront + 1) % qCap;
  qSize--;
}
/***************************************************************
   FUNCTION: void reserve(unsigned)

   USE: Reserves an additional capacity for the queue.

   ARGUMENTS:newCap: an unsigned new capacity for the queue
***************************************************************/
void Queue::reserve(unsigned newCap)
{
  int* copyArray = new int[newCap]; 
  int current = qFront; 
  for(unsigned i = 0; i < qSize; i++)
  {
     copyArray[i] = qArray[current];
     current = (current + 1) % qCap;
  }
  qCap = newCap; 
  delete [] qArray;
  qArray = copyArray;
  qFront = 0;
  qRear = qSize - 1;
}
