/** Vectors_Push.cpp
 *	
 *	Vector Example Program for OOP 2200. In this example, we will 
 *	declare an empty vector and 'push' new elements to it. 
 *
 *   
 *	@author		Thom MacDonald
 *	@version	2018.02 - updated to new ConsoleInput library
 *	@since		3 Mar 2018
 *	@see		Vector – C++ Reference. (n.d.). In Cplusplus.com. 
 *				   Retrieved 21 Jan 2018 from 
 *				   http://www.cplusplus.com/reference/vector/vector/ 
*/

#include <iostream>
#include <iomanip> // for output formatting
#include <vector> // needed for vectors
#include "MyConsoleInput.h" // custom header for numeric input validation from the console.
using namespace std;	


int main()
{
	// DECLARATIONS
	int numberOfTests; // a variable to determine the number of inputs
	double inputTestGrade; // holds the test grade entered by the user
	// TO DO: Declare an empty vector
	vectro<double> studentTesGrades;
	
	// Output an information header
	cout << ".push_back() Example" << endl
		 << "====================" << endl;
	
	// INPUT
	// prompt for the number of tests
	cout << "How many tests are there? "; 
	// get the number of tests
	numberOfTests = ConsoleInput::ReadInteger(1);
	
	// TO DO: Using a for loop, get grades from user,
	// test for valid input, 'push' valid grades to vector


	
	// OUTPUT
	cout << "\nHere are the student's test grades: " << endl
		 << fixed << setprecision(1);
	// For each test grade in the array:
	for(int testIndex = 0; testIndex < studentTestGrades.size(); testIndex++)
	{
		// display the test number followed by the 
		// test grade in a field width of 5 characters
		
		cout << "Test #" << (testIndex + 1) << " - "
			 //<< setw(5) << studentTestGrades[testIndex] << endl;
			 << setw(5) << studentTestGrades.at(testIndex) << endl;
			 
	}
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main
