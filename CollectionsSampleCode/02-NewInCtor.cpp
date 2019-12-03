/** 02-NewInCtor.cpp
 *	
 * Before we delve into the other STL container class templates, we will work on creating our own simple 
 * container classes from scratch.
 * 
 * In this demo we will create an incomplete container class called WholeNumbers. It features an int pointer 
 * as a private member and dynamic memory allocation in the constructor. This version of the class has 
 * issues for us to discover. 
 *  
 *	@author		Thom MacDonald
 *	@version	2014.02
 *	@since		Oct 2014
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 * 	@see		http://www.cplusplus.com/doc/tutorial/dynamic/
 *	@see		http://www.cplusplus.com/reference/vector/vector/
 *  @see		http://www.learncpp.com/cpp-tutorial/104-container-classes/
*/

#include <iostream>		
#include <stdexcept>	

using namespace std;

// Very simple container class with ISSUES!
class WholeNumbers
{
	private:
		int * myArray;  // pointer to a dynamically-allocated array 
		int mySize;		// the size of the c-array
	public:
		WholeNumbers(int size, int initialValue = 0); // constructor
		int Size() const {return mySize;} // mySize accessor
		int GetAt(int index) const;	// accessor for an element of myArray
		void SetAt(int index, int value); // mutator for an element of myArray	
}; 

int main()
{
	try
	{
	    int size; 	// holds user input for the number of elements to store
	    
		// Prompt for and get the number of elements from the user
		cout << "\n\nHow many numbers do you want to store in the OBJECT? ";
		cin >> size;		
		
		WholeNumbers numbersObj(size); // Declare a container object
		
		// Prompt the user to enter values
		cout << "\n\nEnter " << size << " values into the OBJECT: " << endl;
		
		// Loop for each element of the 'container'
		for(int i = 0; i < numbersObj.Size(); i++)
		{
			int temp; // temporary input variable
			// Prompt for element:
			cout << "[" << i << "]: ";
			// Get value for element from user:
			cin >> temp;
			// Set the element
			numbersObj.SetAt(i, temp);
		}
		// Loop for each element of the 'container'(goes a little over)
		for(int i = 0; i <= numbersObj.Size(); i++)
		{
			// Output the element value to the console
			cout << "\n[" << i << "]: " << numbersObj.GetAt(i);
		}
		
	}
	catch(const exception& ex)
	{
		// the 'new' operator will throw a bad_alloc if it fails.
		// .SetAt() and .GetAt() will throw out_of_range if they fail
		cerr << endl << ex.what() << endl;
	}

	
	// END-OF-PROGRAM
	cout << endl << endl;
	return 0;
} // end of main()

// constructor
WholeNumbers::WholeNumbers(int size, int initialValue)
{
	// Allocate a new array dynamically on construction
	myArray = new int [size]; // may throw bad_alloc exception
	mySize = size; // set the size
	// Initialize each element to the initial value
	for(int i = 0; i < mySize; i++)
		myArray[i] = initialValue;
}

// accessor for an element of myArray
int WholeNumbers::GetAt(int index) const
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= mySize)
		throw out_of_range("Index must be between 0 and " + to_string(mySize - 1) + ".");
	// return the value stored at element index
	return myArray[index]; 
}	
// mutator for an element of myArray
void WholeNumbers::SetAt(int index, int value) 
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= mySize)
		throw out_of_range("Index must be between 0 and " + to_string(mySize - 1) + ".");
	
	// set value stored at element index to the parameter value
	myArray[index] = value; 
}	

