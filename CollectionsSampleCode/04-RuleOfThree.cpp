/** 04-RuleOfThree.cpp
 *	
 * In addition to assignment of one container object to another causing a memory problem, these
 * other situations can cause an memory allocation issue:
 * - Passing a container object to a function by value
 * - Returning a container object from a function by value
 * - Initializing a container object with another container object
 *
 * The Rule of Three
 * =================
 * If you NEED to include either a destructor, copy constructor, or assignment 
 * operator in a class, then chances are very good that you need all three.
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
#include <sstream>	
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

	// The Rule of Three!
		~WholeNumbers() { cout << "\nBOOM!\n"; delete [] myArray;} // destructor
		//WholeNumbers(const WholeNumbers &source); // NEW! copy constructor
		//WholeNumbers& operator=(const WholeNumbers &source); // assignment operator
		
		int Size() const {return mySize;} // mySize accessor
		int GetAt(int index) const;	// accessor for an element of myArray
		void SetAt(int index, int value); // mutator for an element of myArray
		string DebugString() const; // an accessor to show info about the state of the object		
}; 

// Testing passing a container object to a function by value
void PassTest(WholeNumbers test)
{
	// Tell the user the object has been passed
	cout << "\nObject passed to function." << endl;
	// Show the state of the object 
	cout << test.DebugString();
}

// Testing returning a container object from a function by value
WholeNumbers ReturnTest()
{
	// Create a local object
	WholeNumbers obj(4, 44); 
	// Show the state of the object 
	cout << obj.DebugString(); 
	// return the object
	return obj;
}


int main()
{
	try
	{
	    WholeNumbers testObject1(2, 22);	// test object
		
//		cout << "\nPassing a container object to a function by value." << endl;
//		PassTest(testObject1);
//		cout << testObject1.DebugString();	
//		cout << endl << endl;
		
//		cout << "\nReturning a container object from a function by value." << endl;
//		testObject1 = ReturnTest();
//		cout << testObject1.DebugString();
//		cout << endl << endl;
				
//		cout << "\nInitializing a container object with another container object" << endl;
//		WholeNumbers testObject2 = testObject1;
//		cout << testObject1.DebugString();
//		cout << testObject2.DebugString();
	
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

//// NEW! copy constructor
//WholeNumbers::WholeNumbers(const WholeNumbers &source)
//{
//	// Allocate a new array dynamically on construction
//	mySize = source.mySize; // set the size
//	myArray = new int [mySize]; // may throw bad_alloc exception
//	// Initialize each element to the corresponding value in the source object
//	for(int i = 0; i < mySize; i++)
//		myArray[i] = source.myArray[i];
//}

/// assignment operator
//WholeNumbers& WholeNumbers::operator=(const WholeNumbers &source)
//{
//	delete [] myArray; // free up the old memory
//	// Allocate a new array dynamically on construction
//	mySize = source.mySize; // set the size
//	myArray = new int [mySize]; // may throw bad_alloc exception
//	// Initialize each element to the corresponding value in the source object
//	for(int i = 0; i < mySize; i++)
//		myArray[i] = source.myArray[i];
//	
//	return *this;
//} 

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

// an accessor to show info about the state of the object	
string WholeNumbers::DebugString() const
{
	stringstream debug;
	debug << "\n==================== DEBUG ====================" << endl
		  << "myArray: " << myArray << endl
		  << "mySize:  " << mySize << endl;
	for(int i = 0; i < mySize; i++)
	{
		debug << "[" << i << "]: " << myArray[i] << "  ";
	}

	debug << "\n===============================================" << endl;
	return debug.str();
}
