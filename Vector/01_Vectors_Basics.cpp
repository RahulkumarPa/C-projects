/** Vectors_Basics.cpp
 *	
 *	Vector Example Program for OOP 2200. In this example, we will 
 *	create a dynamic array-like structure called a vector. 
 *
 *   
 *	@author		Thom MacDonald
 *	@version	2018.02
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
	int numberOfTests; // a variable to determine the size of the vector
	
	// Output an information header
	cout << "Vectors Basics" << endl
		 << "==============" << endl;
	
	// INPUT
	// prompt for the number of tests
	cout << "How many tests are there? ";
	// get the number of tests
	numberOfTests = ConsoleInput::ReadInteger(1);
	
	// Declare the vector based on a variable
	vector<double> studentTestGrades(numberOfTests);
	
	for(int testIndex = 0; testIndex < numberOfTests; testIndex++)
	{
		// prompt for test #
		cout << "Please enter the grade for test " << (testIndex + 1) << ": ";
		// TO DO: get test #
		studentTestGrades[testIndex] = consoleInput::ReadDouble(0.0,100.0); 
	}
	
	// OUTPUT
	cout << "\nHere are the student's test grades: " << endl
		 << fixed << setprecision(1);
	// For each test grade in the array:
	for(int testIndex = 0; testIndex < numberOfTests; testIndex++)
	{
		// display the test number followed by the 
		// test grade in a field width of 5 characters
		
		cout << "Test #" << (testIndex + 1) << " - "
			 << setw(5) << studentTestGrades[testIndex] << endl;
	}
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main
