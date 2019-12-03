/** 01-IntroToContainers.cpp
 *	
 *	A container class is a class designed to hold and organize multiple objects of another class or data-type.
 * The most basic example of a container (although not a container 'class') is the built-in array functionality 
 * that C++ inherited from the C programming language. We will refer to this kind of array as a 'C-array'. 
 * C-arrays, while quick and economical, have significant limitations. C-arrays are by default static, meaning 
 * the size of the c-array is determined at compile time. You can create a dynamic c-array using a pointer and 
 * the new/delete operators, but they can be awkward to use and maintain. C-arrays do not have any built-in 
 * safety features like bounds-checking, and things like dynamic resizing require meticulous manual steps that 
 * are prone to run-time problems. 
 *
 * The C++ Standard Template Library (STL) includes a number of generic container classes that are very useful 
 * when you are familiar with how they work. One of these is the vector class, which we have used. Using a vector 
 * rather than a c-array provides many convenient and robust benefits including simplified memory management, 
 * dynamic sizing/resizing, bounds-checking, etc. It is often it is a good practice to make use of the STL classes 
 * where possible. 
 *
 *   
 *	@author		Thom MacDonald
 *	@version	2014.02
 *	@since		Oct 2014
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see		http://www.cplusplus.com/doc/tutorial/arrays/
 * 	@see		http://www.cplusplus.com/doc/tutorial/dynamic/
 *	@see		http://www.cplusplus.com/reference/vector/vector/
 *  @see		http://www.learncpp.com/cpp-tutorial/104-container-classes/
 *	@see		http://www.cplusplus.com/reference/stl/
 * 	@see		http://www.cplusplus.com/doc/tutorial/templates/
*/

#include <iostream>		
#include <iomanip> 		
#include <stdexcept>	
#include <vector>		

using namespace std;


// Global, non-member functions, each an example of a 'container' in use.
void ArrayExample();
void DynamicExample();
void VectorExample();

int main()
{
	char choice;			// user input for menu-choice
	bool needInput = true;  // loop control
	
	do // Repeat:
	{
		// Display menu
		cout << "\n\nMENU " << endl
			 << "=====" << endl << endl
			 << "\'A\' Run ARRAY Example" << endl
			 << "\'D\' Run DYNAMIC ARRAY Example" << endl
			 << "\'V\' Run VECTOR Example" << endl
			 << "\'Q\' to Quit" << endl << endl
			 << ": ";
		// Clear the input buffer	 
		fflush(stdin);
		// Get the menu choice from the user
		choice = cin.get();
		// Convert the choice to uppercase
		choice = toupper(choice);
		
		// Based on the choice, run the appropriate example:
		switch(choice)
		{
			case 'A':
				ArrayExample();
				break;
			case 'D':
				DynamicExample();
				break;
			case 'V':
				VectorExample();
				break;
			case 'Q': // Quit the loop
				needInput = false;
				break;
			default:  // invalid choice
				cout << "\nUnrecognized choice. Please try again.";
		}
		
	}while (needInput); // Continue looping while input is needed.

	
	// END-OF-PROGRAM
	cout << endl << endl;
	return 0;
} // end of main()

void ArrayExample()
{

	try
	{
		/* Variable Length Arrays (VLAs) 
		 * VLAs are NOT ALLOWED in ISO C++, even if this syntax works in your compiler!
		 */

//		int variableSize; // holds the size of the 'array' as a variable 
//		// Prompt for and get the number of elements from the user
//		cout << "\n\nHow many numbers do you want to store in the ARRAY? ";
//		cin >> variableSize;
//		int aryNumbers[variableSize]; // Declare a VLA, not ISO C++
		
		const int ARRAY_SIZE = 5;   // A 'companion' constant for the array	
		int aryNumbers[ARRAY_SIZE]; // The array size MUST resolve to a constant expression at compile-time
		
		// Prompt the user to enter values
		cout << "\n\nEnter " << ARRAY_SIZE << " values into the ARRAY: " << endl;
		
		// Loop for each element of the 'container'
		for(int i = 0; i < ARRAY_SIZE; i++)
		{
			// Prompt for element:
			cout << "[" << i << "]: ";
			// Get value for element from user:
			cin >> aryNumbers[i];
		}
		
		// Loop for each element of the 'container' (goes a little over)
		for(int i = 0; i <= ARRAY_SIZE; i++)
		{
			// Output the element value to the console
			cout << "\n[" << i << "]: " << aryNumbers[i];
		}
	}
	catch(const exception& ex)
	{
		// Unreachable code: C-arrays don't throw exceptions!
		cerr << endl << ex.what() << endl;
	}

} // end of ArrayExample

void DynamicExample()
{
	try
	{
	    int dynamicSize; 	// holds the size of the 'array' as a variable
	    int * ptrNumbers;   // 'points' to an 'array' on the heap
		
		// Prompt for and get the number of elements from the user
		cout << "\n\nHow many numbers do you want to store in the DYNAMIC ARRAY? ";
		cin >> dynamicSize;		
		
		ptrNumbers = new int [dynamicSize]; // dynamically-allocate the 'array'
		
		// Prompt the user to enter values
		cout << "\n\nEnter " << dynamicSize << " values into the DYNAMIC ARRAY: " << endl;
		
		// Loop for each element of the 'container'
		for(int i = 0; i < dynamicSize; i++)
		{
			// Prompt for element:
			cout << "[" << i << "]: ";
			// Get value for element from user:
			cin >> ptrNumbers[i];
		}
		// Loop for each element of the 'container'(goes a little over)
		for(int i = 0; i <= dynamicSize; i++)
		{
			// Output the element value to the console
			cout << "\n[" << i << "]: " << ptrNumbers[i];
		}
		
		delete [] ptrNumbers; // Don't forget to delete!
	}
	catch(const exception& ex)
	{
		// the 'new' operator will throw a bad_alloc if it fails.
		cerr << endl << ex.what() << endl;
	}

}
void VectorExample()
{
	try
	{
	    int vectorSize;	// holds user input for the number of elements to store
		vector<int> vNumbers; // an empty std::vector to hold ints
		
		// Prompt for and get the number of elements from the user
		cout << "\n\nHow many numbers do you want to store in the VECTOR? ";
		cin >> vectorSize;
		
		// Resize the vector accordingly
		vNumbers.resize(vectorSize);
		
		// Prompt the user to enter values
		cout << "\n\nEnter " << vNumbers.size() << " values into the VECTOR: " << endl;
		
		// Loop for each element of the 'container'
		for(int i = 0; i < vNumbers.size(); i++)
		{
			// Prompt for element:
			cout << "[" << i << "]: ";
			// Get value for element from user:
			cin >> vNumbers.at(i);
			//cin >> vNumbers[i];
		}
		
		// Loop for each element of the 'container'	(goes a little over)
		for(int i = 0; i <= vNumbers.size(); i++)
		{
			// Output the element value to the console
			cout << "\n[" << i << "]: " << vNumbers.at(i);
		}
	}
	catch(const exception& ex)
	{
		// a number of exceptions could be thrown
		cerr << endl << ex.what() << endl;
	}

}



