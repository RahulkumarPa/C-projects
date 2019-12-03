/** Global_Storage_Classes.cpp
 *	
 *	In this example we examine the extern and static storage classes for 
 *	global variables. This is the first of two files.
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
#include "07B_Global_Storage_Classes_File2.cpp" // second file in the project
using namespace std;

// GLOBAL DECLARATIONS
int globalVariable = 1;	// regular global variable
static int staticGlobalVariable = 2; // static global variable
									 // - cannot be extended beyond
									 //   this file.
						

// FUNCTION PROTOTYPES

void GlobalExample();
void StaticGlobalExample();
void ExternalGlobalExample();

int main()
{
	cout << "Global Storage Classes" << endl
		 << "======================" << endl;
	
	// FUNCTION CALLS
	GlobalExample();
	StaticGlobalExample();
	ExternalGlobalExample();
	FunctionFromFile2(); // Function defined in second file
		
	// done.
	cout << endl << endl;
	return 0;
} // end of main


// FUNCTION DEFINITIONS
void GlobalExample()
{
	// No problem accessing a global declared in this file
	cout << globalVariable << ": Global" << endl;
}

void StaticGlobalExample()
{
	// No problem accessing a static global declared in this file
	cout << staticGlobalVariable << ": Static Global" << endl;
}

void ExternalGlobalExample()
{
	extern int externalGlobalVariable; // extends the scope of the
									   // global variable declared 
									   // in second file. Not a new
									   // storage location.
									   
	cout << externalGlobalVariable << ": External Global" << endl;
}


