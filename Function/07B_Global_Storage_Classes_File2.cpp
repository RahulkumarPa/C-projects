/** Global_Storage_Classes_File2.cpp
 *	
 *	In this example we examine the extern and static storage classes for 
 *	global variables. This is the second of two files.
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

// GLOBAL DECLARATIONS
int externalGlobalVariable = 3; // regular global variable
extern int globalVariable;	// extends the scope of the
							// global variable declared 
							// in first file. Not a new
							// storage location.

// FUNCTION DEFINITION

void FunctionFromFile2() // Defined in this file, called in the other.
{
	cout << externalGlobalVariable + globalVariable << ": Function from second file" << endl;
}


