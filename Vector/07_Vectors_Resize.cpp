/** Vectors_Resize.cpp
 *	
 *	Vector Example Program for OOP 2200. In this example, we will 
 *	explore resizing a vector.
 *   
 *	@author		Thom MacDonald
 *	@version	2018.02
 *	@since		3 Mar 2018
 *	@see		Vector – C++ Reference. (n.d.). In Cplusplus.com. 
 *				   Retrieved 21 Jan 2018 from 
 *				   http://www.cplusplus.com/reference/vector/vector/ 
*/

#include <iostream>
#include <iomanip> // for output formatting
#include <vector> // needed for vectors
using namespace std;	

/**	DisplayIntVectorInfo function
 *	Displays the size, capacity and contents of a vector<int> to the console window
 *	@param		numbers - the vector<int> to display, passed by const reference
 *	@return		N/A
*/

// TO DO: Create a function definition DisplayIntVectorInfo with 
// a vector constant that passes a value by reference


int main()
{
		// DECLARATIONS
	vector<int> values {11, 22, 33}; // initialized vector of doubles
 		// Note: This code is C++ 11 Standard only.
		
	// Output an information header
	cout << "Resizing Vectors" << endl
		 << "================" << endl;
	
	// display the initial vector
	DisplayIntVectorInfo(values);
	
	// TO DO: Resize the vector to 5 elements

	// display the resized vector
	cout << "\nAfter resizing to 5 elements: ";
	DisplayIntVectorInfo(values);

	// TO DO: Resize the vector to 7 elements filled with 88

	// display the resized vector
	cout << "\nAfter resizing to 7 elements, filled with \'88\': ";
	DisplayIntVectorInfo(values);
	
	// TO DO: Resize the vector to 2 elements

	// display the resized vector
	cout << "\nAfter resizing to 2 elements: ";
	DisplayIntVectorInfo(values);
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main

// DisplayIntVectorInfo function definition
void DisplayIntVectorInfo(const vector<int> &numbers)
{
	// output the size and content of the vector
	cout << "\nSize: " << numbers.size() 
		 << " Capacity: " << numbers.capacity() 
		 << endl << " { ";
		 
	for(int index = 0; index < numbers.size() - 1 ; index++)
	{
		cout << numbers.at(index) << ", ";

	}
	cout << numbers.back() << " }" << endl;
}
