/** 03-AssignmentIssue.cpp
 *	
 * New features in the WholeNumbers class include a destructor as well as a method to show 
 * the state of the object for debugging purposes.
 *	
 * In this demo we will test the WholeNumbers container class to discover what happens when
 * assigning a container object to another container object. Initially we will try this 
 * without an overloaded assignment operator, then we will add one to solve the problem 
 * discovered. 
 *  
 *	@author		Thom MacDonald
 *	@version	2014.02
 *	@since		Oct 2014
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 * 	@see		http://www.cplusplus.com/doc/tutorial/dynamic/
 *  @see		http://www.learncpp.com/cpp-tutorial/104-container-classes/
*/

#include <iostream>		
#include <iomanip> 		
#include <stdexcept>	
#include <vector>
#include <sstream>

using namespace std;

// Very simple container class with ISSUES!
class WholeNumbers
{
	private:
		int * myArray;  // pointer to a dynamically-allocated c-array 
		int mySize;		// the size of the c-array
	public:
		WholeNumbers(int size, int initialValue = 0); // constructor
		~WholeNumbers() { cout << "\nBOOM!\n"; delete [] myArray;} // NEW! destructor
		//WholeNumbers& operator=(const WholeNumbers &source); // NEW! assignment operator
		
		int Size() const {return mySize;} // mySize accessor
		int GetAt(int index) const;	// accessor for an element of myArray
		void SetAt(int index, int value); // mutator for an element of myArray
		string DebugString() const; // NEW! an accessor to show info about the state of the object		
}; 

int main()
{
	try
	{
	    WholeNumbers testObject1(4);	// test object containing 4 ints
	    WholeNumbers testObject2(5);   // test object containing 5 ints
    
		// Assign element values for first test object
	    for(int i = 0; i < testObject1.Size(); i++)
	    	testObject1.SetAt(i, (i + 1) * 100); // 100, 200, 300, ...
	    
		// Assign element values for second test object	
	    for(int i = 0; i < testObject2.Size(); i++)
	    	testObject2.SetAt(i, (i + 1) * 11); // 11, 22, 33, ...
	    
	    cout << "After assigning element values:" << endl
			 << "\ntestObject 1:";
		// Show the object debug info
		cout << testObject1.DebugString();
		cout << "\ntestObject 2:";
		cout << testObject2.DebugString();
		
		cin.ignore();
		cout << endl << endl << endl;
	    
	    // Assign one container object to another
	    testObject1 = testObject2;
	    
	    cout << "After assigning one container object to another:" << endl
			 << "\ntestObject 1:";
		// Show the object debug info
		cout << testObject1.DebugString();
		cout << "\ntestObject 2:";
		cout << testObject2.DebugString();
	
	}
	catch(const exception& ex)
	{
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

//// NEW! assignment operator
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

// NEW! an accessor to show info about the state of the object	
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
