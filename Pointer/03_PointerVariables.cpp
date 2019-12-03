/** 03_PointerVariables.cpp
 *	
 *	Pointers Example Program 03 for OOP 2200. In this example, we will 
 *	assign a pointer an address of one variable, then another.
 *	   
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		24 Feb 2018
 *	@see 		Bronson, G. (2012).  Chapter 8 Arrays and Pointer. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
 *	@see		Pointer Variables in C++ (2:44)
 *					http://www.youtube.com/watch?v=FrVx48FjtYo&hd=1
*/

#include <iostream>
using namespace std;	


int main()
{
	// DECLARATIONS
	int nuts = 88; 	// an example of an integer variable 
	int bolts = 99; // another example of an integer variable 
	int *ptrHardware; // uninitialized pointer! Bad news.
	
	// OUTPUT
	cout << "Pointer Variables" << endl
	     << "=================" << endl;
	     
	//*ptrHardware = 8888; // this may crash to desktop. Why?
	     
	ptrHardware = &nuts;
	cout << "\nPointing at \'nuts\'" << endl
		 << "Value:   " << *ptrHardware << endl
		 << "Address: " << ptrHardware << endl; 
	
	ptrHardware = &bolts;
	cout << "\nPointing at \'bolts\'" << endl
		 << "Value:   " << *ptrHardware << endl
		 << "Address: " << ptrHardware << endl; 
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main
