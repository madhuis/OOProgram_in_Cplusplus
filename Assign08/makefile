#
# PROGRAM:    Assign 8
# PROGRAMMER: Ishan Madhu
# LOGON ID:   z1763923
# DATE DUE:   April 21, 2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign8: assign8.o 
	g++ $(CCFLAGS) -o assign8 assign8.o

# Rules to compile source code files to object code
assign8.o: assign8.cpp sorts.h quicksort.h mergesort.h
	g++ $(CCFLAGS) -c assign8.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8

