#ifndef TEAM_H
#define TEAM_H
#include "Player.h"
//*****************************************************************
// FILE: Team.h
// AUTHOR: Ishan Madhu
// LOGON ID: z1763923
// DUE DATE: 02/12/15
//
// PURPOSE: Contains the declaration for the Team class.

//*****************************************************************

// Declaration of class
class Team
{
// Data members and method prototypes for the Player class go here
	private:
	// Declaration of Private 
	Player playerList[40]; //An array of 40 Player objects
	int numObject; // An integer that specifies the number of Player objects actually stored in the array
	
	// Declaration of Public
	public:
	Team();// This "default" constructor for the Team class takes no parameters so no return values.
	Team(const char*); // Alternate Team constructor
	void sortByName(); 
// 	sortByName()==> This method takes no parameters and returns nothing.
	
	int searchForName(char*);
//	This method should take one parameter: a character array containing the name of the Player to
//	search for (searchName). The method should return an integer
	
	void print();// This method takes no parameters and returns nothing
	
	void updateStats(const char*);
// 	updateStats()==> This method should take one parameter: a pointer to a constant character (that points to an array of
//	characters containing the name of a file of game statistics). The method should return nothing.
	
};
#endif

