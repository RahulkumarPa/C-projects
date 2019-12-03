/** 05-OverloadedSubscript.cpp
 *	
 *  In this version, we revisit overloading the subscript ([]) operator in way way that makes 
 *	sense in the context of the container class.
 *
 *	@author		Thom MacDonald
 *	@version	2014.02
 *	@since		Oct 2014
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 * 	@see		http://en.wikipedia.org/wiki/Rule_of_three_%28C%2B%2B_programming%29
 *  @see		http://www.drdobbs.com/c-made-easier-the-rule-of-three/184401400
*/

#include <iostream>		
#include <iomanip> 		
#include <stdexcept>	
#include <vector>

using namespace std;

// Very simple container class
class WholeNumbers
{
	private:
		int * myArray;  // pointer to a dynamically-allocated c-array 
		int mySize;		// the size of the c-array
	public:
		WholeNumbers(int size, int initialValue = 0); // constructor
		~WholeNumbers() { /*cout << "\nBOOM!\n";*/ delete [] myArray;} // destructor
		WholeNumbers(const WholeNumbers &source); // NEW! copy constructor
		WholeNumbers& operator=(const WholeNumbers &source); // assignment operator
		
		int Size() const {return mySize;} // mySize accessor
//		int GetAt(int index) const;	// accessor for an element of myArray
//		void SetAt(int index, int value); // mutator for an element of myArray
		
		int operator[](int index) const;  // accessor version of []
		int& operator[](int index);		  // mutator version of []
		
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
		cout << "\nEnter " << numbersObj.Size() << " values into the object: " << endl;
		
		// Loop for each element of the 'container'
		for(int i = 0; i < numbersObj.Size(); i++)
		{
			// Prompt for element:
			cout << "[" << i << "]: ";

			//int temp; // temporary input variable
			//// Get value for element from user:
			//cin >> temp;
			//// Set the element
			//numbersObj.SetAt(i, temp);
			
			// Get value for element from user:
			cin >> numbersObj[i]; // since [] returns a referance to the element, this works!
		}

		cout << "\n\nOutput from the object:" << endl;		
		// Loop for each element of the 'container'
		for(int i = 0; i < numbersObj.Size(); i++)
		{
			// Output the element value to the console
			//cout << "\n[" << i << "]: " << numbersObj.GetAt(i);
			cout << "\n[" << i << "]: " << numbersObj[i]; // used as an accessor, but still calls the mutator version
		}
		
		
		const WholeNumbers NUMBERS_OBJ = numbersObj; // creates a const version of the object using the copy constructor

//		// Prompt the user to enter values
//		cout << "\nEnter " << NUMBERS_OBJ.Size() << " values into the object CONSTANT: " << endl;
//		
//		// Loop for each element of the 'container'
//		for(int i = 0; i < NUMBERS_OBJ.Size(); i++)
//		{
//			// Prompt for element:
//			cout << "[" << i << "]: ";
//			// Get value for element from user:
//			cin >> NUMBERS_OBJ[i]; // since [] const returns a value to the element, this won't compile!
//		}
		
		cout << "\n\nOutput from a object CONSTANT:" << endl;
		// Loop for each element of the 'container' constant
		for(int i = 0; i < NUMBERS_OBJ.Size(); i++)
		{
			// Output the element value to the console
			//cout << "\n[" << i << "]: " << numbersObj.GetAt(i);
			cout << "\n[" << i << "]: " << NUMBERS_OBJ[i]; // Calls the accessor version
		}
		
	
	}
	catch(const exception& ex)
	{
		// the 'new' operator will throw a bad_alloc if it fails.
		// Both versions of operator[] will throw out_of_range if they fail
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

// copy constructor
WholeNumbers::WholeNumbers(const WholeNumbers &source)
{
	// Allocate a new array dynamically on construction
	mySize = source.mySize; // set the size
	myArray = new int [mySize]; // may throw bad_alloc exception
	// Initialize each element to the corresponding value in the source object
	for(int i = 0; i < mySize; i++)
		myArray[i] = source.myArray[i];
}

// assignment operator
WholeNumbers& WholeNumbers::operator=(const WholeNumbers &source)
{
	delete [] myArray; // free up the old memory
	// Allocate a new array dynamically on construction
	mySize = source.mySize; // set the size
	myArray = new int [mySize]; // may throw bad_alloc exception
	// Initialize each element to the corresponding value in the source object
	for(int i = 0; i < mySize; i++)
		myArray[i] = source.myArray[i];
	
	return *this;
} 

// operator [] accessor for an element of myArray
int WholeNumbers::operator[](int index) const
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= mySize)
		throw out_of_range("Index must be between 0 and " + to_string(mySize - 1) + ".");
	// return the value stored at element index
	return myArray[index]; 
}	
// operator [] mutator for an element of myArray
int& WholeNumbers::operator[](int index) 
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= mySize)
		throw out_of_range("Index must be between 0 and " + to_string(mySize - 1) + ".");
	// return a REFERENCE to the element at index
	return myArray[index]; 
}

//// accessor for an element of myArray
//int WholeNumbers::GetAt(int index) const
//{
//	// if the parameter index is invalid, throw an exception
//	if(index < 0 || index >= mySize)
//		throw out_of_range("Index must be between 0 and " + to_string(mySize - 1) + ".");
//	// return the value stored at element index
//	return myArray[index]; 
//}	
//// mutator for an element of myArray
//void WholeNumbers::SetAt(int index, int value) 
//{
//	// if the parameter index is invalid, throw an exception
//	if(index < 0 || index >= mySize)
//		throw out_of_range("Index must be between 0 and " + to_string(mySize - 1) + ".");
//	
//	// set value stored at element index to the parameter value
//	myArray[index] = value; 
//}	

