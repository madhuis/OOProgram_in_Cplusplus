#include<iostream>
#include<string>

using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
//*****************************************************************
// FILE: Player.h
// AUTHOR: Ishan Madhu
// LOGON ID: z1763923
// DUE DATE: 02-12-2015
//
// PURPOSE: Contains the declaration for the Player class.

//*****************************************************************
class Player
{
// Data members and method prototypes for the Player class go here
	private:
	//Player instance variable	
	int number; // The player's number (an integer)
	char name[26]; // The player's name (a character array with room for 25 characters PLUS the null character)
	char position[3];// The player's position (a character array with room for 2 characters PLUS the null character)
	int hits;//The player's number of hits (an integer)
	int atBats;// The player's number of times at bat (an integer)
	
	//Player instance method
	public:

	// Default constructor with no parameters.
	Player();

	// alternate player constructor with datatypes.	
	Player(int,char* ,char*, int, int); 

	int getNumber();
	// getNumber() ==> It should return the number data member.
	
	char* getName();
	//getName() ==> It should return the name data member.array's name will convert the name into a pointer to the first element of the array, 
	//which in this case is data type char

	char* getPosition();
	//getPosotion() ==> It should return the Position  data member.

	int getHits(); 
//	getHits()==> This accessor method takes no parameters. It will have a return data type of int. It
//	should return the hits data member.

	int getAtBats();
//	getHits()==> This accessor method takes no parameters. It will have a return data type of int. It
//      should return the Bats  data member.

	void setHits(int);
//	setHits()==>//      setHits()==> This method takes an integer argument, a new number of hits. It returns nothing.

	void setAtBats(int);
//      setAtBats()==> This method takes an integer argument, a new number of Bats. It returns nothing.

	double battingAverage();
//	battingAverage()==> This method takes no arguments. It returns a double number.

	void print();
//	print() This method takes no parameters and returns nothing. The method should print the
//	number, name, position, hits, at bats, and batting average .
	
};
#endif

