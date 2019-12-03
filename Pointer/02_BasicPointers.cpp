/** 02_BasicPointers.cpp
 *	
 *	Pointers Example Program 02 for OOP 2200. A pointer is a data 
 * 	type whose value is a memory address of another item stored 
 *	elsewhere in memory. Pointers can 'point to' data, or they can
 *	also be used to 'point to' functions. In this example, we will 
 *	declare a pointer, assign it an address, and access the value it 
 *  points to using indirection.
 *
 *	   
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		24 Feb 2018
 *	@see 		Bronson, G. (2012).  Chapter 8 Arrays and Pointers. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
 *	@see		Basic Pointers in C++ (5:10)
 *					http://www.youtube.com/watch?v=xidAIphru94&hd=1
*/

#include <iostream>
using namespace std;	


int main()
{
	// DECLARATIONS
	int wholeNumber = 22; 			// an example of an integer variable 
	
	// type *
	int *ptrNumber = &wholeNumber; // a pointer to an int, initialized 
								   // to the address of another variable
	
	// OUTPUT
	cout << "Basic Pointers" << endl
	     << "==============" << endl;
	     
	cout << "\nMajor elements of the variable \'wholeNumber\'" << endl
		 << "=============================================" << endl
		 << "Size:    " << sizeof(wholeNumber) << " bytes." << endl
		 << "Value:   " << wholeNumber << endl
		 << "Address: " << &wholeNumber << endl; // I call '&' the 'address of' operator
	
	cout << "\nMajor elements of the variable \'ptrNumber\'" << endl
		 << "=============================================" << endl
		 << "Size:                      " << sizeof(ptrNumber) << " bytes." << endl
		 << "Value (address stored):    " << ptrNumber << endl
		 << "Address (of the pointer):  " << &ptrNumber << endl; 
		 
	// '*' is the indirection operator it 'indirectly' accesses the value
	// of wholeNumber by looking up the address. I call it the 'value at' operator.
	cout << "Value pointed to (lookup): " << *ptrNumber << endl; 
		 
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main
