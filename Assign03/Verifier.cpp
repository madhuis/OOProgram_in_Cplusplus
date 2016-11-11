/*********************************************************************
PROGRAM: Verifier.cpp
PROGRAMMER: Ishan Madhu
LOGON ID: z1763923
DUE DATE: 2/27/2015
FUNCTION: This program implements the Verifier class.
*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "Verifier.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream ;

/****************************************************************

   FUNCTION:   Verifier()

   ARGUMENTS:  none

   RETURNS:    none

   NOTES:      set all of the elements of the grid array to 0.
****************************************************************/
Verifier::Verifier() 
{
    /* set all elements to 0 */
    for(int i=0;i<9;i++)
	for(int j=0;j<9;j++)
	    grid[i][j] = 0;
}

/****************************************************************

   FUNCTION:   void readGrid(const char *)

   ARGUMENTS:  filename, name of the file to read string from

   RETURNS:    none

   NOTES:       read the contents of the input file into
   		the elements of the grid array
****************************************************************/
void Verifier::readGrid(const char* filename) 
{
    ifstream inputFile(filename); /* open file for reading */
    string temp; /* temp variable for reading input into */

    /* taking input and storing into grid */
    for(int i=0; i<9; i++)
    {
	for(int j=0;j<9;j++)
	{
	    inputFile >> temp;
	    /* store first character of temp input as char in grid */
	    grid[i][j] = temp[0];
	}
    }

    /* close inputfile */
    inputFile.close();    
}

/****************************************************************

   FUNCTION:   void printGrid()

   ARGUMENTS:  none

   RETURNS:    none

   NOTES:      print the Sudoku grid array to
   		the screen as 9 rows of 9 columns
****************************************************************/
void Verifier::printGrid() 
{
    /* printing grid in fancy form */
    
    for(int i=0;i<9;i++)
    {
	/* print row separator every 3 rows */
	if(i%3 == 0)
	     cout<<"-------------------------"<<endl;

	for(int j=0;j<9;j++)
	{
	    /* print column separator every 3 columns */
	    if(j%3 == 0)
		cout<<"| ";
		
	    /* print element */
	    cout<<grid[i][j]<<" ";
	}
	/* print last column separator */
	cout<<"|"<<endl;
    }

    /* print last row separator */
    cout<<"-------------------------"<<endl;
	
}

/****************************************************************

   FUNCTION:   bool verifySolution()

   ARGUMENTS:  none

   RETURNS:    true is solution is correct, else false

   NOTES:      checks if solution is correct.
****************************************************************/
bool Verifier::verifySolution() 
{
    /* check each row */
    for(int i= 0;i<9;i++)
    {
	/* if a row fails, return false */
	if(!checkRow(i))
	    return false;
    }

    /* check each column */
    for(int i= 0;i<9;i++)
    {
	/* if a column fails, return false */
	if(!checkColumn(i))
	    return false;
    }

    /* check each subgrid */
    for(int i= 0;i<9;i++)
    {
	/* if a subgrid fails, return false */
	if(!checkSubgrid(i))
	    return false;
    }

    /* if all pass, then correct solution */
    return true;
}

/****************************************************************

   FUNCTION:   bool checkRow(int)

   ARGUMENTS:  row, index of row to check if correct

   RETURNS:    true is row is correct, else false

   NOTES:      checks if row is correct.
****************************************************************/
bool Verifier::checkRow(int row) 
{
    /* let presence of all numbers be false */
    bool isPresent[9] = {false};

    /* check if a number repeats, then return false */
    for(int i=0;i<9;i++)
    {
	/* get index in boolean array */
	int index = grid[row][i] - '1';
	/* if index already present, number repeats
	 * so return false */
	if(isPresent[index])
	    return false;

	/* else set number to be present */
	isPresent[index] = true;
    }
    /* if all pass, then correct solution */
    return true;
}

/****************************************************************

   FUNCTION:   bool checkColumn(int)

   ARGUMENTS:  col, index of column to check if correct

   RETURNS:    true is column is correct, else false

   NOTES:      checks if column is correct.
****************************************************************/
bool Verifier::checkColumn(int col) 
{
    /* let presence of all numbers be false */
    bool isPresent[9] = {false};

    /* check if a number repeats, then return false */
    for(int i=0;i<9;i++)
    {
	/* get index in boolean array */
	int index = grid[i][col] - '1';
	/* if index already present, number repeats
	 * so return false */
	if(isPresent[index])
	    return false;

	/* else set number to be present */
	isPresent[index] = true;
    }
    /* if all pass, then correct solution */
    return true;
}

/****************************************************************

   FUNCTION:   bool checkSubgrid(int)

   ARGUMENTS:  num, index of subgrid (0-8) to check if correct

   RETURNS:    true is subgrid is correct, else false

   NOTES:      checks if subgrid is correct.
****************************************************************/
bool Verifier::checkSubgrid(int num) 
{
    /* let presence of all numbers be false */
    bool isPresent[9] = {false};

    /* calculate starting index of subgrid */
    int startRow = (num/3)*3;
    int startCol = (num%3)*3;

    /* check if a number repeats, then return false */
    for(int i=0;i<3;i++)
    {
	for(int j=0;j<3;j++)
	{
	    /* get index in boolean array */
	    int index = grid[startRow+i][startCol+j] - '1';
	    /* if index already present, number repeats
	     * so return false */
	    if(isPresent[index])
		return false;

	    /* else set number to be present */
	    isPresent[index] = true;
	}
    }
    /* if all pass, then correct solution */
    return true;
    
}

    
