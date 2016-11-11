/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: ISHAN MADHU
   LOGON ID:   z1763923
   DUE DATE:   April 21, 2015
   FUNCTION:   template functions implemented to read a series
	       of items from an input file and then print the items.
*********************************************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
#ifndef SORTS_H
#define SORTS_H

template <class T> void buildList(vector<T>&, const char*);
template <class T> void printList(const vector<T>&, int, int);
template <class T> bool lessThan(const T&, const T&);
template <class T> bool greaterThan(const T&, const T&);

/*******************************************************************************************
   FUNCTION: template <class T> void buildList(vector<T>& const char*)

   USE: This Function use to read items from an input file and puts them in a vector

   ARGUMENTS: set - a reference to a vector<T> object
              fileName - a C-style string containing the full pathname of the input file
********************************************************************************************/
template<class T>
void buildList(vector<T>& set, const char* fileName)
{
  T item;
  ifstream inFile;

  inFile.open(fileName);
  if(!inFile)
  {
     cout << "Error, file did not open. " << endl;
  }
  inFile >> item;
  while(inFile)
  {
    set.push_back(item);
    inFile >> item;
  }
  inFile.close();
}

/**************************************************************************************************************
   FUNCTION: template <class T> void printList(const vector<T>&, int, int)

   USE: THis Function uses to print a list of stored items in a vector

   ARGUMENTS: set - a reference to a const vector<T> object
              itemWidth - an integer representing the width an individual item should occupy
	      numPerLine - an integer specifying the maximum number of items that should be printed per line
***************************************************************************************************************/
template<class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
  int i = 0;
  while(i < (int) set.size())
  {
     cout << setw(itemWidth) << set[i] << ' ';
     i++;
     if(i % numPerLine == 0)
       cout << endl;
  }

  if (i % numPerLine != 0)
     cout << endl;

}

/******************************************************************
   FUNCTION: template <class T> bool lessThan(const T&, const T&)

   USE: This Function returns true if item 1 <  item 2, false if not

   ARGUMENTS:  item1 - a reference to a constant T object
               item2 - a reference to a constant T object
******************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
  return (item1 < item2);
}

/******************************************************************
   FUNCTION: template <class T> bool greaterThan(const T&, const T&)

   USE: THis Function returns true if item 1 > item 2, false if not

   ARGUMENTS:  item1 - a reference to a constant T object
               item2 - a reference to a constant T object
******************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
  return (item1 > item2);
}
#endif
