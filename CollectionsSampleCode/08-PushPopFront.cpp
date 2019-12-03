/** 08-PushPopFront.cpp
 *	
 *  In this version, we add more dynamic re-sizing functionality to our container class.
 *
 *	@author		Thom MacDonald
 *	@version	2014.02
 *	@since		Oct 2014
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#include <iostream>		
#include <iomanip> 		
#include <stdexcept>
#include <sstream>

using namespace std;

// Container class
class WholeNumbers
{
	private:
		int * myArray;  // pointer to a dynamically-allocated c-array 
		int mySize;		// the size of the c-array
	public:
		WholeNumbers(int size, int initialValue = 0); // constructor
		~WholeNumbers() { cout << "\nBOOM!\n"; delete [] myArray;} // destructor
		WholeNumbers(const WholeNumbers &source); // NEW! copy constructor
		WholeNumbers& operator=(const WholeNumbers &source); // assignment operator	
		int Size() const {return mySize;} // mySize accessor
		int operator[](int index) const;  // accessor version of []
		int& operator[](int index);		  // mutator version of []
		string DebugString() const; // an accessor to show info about the state of the object		
		void Resize(int newSize, int initialValue = 0);	// re-sizing mutator
		
		void PushBack(int newValue); // for adding an element to the back/end
		int PopBack();				 // for removing an element from the back/end
		
		void PushFront(int newValue); // NEW! for adding an element to the front/start
		int PopFront();	  			  // NEW! for removing an element from the front/start

}; 


int main()
{
	try
	{
		WholeNumbers numbersObj(0); // Declare a container object
		

		for(int i = 0; i < 3; i++)
		{
			// Add values for elements, growing the container
			numbersObj.PushFront((i + 1) * 5); // abritrary values: 5, 10, 15
			numbersObj.PushBack((i + 1) * 2); // abritrary values: 2, 4, 6
		}
		cout << "\nAfter \'Pushing\' 6 elements: " << endl;
		cout << numbersObj.DebugString();
		cin.ignore();
		
		while(numbersObj.Size() > 0)
		{
			// Remove elements, shirking the container
			cout << "\n\'Popping\' Front: " << numbersObj.PopFront() << endl;
			cout << "\n\'Popping\' Back:  " << numbersObj.PopBack() << endl;
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

// re-sizing mutator
void WholeNumbers::Resize(int newSize, int initialValue)
{
	int * newArray = new int[newSize]; // throws bad_alloc on failure
	int elementsToCopy = (mySize < newSize)? mySize : newSize; // whichever is smaller
	
	// Copy each each existing element to the new array
	for(int i = 0; i < elementsToCopy; i++)
		newArray[i] = myArray[i];
	
	// Initialize any remaining elements to initialValue
	for(int i = elementsToCopy; i < newSize; i++)
		newArray[i] = initialValue;
	
	// Set the new size
	mySize = newSize;
	
	// Delete the old array
	delete [] myArray;
	
	// Set the myArray pointer to the new array
	myArray = newArray;
}

// for adding an element to the back/end
void WholeNumbers::PushBack(int newValue)
{
	// Make the container larger by 1
	Resize(mySize + 1);
	// Add the new value to the end
	myArray[mySize - 1] = newValue;
}

// NEW! for adding an element to the front/start
void WholeNumbers::PushFront(int newValue)
{
	// Make the container larger by 1
	Resize(mySize + 1);
	
	// Shift all the existing element value backward 1 spot:
	for(int moveTo = mySize - 1; moveTo > 0; moveTo--)
	{
		myArray[moveTo] = myArray[moveTo - 1];
	}
	
	// Add the new value to the front
	myArray[0] = newValue;
}

// for removing an element from the back/end
int WholeNumbers::PopBack()
{
	// If the container is empty, throw an error
	if(mySize <= 0)
		throw out_of_range("Cannot .PopBack() an empty container. ");
	// preserve the last value
	int value = myArray[mySize - 1];
	// Make the container smaller by 1
	Resize(mySize - 1);
	// return the former last value
	return value;
}

// NEW! for removing an element from the start/front
int WholeNumbers::PopFront()
{
	// If the container is empty, throw an error
	if(mySize <= 0)
		throw out_of_range("Cannot .PopFront() an empty container. ");
	// preserve the first value
	int value = myArray[0];
	
	// Shift all the existing element value forward by 1 spot:
	for(int moveTo = 0; moveTo < mySize - 1; moveTo++)
	{
		myArray[moveTo] = myArray[moveTo + 1];
	}
	
	// Make the container smaller by 1
	Resize(mySize - 1);
	// return the former last value
	return value;
}
