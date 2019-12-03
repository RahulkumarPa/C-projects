/** 01_VariableElements.cpp
 *	
 *	Pointers Example Program 01 for OOP 2200. In this example, we will 
 *	examine the major elements of a variable.
 *	   
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		24 Feb 2018
 *	@see 		Bronson, G. (2012).  Chapter 8 Arrays and Pointer. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
 *  @see		Major Elements of a C++ Variable (3:28) 
 *					http://www.youtube.com/watch?v=tzR3P0Is-X8&hd=1
*/

#include <iostream>
using namespace std;	


int main()
{
	// DECLARATIONS
	int wholeNumber = 22; 			// an example of an integer variable 
	double realNumber = 4.54321; 	// an example of a double variable 
	
	// OUTPUT
	cout << "Elements of a C++ Variable" << endl
	     << "==========================" << endl;
	
	cout << "\nMajor elements of the variable \'wholeNumber\'" << endl
		 << "=============================================" << endl
		 << "Size:    " << sizeof(wholeNumber) << " bytes." << endl
		 << "Value:   " << wholeNumber << endl
		 << "Address: " << &wholeNumber << endl; // '&' is the address operator
	
	cout << "\nMajor elements of the variable \'realNumber\'" << endl
		 << "=============================================" << endl
		 << "Size:    " << sizeof(realNumber) << " bytes." << endl
		 << "Value:   " << realNumber << endl
		 << "Address: " << &realNumber << endl; // '&' is the address operator
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main
