/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   April 21, 2015
   FUNCTION:   A template functions use to sort a list of items using
	       the recursive quick sort algorithm.
*********************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#ifndef QUICKSORT_H
#define QUICKSORT_H

template <class T> void quickSort(vector <T>&, bool(*) (const T&, const T&));
template <class T> void quickSort(vector <T>&, int, int, bool(*) (const T&, const T&));
template <class T> int partition(vector <T>&, int, int, bool(*) (const T&, const T&));

/*******************************************************************************************
   FUNCTION: template <class T> void quickSort(vector<T>&, bool (*) (const T&, const T&))

   USE: It Sorts items in the vector set using the quick sort algorithm

   ARGUMENTS: set - a reference to a vector<T> object
              compare - a boolean pointer to a comparison function
********************************************************************************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare) (const T&, const T&))
{
  quickSort(set, 0, set.size() - 1, compare);
}

/*******************************************************************************************
   FUNCTION: template <class T> void quickSort(vector<T>&, int, int, bool (*) (const T&, const T&))

   USE: It performs the recursive calls to implement the quick sort algorithm

   ARGUMENTS: set - a reference to a vector<T> object
              start - an integer representing the first vector element
	      end - an integer representing the last vector element
	      compare - a boolean pointer to a comparison function
********************************************************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool(*compare) (const T&, const T&))
{
  int pivotPoint;
  if(start < end)
  {
     pivotPoint = partition(set, start, end, compare); 
     quickSort(set, start, pivotPoint - 1, compare);  
     quickSort(set, pivotPoint + 1, end, compare);   
  }
}

/*******************************************************************************************
   FUNCTION: template <class T> int partition(vector<T>&, int, int, bool (*) (const T&, const T&))

   USE: This Function use to selects a pivot element and then partitions the vector around the pivot

   ARGUMENTS: set - a reference to a vector<T> object
              start - an integer representing the first vector element
              end - an integer representing the last vector element
              compare - a boolean pointer to a comparison function
********************************************************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare) (const T&, const T&))
{
  int pivotIndex;
  int  mid;
  T pivotValue;
  T temp;

  mid = (start + end) / 2;

  temp = set[start];
  set[start] = set[mid];
  set[mid] = temp;

  pivotIndex = start;
  pivotValue = set[start];

  for(int scan = start + 1; scan <= end; scan++)
  {
    if(compare(set[scan], pivotValue))
    {
       pivotIndex++;

       temp = set[pivotIndex];
       set[pivotIndex] = set[scan];
       set[scan] = temp;
    }
  }

  temp = set[start];
  set[start] = set[pivotIndex];
  set[pivotIndex] = temp;

  return pivotIndex;
}
#endif

