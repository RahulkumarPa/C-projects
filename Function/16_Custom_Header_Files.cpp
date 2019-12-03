/** Custom_Header_Files.cpp
 *	
 *  In this program, we use a re-usable library for our input validation functions.
 *	   
 *	@author		Thom MacDonald
 *	@author		<your name>
 *	@version	2018.01
 *	@since		Jan 2018
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
#include "MyConsoleInput.h"
using namespace std;

int main()
{
	// DECLARATIONS
    const int MIN_INPUT = 0;		// minimum value
    const int MAX_INPUT = 100;		// maximum value
	int inputValue;		 		    // hold the input from the user
	
	cout << "Custom Header File" << endl
		 << "==================" << endl;
	
	// INPUT
	// Prompt for input
	cout << "Please enter a WHOLE number: ";
	
	// Get the input using our function
	inputValue = ConsoleInput::ReadInteger(MIN_INPUT, MAX_INPUT);
	 
	// OUTPUT
	// Display the value entered
	cout << "\nCongratulations on entering the value " << inputValue << "!";
    
	// done.
	cout << endl << endl;
	return 0;
} // end of main
