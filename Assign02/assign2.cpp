/****************************************************************
   PROGRAM:   Chicago White Sox Roxter [Assignment No: 2]
   AUTHOR:    Ishan Madhu
   LOGON ID:  Z1763923
   DUE DATE:  02/12/2015
   FUNCTION:  This assignment reviews object-oriented programming concepts such as classes, methods, constructors, accessor methods, and access modifiers.
              It makes use of an array of objects as a class data member, and introduces the concept of object serialization or "binary I/O".


   INPUT:    Playerfile, gaames.txt file etc.

   OUTPUT:    	./assign2

****************************************************************/
#include <iostream>
#include <iomanip> // Use to manipulate 
#include <string> // USe some strings in this main function.
#include <fstream> // For open/close files.
#include "Team.h" // we have to include Team.h to open that header file.
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

//main method
int main()
{

 	Team t("playerdata"); // Open Playerdata file call in a main function.
	t.sortByName();// To arrange data by name for output in a main function.
	t.print(); // To print an output call in a main function.
	
	
	
	 cout<<"----------------"<<endl;
	 t.updateStats("gamestats.txt"); // to call in a main function
	 t.print(); // // To print an output call in a main funct ion

	return 0;
}


