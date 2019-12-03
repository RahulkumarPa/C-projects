/** Global_Scope.cpp
 *	
 *	In this program we examine the difference between local and 
 *	global variables. 
 *
 *  Generally speaking, you should declare variables in the narrowest 
 *  scope possible. This makes your program more modular, which should 
 *  make it easier to debug and maintain. Also, functions that have
 *	extensive external dependencies (e.g. dependant on a number of 
 *  global variables being declared) are more difficult to reuse. 	
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
using namespace std;

/**	LocalScopeTest function
 *	@param		none.
 *	@return		none.
*/
void LocalScopeTest();  // function prototype

/**	globalNumber
 *	an int variable available to all functions defined after this declaration. 
 */
int globalNumber;  // Avoid this is labs.

int main()
{
	// DECLARATIONS
	int localNumber; // an int variable only available in the block it is declared in.
	
	// PROCESSING
	// set the local variable to 88 and the global variable to 888
	localNumber = 88;
	globalNumber = 888;
		
	// OUTPUT
	cout << "Global Scope" << endl
		 << "============" << endl;
		 
	// show the variable values
	cout << "\nIn main(), BEFORE call to function:" << endl
		 << "localNumber is: " << localNumber << endl
		 << "globalNumber is " << globalNumber << endl;
		 
	LocalScopeTest(); // call the function
	
	// show the variable values again	 
	cout << "\nIn main(), AFTER call to function:" << endl
		 << "localNumber is: " << localNumber << endl
		 << "globalNumber is " << globalNumber << endl;

		
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	LocalScopeTest function definition
void LocalScopeTest()
{
	// DECLARATIONS
	int localNumber; // an int variable only available in the block it is declared in.
	
	// PROCESSING
	// set the local variable to 99 and the global variable to 999
	localNumber = 99;
	globalNumber = 999;
	
	// OUTPUT
	// show the variable values
	cout << "\nIn LocalScopeTest():" << endl
		 << "localNumber is: " << localNumber << endl
		 << "globalNumber is " << globalNumber << endl;
		 
}
