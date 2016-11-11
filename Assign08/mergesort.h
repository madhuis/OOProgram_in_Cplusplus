/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Ishan Madhu
   LOGON ID:   z1763923
   DUE DATE:   April 21, 2015
   FUNCTION:   sort a list of items using the recursive merge sort algorithm
*********************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#ifndef MERGESORT_H
#define MERGESORT_H

template <class T> void mergeSort(vector<T>&, bool (*) (const T&, const T&));
template <class T> void mergeSort(vector<T>&, int, int, bool (*) (const T&, const T&));
template <class T> void mergeSort(vector<T>&, int, int, int, bool(*) (const T&, const T&));

/**********************************************************************************************
   
   FUNCTION: template <class T> void mergeSort(vector<T>&, bool (*) (const T&, const T&))

   USE: It sorts  items in the vector set using the merge sort algorithm & calls the recursive
   merge sort function.

   ARGUMENTS: Here  set - a reference to a vector<T> object
              	    compare - a boolean pointer to a comparison function
***********************************************************************************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare) (const T&, const T&))
{
  mergeSort(set, 0, set.size() - 1, compare);
}
/***************************************************************************************************
   FUNCTION: template <class T> void mergeSort(vector<T>&, int, int, bool (*) (const T&, const T&))

   USE: It divides a vector into two subvectors, sorts them, and then merges the two sorted subvectors

   ARGUMENTS:Here, set - a reference to a vector<T> object
	           low - an integer representing the lower element in the vector
	           high - an integer representing the higher element in the vector
                   compare - a boolean pointer to a comparison function
*****************************************************************************************************/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool(*compare) (const T&, const T&))
{
  int mid;

  if (low < high)
  {
    mid = (low + high) / 2;

    mergeSort(set, low, mid, compare);
    mergeSort(set, mid + 1, high, compare);

    mergeSort(set, low, mid, high, compare);
  }
}

/***************************************************************************************************
   FUNCTION: template <class T> void mergeSort(vector<T>&, int, int, bool (*) (const T&, const T&))

   USE: Here, It divides a vector into two subvectors, sorts them, and then merges the two sorted subvectors

   ARGUMENTS:  set - a reference to a vector<T> object
               low - an integer representing the lower element in the vector
               mid - an integer representing the middle element of two vectors
               high - an integer representing the higher element in the vector
               compare - a boolean pointer to a comparison function
*****************************************************************************************************/
template <class T>
void mergeSort(vector<T>& set, int low, int mid, int high, bool(*compare) (const T&, const T&))
{
  vector<T> temp(high - low + 1);

  int i = low;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= high)
  {
     if(compare(set[j],set[i]))
       temp[k++] = set[j++]; 
     else
       temp[k++] = set[i++]; 
  }



  while(i <= mid)
    temp[k++] = set[i++]; 

  while(j <= high)
    temp[k++] = set[j++]; 

  for(i = 0, j = low; j <= high; i++, j++) 
    set[j] = temp[i];
}
#endif

