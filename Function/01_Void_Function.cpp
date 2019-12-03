/** Void_Function.cpp
 *	
 *	In this program we define a function that returns nothing and has 
 *	no parameters. 
 *	   
 *	@author		Rahulkumar Patel
 *	@version	2018.01
 *	@since		May 2018
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
using namespace std;

/**	Hello function
 *	This function displays a simple message to the console window
 *	@param		none
 *	@return		none
 */
 void Hello();
 void MoreSinging();

int main()
{
	cout << "Void Functions" << endl
		 << "==============" << endl;
	
	cout << "\nNow we will call our function: " << endl;
	
	Hello(); // call the Hello function
	MoreSinging();
	
	cout << "\nWe are back in main()." << endl;
		
	cout << endl << endl;
	return 0;
} // end of main

// Hello function definition
void Hello() // function header
{ // function body

	cout << "\nHello, world!" << endl; // output message
	cout << "\n Hello Jello!" << endl;

} // end of Hello()
void MoreSinging()
{
	cout << "\nThis is a song that never ends," << endl;
	cout << "yes this goes on and on my friends !" <<endl
	     << "Some people started singing it," <<endl
	     << "not knowing what it was, but they'all" <<endl
	     << "continue singig it forever just becasue......" << endl;
	     
	     Hello(); // Call the Hello function again
	     
}
