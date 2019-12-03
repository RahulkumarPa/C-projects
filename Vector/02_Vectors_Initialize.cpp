/** Vectors_Initialize.cpp
 *	
 *	Vector Example Program for OOP 2200. In this example, we will 
 *	initialize elements at the time the vector is declared.
 *
 *	@author		Thom MacDonald
 *	@version	2018.02
 *	@since		3 Mar 2018
 *	@see		Vector – C++ Reference. (n.d.). In Cplusplus.com. 
 *				   Retrieved 21 Jan 2018 from 
 *				   http://www.cplusplus.com/reference/vector/vector/ 
*/

#include <iostream>
#include <vector> // needed for vectors
using namespace std;	


int main()
{
	// DECLARATIONS
	// TO DO: Declare and initialize a vector of doubles
	vector<int> values { 11,22,33,44,55 };

		
	// Output an information header
	cout << "Initializing Vectors" << endl
		 << "====================" << endl;
		
	// output the size and content of the vector
	cout << "\nThe vector contains " << values.size() << " elements: ";
	for(auto value: values)
	{
		// display the element value	
		cout << value << " ";	 
	}
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main
