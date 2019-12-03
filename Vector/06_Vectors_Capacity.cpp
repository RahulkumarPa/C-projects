/** Vectors_Capacity.cpp
 *	
 *	Vector Example Program for OOP 2200. In this example, we will 
 *	explore how capacity is increased as size is increased.
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
	const int ELEMENTS = 33; 	// number of elements to add
	vector<double> values;		// holds an increasing number of values
	int pauseIndex = 2;			// pause output after this index
		
	// Output an information header
	cout << "Vector Capacity" << endl
		 << "===============" << endl;
	
	// display the initial size and capacity
	cout << "Initial Size: " << values.size() << "   "
 		 << "Initial Capacity: " << values.capacity() << endl;
 	
 	// loop ELEMENTS times
 	// TO DO: Create a loop that counts through the elements,
 	// If the index is less than the pauseIndex, pause
 	// wait for key press, then increase pauseIndex times 2 MIGHT NOT DO THIS!!!!
 	for(int index = 0; index < ELEMENTS; index++)
    {
	 	// is it time to pause?
		if(index > pauseIndex) 
	 	{
	 		// pause
			cout << "\nPress \'Enter\' to continue... ";
	 		cin.ignore();
	 		cin.sync();
			// double the pause index
			pauseIndex *= 2;
	 	}
		 
		 // add an element to the vector
	 	cout << "\nAdding #" << setw(2) << index + 1 << ": ";
	    values.push_back(index);
 		
		// display the new size and capacity
 		cout << "Size: " << setw(2) << values.size() << "   "
 			 << "Capacity: " << setw(2) << values.capacity() 
			 << endl;
	}
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main


