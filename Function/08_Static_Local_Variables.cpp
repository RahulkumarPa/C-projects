/** Static_Local_Variables.cpp
 *	
 *	In this program we examine the difference between automatic and 
 *	static local variables. 
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

/**	Test function
 *	@param		none.
 *	@return		none.
*/
void Test();  // function prototype


int main()
{
	// DECLARATIONS
	const int NUMBER_OF_CALLS = 5;
	
	// OUTPUT
	cout << "Static Local Variables" << endl
		 << "======================" << endl;
		 
	// call the Test function in a loop multiple times
	
	for(int loopCount = 1; loopCount <= NUMBER_OF_CALLS; loopCount++)
	{
		// display the current loop number
		cout << "\nLoop #" << loopCount << ": ";
		// call the test function
		Test();
	}
		
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	Test function definition
void Test()
{
	
	/************************************************************************************
	 *	INTERACTIVE: 
	 *	See what happens when you add the keyword 'static' to the locl declaration
	 *  in this example.
	 ************************************************************************************/
	
	/*static*/ int localNumber = 1; // initialize a local variable to 1
	
	// OUTPUT
	// show the variable value of the console
	cout << localNumber;
	
	// PROCESSING
	localNumber++; // increment the local variable by 1
}
