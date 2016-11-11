#include "Player.h"
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <cstring>
using namespace std;

// Deafult constructor
// does not return datatype.
Player::Player()
{
	// This method should set the name and position data members to a "null string"
	// The number, hits, and at bats data members should be set to 0.
	number=0;
	strcpy(name,"");
	strcpy(position,"");
	hits=0;
	atBats=0;
}


// parametrarized constructor
// does not return datatype.

Player::Player(int newNumber,char* newName,char* newposition, int newHits, int newAtBats)
{
/*Write
another constructor for the Player class that takes five parameters: 
1) an integer that contains a new number, 2) a character array that contains a new name. 
3) a character array that contains a new position, 4) an integer that contains a new number of hits, and 
5) an integer that contains a new number of times at bat.

Also,

*/
	number=newNumber;
// strcpy() to copy the the new name parameter into the name data member and the new position parameter into the position data member.
	strcpy(name,newName);
	strcpy(position,newposition);
//  the setHits() and setAtBats() methods to set the hits and at bats data members to the new hits and new at bats passed into the constructor.
	setHits(newHits);
//	hits=newHits;
	setAtBats(newAtBats);
	//atBats=newAtBats;
	
}


//this Method is used to get the value of the number variable
// return number

int Player::getNumber()
{
	return number;
}

/*
*this Method is used to get the value of the name variable
* return name
*/
char* Player::getName()
{
	return name; 
//returning an array's name will convert the name into a pointer to the first element of the array, which in this case is data type char.
}

/*
*this Method is used to get the value of the position variable
* return pasition
*/

char* Player::getPosition()
{
 	return position;
//  It should return Position data.
}


/**
*this Method is used to get the value of the hits variable
* return number of hits
*/

int Player::getHits()
{
	return hits;
} 

/*
*this Method is used to the get value of the Atbats variable
* return number of bats
*/

int Player::getAtBats()
{
	return atBats;
}

/**
*this Method is used to the set the value of the hits variable
*if the value is >=0 then set to new value
*else set to 0
* param: int 
*/


void Player::setHits(int newHits)
{
	if(newHits>=0)
	{
		hits=newHits;
	}
	else
	{
		hits=0;
	}
}

/**
*this Method is used to the set the value of the Atbats variable
*if the value is >=0 then set to new value
*else set to 0
*param: int 
*/


void Player::setAtBats(int newAtBats)
{
	if(newAtBats>=0)
	{
		atBats=newAtBats;
	}
	else
		atBats=0;
}

/**
*this Method is used for calculation of bating average 
*It can throw divide by zero exception
*so check denominator first and if this is zero then return -1
*else return hits/atBats;
*/

double Player::battingAverage()
{
	if(atBats==0)
	{
		return -1;
	}
	return (double)hits/atBats;
	
}

/**
*this Method is used for printing of data separated by space.
*/


void Player::print()
{	cout << setw(4) << left << getNumber();
	cout << setw(27)  << left  << getName();
	cout << setw(5) << left << getPosition();
	cout << setw(3) << right<<getHits();
	cout << setw(5) << right<<getAtBats();
	cout << setw(7)<<right;
	if(battingAverage()==-1)
	{
	
		cout << " -\n";
	}
	else
	{
		cout << setprecision(3) << fixed;
		cout << battingAverage() << endl;
	}
  
}

















