/** 06_ByAddress.cpp
 *	
 *	Pointers Example Program 06 for OOP 2200. In this example, we will 
 *	compare passing arguments 'by reference' and 'by address' using a 
 *	pointer parameter. In straight C, there are no reference parameters, 
 *  so pass 'by address' is common. 
 *	   
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		24 Feb 2018
 *	@see 		Bronson, G. (2012).  Chapter 8 Arrays and Pointers. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
 *	@see		Passing Arguments to a Function by Address in C++ (5:18)
 *					http://www.youtube.com/watch?v=iH-kkeh5sZs&hd=1
*/

#include <iostream>
#include <iomanip>
using namespace std;	

/**	Swap function
 * 	@param &left - a reference to the value to be swapped 
 * 	@param &right - a reference to the other value to be swapped
*/
void Swap(double &left, double &right);

/**	Swap function
 * 	@param *left - the address of to the value to be swapped
 * 	@param *right - the address of to the other value to be swapped   
*/
void Swap(double *left, double *right);

int main()
{
	// DECLARATIONS
	double valueOne = 88.8;
	double valueTwo = 22.2;
		
	cout << "Passing By Address" << endl
		 << "==================" << endl;
		 
    cout << "\nBefore swapping:\nValueOne = " << valueOne << endl
    	 << "ValueTwo = " << valueTwo << endl;
	
	Swap(valueOne, valueTwo); // passing 'by reference' is 
 				   // NOT evident by the function call argument(s).
					
	cout << "\nAfter swapping:\nValueOne = " << valueOne << endl
    	 << "ValueTwo = " << valueTwo << endl;
    	 
 	Swap(&valueOne, &valueTwo); // passing 'by address' IS 
 				   // evident by the use of the '&' before the argument(s).
	
	cout << "\nAfter re-swapping:\nValueOne = " << valueOne << endl
    	 << "ValueTwo = " << valueTwo << endl;
    
		
	// done.
	cout << endl << endl;
	return 0; 
} // end of main

//	Swap function - by reference
void Swap(double &left, double &right)
{
	// NOT evident in the function body that we are using
	// references. Indirection using references is automatic
	
	double holder = left; // retain the left value in holder
	left = right;		  // set left to right value
	right = holder;		  // set right to holder value
}

//	Swap function - by address
void Swap(double *left, double *right)
{
	// Evident in the function body that we are using
	// pointers. Indirection using pointers is explicit
	
	double holder = *left; // retain the left value in holder
	*left = *right;		  // set left to right value
	*right = holder;		  // set right to holder value
}

