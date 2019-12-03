/** Scope_Resolution_Operator.cpp
 *	
 *  In this program we use the scope resolution operator to differentiate 
 *	between local and global scope variables with the same name. Again,
 * 	this situation should be avoided by always declaring variables in the
 *	narrowest scope possible.
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


/**	someNumber
 *	an global int variable initialized to 88. 
 */
int someNumber = 88;

int main()
{
	// DECLARATIONS
	int someNumber = 99; // a local int variable initialized to 99. 
	
	// OUTPUT
	cout << "Scope Resolution Operator" << endl
		 << "=========================" << endl;
		 
	// show the variable value
	cout << "The local version of someNumber is: " << someNumber << endl;  
	
	// show the global variable value explicitly using the scope resolution operator
	cout << "The global version of someNumber is: " << ::someNumber << endl;
	

	// done.
	cout << endl << endl;
	return 0;
} // end of main

