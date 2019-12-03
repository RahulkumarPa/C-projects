/** Vectors_Pop.cpp
 *	
 *	Vector Example Program for OOP 2200. In this example, we will 
 *	'pop' elements from a vector until it is empty.
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
#include <iomanip> // for output formatting
#include <vector> // needed for vectors
using namespace std;	


int main()
{
	// DECLARATIONS
	const int QUANTITY = 5; // loop limit
	const int FACTOR = 11;  // used for values to store
	vector<int> values; // empty vector
		
	// Output an information header
	cout << ".pop_back() Example" << endl
		 << "===================" << endl;
	
	// add some elements to the vector
	for(int index = 1; index <= QUANTITY; index++)
	{
	 	values.push_back(index * FACTOR); // 11, 22, 33, 44, 55
	}
	
	// OUTPUT
	
	// TO DO: Build a loop to remove the last element from 
	// the vector until it is empty
	while(!values.empty())
	{
		// output the last element of the vector
		cout << "Removing element [" << (values.size()-1)
		      << "]: " << values.back() <<endl;
		      
		      // remove the last element
		      values.pop_back();
	}
	
	
	// TO DO: Output the size of the vector
	cout << "\nThe vector ow contains " values.size() << " elements." << endl;
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main
