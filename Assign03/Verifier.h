/****************************************************************
   FILE:      Verifier.h
   AUTHOR:    Ishan Madhu
   LOGON ID:  Z1763923
   DUE DATE:  02/27/2015

   PURPOSE:   The functions for the verifier program
****************************************************************/

#ifndef VERIFIER_H_
#define VERIFIER_H_

class Verifier 
{
	private:
		char grid[9][9];
		//private functions to check rows, columns and subgrid
		bool checkRow(int);
		bool checkColumn(int);
		bool checkSubgrid(int);
	public:
		Verifier();
		void readGrid(const char *);
		void printGrid();
		bool verifySolution();
};
#endif /* VERIFIER_H_ */
