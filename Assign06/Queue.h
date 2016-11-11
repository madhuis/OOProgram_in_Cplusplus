/******************************************************************
   FILE:      Queue.h
   AUTHOR:    ISHAN MADHU
   LOGON ID:  z1763923
   DUE DATE:  April 7, 2015
   PURPOSE:   the class declaration for the Queue
******************************************************************/
#include<iostream>
#include <stdexcept>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H
class Queue
{
  friend ostream & operator<<(ostream&, const Queue&);

  private:
  int* qArray;
  unsigned int qCap;
  unsigned int qSize;
  int qFront;
  int qRear;

  public:
  Queue();
  ~Queue();
  Queue(const Queue&); 
  Queue& operator=(const Queue&);
  void clear();
  unsigned size()const;
  unsigned capacity()const;
  bool empty()const;
  int front()const;
  int back()const;
  void push(int);
  void pop();
  void reserve(unsigned);
};
#endif

