/** 07B_PointerArithmetic2.cpp
 *	
 *	Pointers Example Program 7B for OOP 2200. In this example, we will 
 *	use a pointer parameter to pass an array to a function.
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
#include <iomanip> // for output formatting
using namespace std;	

/**	AverageOfArray function
 *	@param		*ptrValues - pointer to an array of ints
 *	@param		SIZE - the size of the array
 *	@return		the average value of the array
*/
double AverageOfArray(int *ptrValues, const int SIZE);

int main()
{
	// DECLARATIONS
	const int SIZE = 5;  // 'Companion' to the array
	int values[SIZE] = {11, 22, 34, 45, 56};
	
	cout << "Pointer Arithmetic" << endl
		 << "==================" << endl
		 << fixed << setprecision(1);

	// Final output. Display the average.
	cout << "\nThe average is " 
		 << AverageOfArray(values, SIZE) << endl;
		 
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	AverageOfArray function
double AverageOfArray(int *ptrValues, const int SIZE)
{
	int sumOfValues = 0;
	const int *END = ptrValues + SIZE; // one address beyond the end
		  		 	  			  		  // of the array 
	
	// while the address has not reached the end address
	while(ptrValues < END) // pointer arithmetic!
	{
		// add this element value to the sum
		sumOfValues += *ptrValues++;
	}
	
	// calculate the average by dividing the sum by the size
	return (double) sumOfValues / SIZE;
}

