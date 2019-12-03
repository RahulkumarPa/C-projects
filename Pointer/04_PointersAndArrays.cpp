/** 04_PointersAndArrays.cpp
 *	
 *	Pointers Example Program 03 for OOP 2200. In this example, we will 
 *	explore the relationship between arrays and pointers. 
 *	   
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		24 Feb 2018
 *	@see 		Bronson, G. (2012).  Chapter 8 Arrays and Pointers. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
 *	@see		Pointer and Array Relationship in C++ (6:00)
 *					http://www.youtube.com/watch?v=JZVrkK9oEv8&hd=1	
*/

#include <iostream>
using namespace std;	

int main()
{
	// DECLARATIONS
	const int SIZE = 3;		// number of elements in the same array
	int arrayValues[SIZE] = {11, 22, 33}; // sample array
	
	// OUTPUT
	cout << "Pointers and Arrays" << endl
	     << "===================" << endl;
	     
	cout << "\nARRAY NAME: " << endl;
	// The name of an array is a pointer constant that holds the address of the first 
 	// element of the array.
	cout << "\narrayValues     = " << arrayValues << endl
		 << "&arrayValues[0] = " << &arrayValues[0] << endl;
	
	cout << "\nARRAY NOTATION: " << endl; 	// Array notation: accessing elements 
		 			 		   	 			// using the subscript operator[]
	// loop for each element...
	for(int index = 0; index < SIZE; index++)
	{
		// Display the address and value of each element in the array
		cout << "\n&arrayValues[" << index << "] = " << &arrayValues[index] << endl;
		cout << "arrayValues[" << index << "]  = " << arrayValues[index] << endl;
	}
			 
	cout << "\nPOINTER NOTATION: " << endl; // Pointer notation: accessing elements 
		 			 		   	 			// using address + an offset
	// loop for each element...
	for(int offset = 0; offset < SIZE; offset++)
	{
		cout << "\narrayValues + " << offset << "   = " << arrayValues + offset << endl;
		cout << "*(arrayValues + " << offset << ") = " << *(arrayValues + offset) << endl;
	}
	
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main
