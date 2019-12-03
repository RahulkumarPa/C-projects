/** Vectors_Algorithm.cpp
 *	
 *	Vector Example Program for OOP 2200. In this example, we will 
 *	demonstrate sort(), random_shuffle(), and replace() from <algorithm>.
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
#include <algorithm> // needed for sort(), random_shuffle(), and replace()
#include <vector> // needed for vectors
using namespace std;	

/**	DisplayIntVectorContents function
 *	Displays the contents of a vector<int> to the console window
 *	@param		numbers - the vector<int> to display, passed by const reference
 *	@return		N/A
*/
void DisplayIntVectorContents(const vector<int> &numbers);

int main()
{
		// DECLARATIONS
	vector<int> values {99, 88, 77, 66, 44, 44, 33, 22, 11}; // initialized vector of doubles
 		// Note: This code is C++ 11 Standard only.
		
	// Output an information header
	cout << "<algorithm> Functions" << endl
		 << "=====================" << endl;
	
	// Display the vector as initialized
	cout << "\nThe vector as initialized:  ";
	DisplayIntVectorContents(values);
	
	// TO DO: Shuffle the vector
	
	// Display the shuffled vector
	cout << "\nAfter shuffling the vector: ";
	DisplayIntVectorContents(values);
	
	// TO DO: Sort the vector

	// Display the sorted vector
	cout << "\nAfter sorting the vector:   ";
	DisplayIntVectorContents(values);
	
	// TO DO: Replace 44 with 55

	// Display the sorted vector
	cout << "\nAfter replacing 44 with 55: ";
	DisplayIntVectorContents(values);	

	// done.
	cout << endl << endl;
	return 0;
} // end of main

// DisplayIntVectorContents function definition
void DisplayIntVectorContents(const vector<int> &numbers)
{
	// output the size and content of the vector
	cout << " { ";
		 
	for(int index = 0; index < numbers.size() - 1 ; index++)
	{
		cout << numbers.at(index) << ", ";
	}
	cout << numbers.back() << " }" << endl;
}
