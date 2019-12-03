/** Vectors_Modifying.cpp
 *	
 *	Vector Example Program for OOP 2200. In this example, we will 
 *	modify vector content using .insert(), .erase(), and .clear()
 *  as well as pass a vector to a function.
 *
 *   
 *	@author		Thom MacDonald
 *	@version	2018.02
 *	@since		3 Mar 2018
 *	@see		Vector – C++ Reference. (n.d.). In Cplusplus.com. 
 *				   Retrieved 21 Jan 2018 from 
 *				   http://www.cplusplus.com/reference/vector/vector/ 
*/

#include <iostream>
#include <cstdlib> // for system()
#include <iomanip> // for output formatting
#include <vector> // needed for vectors
using namespace std;	

/**	DisplayIntVector function
 *	Displays the contents of a vector<int> to the console window
 *	@param		numbers - the vector<int> to display, passed by const reference
 *	@return		N/A
*/

void DisplayIntVector(const vector<int> &numbers);

int main()
{
	// DECLARATIONS
	vector<int> values {11, 22, 33}; // initialized vector of doubles
 		// Note: This code is C++ 11 Standard only.
	    // I specified "-std=c++11" in my compiler options to make this work.
		
	// Output an information header
	cout << "Modifying Vectors" << endl
		 << "=================" << endl;
	
	// Display the vector as initialized
	cout << "\nThe vector as initialized contains ";
	DisplayIntVector(values);
	
	// TO DO: Insert 2 numbers into the vector at the 2nd position and the 2nd last position
    vlues.insert(valuees.begin()+1,88);
    vlues.insert(valuees.end()-1,100);
	
	// Display the vector after inserts
	cout << "\nAfter inserts, the vector contains ";
	DisplayIntVector(values);
	//system("pause"); // pause the output
	
	// TO DO: Erase the first element and the last 2 elements
    values.erase(values.begin());
    values.erase(values.end()-2, values.end());
	// Display the vector after inserts
	cout << "\nAfter erases, the vector contains ";
	DisplayIntVector(values);
	//system("pause"); // pause the output
	
	// Delete all elements in the vector
	values.clear();
	// Display the vector after clear
	cout << "\nAfter clear, the vector contains ";
	DisplayIntVector(values);
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main

// DisplayIntVector function definition
void DisplayIntVector(const vector<int> &numbers)
{
	// output the size and content of the vector
	cout << numbers.size() << " elements:" << endl;
	for(int index = 0; index < numbers.size(); index++)
	{
		// display the element number followed by the element value
		
		cout << "Element [" << index << "] - " << numbers.at(index) << endl;
			 
	}
}
