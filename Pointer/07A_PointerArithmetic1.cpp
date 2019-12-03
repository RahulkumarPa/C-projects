/** 07A_PointerArithmetic1.cpp
 *	
 *	Pointers Example Program 7A for OOP 2200. In this example, we will 
 *	use 'pointer arithmetic' to process an array.  
 *	   
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		24 Feb 2018
 *	@see 		Bronson, G. (2012).  Chapter 8 Arrays and Pointers. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
 *	@see		Pointer Arithmetic in C++ (7:00)
 *					http://www.youtube.com/watch?v=tUQvCkdhKOg&hd=1	
*/

#include <iostream>
#include <iomanip>
using namespace std;	

int main()
{
	// DECLARATIONS
	const int SIZE = 5;  // 'Companion' to the array
	int values[SIZE] = {11, 22, 34, 45, 56};
	
	int *ptrValues = NULL; // initialized to NULL at this point
	int sumOfValues = 0; // a sum of the grades to calculate the average
	
	cout << "Pointer Arithmetic" << endl
		 << "==================" << endl
		 << fixed << setprecision(1);
	
	// Assign the starting address to the pointer
	ptrValues = values; 
	// ptrValues = &values[0]; // same
	
	// while the address held by ptrValues is < the end address
	// end address is values (starting address) + SIZE (number of elements)   
	
	while(ptrValues < values + SIZE)
	{
		cout << endl << ptrValues << " - " << *ptrValues;
	
		sumOfValues += *ptrValues++;  // *ptrValues gets the value, 
					// then ptrValues++ moves to the next element
	}
	// output the average
	cout << "\n\nThe average value was: " << (double) sumOfValues/SIZE << endl;
		
	// done.
	cout << endl << endl;
	return 0; 
} // end of main
