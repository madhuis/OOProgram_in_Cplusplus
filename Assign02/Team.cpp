#include "Team.h"
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;


/**
* default constructor
*/
Team::Team()
{
	numObject=0; // the number of books data member to 0.
}

/**
* param constructor
* used for reading data from binary file
* and store each line to player object
*/
Team::Team(const char* teamdb)
{
    	ifstream inFile; // Clearly declared inputfile variable
	inFile.open(teamdb,ios::binary); // Open the file stream for binary input
	//  Check the failing condition.
	if(inFile.fail())
	{
		cout << "Can not open the file\n";
		exit(1);
	}
	numObject=0;
	inFile.read((char*)&playerList[numObject],sizeof(Player)); //Read the database file into your Team object.
	while(inFile) // Loop  to read input file variables.
	{
		numObject++; // increment operator to read next details in the file.
		inFile.read((char*)&playerList[numObject],sizeof(Player));
	}
	inFile.close(); // close the file.

}


/**
* this method is used for sorting of player objects aacording to player name
*/
void Team::sortByName()
{
	int i, j;
	Player bucket; // change the data type of bucket to Player.

	for(i=1;i<numObject;i++)
	{
		bucket = playerList[i];
		for(j=i;(j > 0) && strcmp(playerList[j-1].getName(), bucket.getName()) > 0 ;j--)
			playerList[j] = playerList[j-1];
		playerList[j] = bucket;
	}
}

/**
* this method is used for printing of player objects
*/
void Team::print()
// This should print couple of header lines and it does not return any value.
{
	cout<<"CHICAGO WHITE SOX ROSTER"<<endl;
	cout << setw(4) << left << "NO";
	cout << setw(27)  << left  << "NAME";
	cout << setw(5) << left <<"POS";
	cout << setw(3) <<right<< "H";
	cout << setw(5) <<right<< "AB";
	cout << setw(7)<<right<<"AVG"<<endl;
        for (int i = 0; i < numObject; i++)
        {
        	playerList[i].print();
        }
}


/**
* this method is used for serching of player object
*/
int Team::searchForName(char* name)
{
   int low = 0;
   int high = numObject - 1;
   int mid;
   int cond=0;
   while (low <= high)
   {
      mid = (low + high) / 2;
      cond=strcmp(playerList[mid].getName(),name);
      if (cond==0){
         return mid;
		}
      if (cond>0){
       high = mid - 1;
 	 }
      else{
        low = mid + 1;
    	}
      }

   return -1;
}

/**
* this method is used for update the player from the file
*/
void Team:: updateStats(const char* fileName){
	
	ifstream inFile;
	inFile.open(fileName);
	if(inFile.fail())
		{
		cout << "Can not open the game file\n";
		exit(1);
		}
	string  line;
	char fname[12];
	char lName[11];
	int hits;
	int abats;
	char fullname[26]; // Big enough to hold both name and lastname
    getline(inFile,line);
    cout<<line<<endl;
	inFile >> fname;cout << setw(27)  << left  << "NAME";
	cout << setw(3) <<right<< "H";
	cout << setw(5) <<right<< "AB"<<endl;
	while(inFile)
		{
		inFile >> lName;
		inFile >> hits;
		inFile >> abats;
		fullname[0] = '\0';       // strcat searches for '\0' to cat after
  		strcat ( fullname, lName );     // Copy name into full name
  		strcat ( fullname, ", " );      // We want to separate the names by a space
  		strcat ( fullname, fname ); // Copy lastname onto the end of fullname
		int index=searchForName(fullname);
		if(index!=-1){
			cout << setw(27)  << left  << fullname;
			cout << setw(3) << right<<hits;
			cout << setw(5) << right<<abats<<endl;
			playerList[index].setHits(playerList[index].getHits() + hits);
			playerList[index].setAtBats(playerList[index].getAtBats() + abats);
		}
		else{
			cout<<"Error - player named Fake, Total does not exist"<<endl;
		}
		inFile >> fname;
		}	
		inFile.close();

}
