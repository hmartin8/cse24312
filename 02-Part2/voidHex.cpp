/**********************************************
* File: voidFunc.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of allocating multiple version of data 
* with different types of elements
*
* Shows void pointers as "Pass by reference"
*
* Lecture 02 - Part 2 - Slide 29
**********************************************/

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

void setNodeValues( void* reference, double theDbl, float theFlt, int theInt ){
	
	// Put a double in the first 64 bits after reference
	*((double *)(reference)) = theDbl;
	
	// Move past 64 bits and put in a float 
	reference += sizeof(double);
	*((float *)(reference)) = theFlt;
	
	// Move past 32 bits and put in an integer
	reference += sizeof(float);
	*((int *)(reference)) = theInt;	
	
}


void printNodeValues( void* reference ){
	
	COUT << "-----------------------------" << ENDL;
	COUT << "Initial address of reference: " << reference << ENDL << ENDL;	
	
	COUT << "Double:  " << *((double *)(reference)) << "\t at address " << reference << ENDL;
	
	reference += sizeof(double);
	COUT << "Float:   " << *((float *)(reference)) << "\t at address " << reference << ENDL;
	
	reference += sizeof(int);
	COUT << "Integer: " << *((int *)(reference)) << "\t at address " << reference << ENDL;
	
	COUT << ENDL;
	COUT << "Final sddress of reference: " << reference << ENDL;	
	
}

int main(void){
	
	long unsigned int nodeSize = sizeof(double) + sizeof(float) + sizeof(int);
	
	void* node1 = malloc( nodeSize );
	
	// Set the node Values for node1 
	setNodeValues( node1, -0x0.ap0, 0x1.ap0, 0x00000083 );
	
	// Printing the values. Set the reference back to numbers
	printNodeValues( node1 );
	
	// Free void* with allocated memory
	free( node1 );

	return 0;
}
