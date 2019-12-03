/** 05_DynamicallyAllocatedArrays.cpp
 *	
 *	Pointers Example Program 05 for OOP 2200. In this example, we will 
 *	use a pointer variable to create an array in memory dynamically,
 *  including runtime exception handling. 
 *	   
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		24 Feb 2018
 *	@see 		Bronson, G. (2012).  Chapter 8 Arrays and Pointers. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
 *	@see		Dynamically Allocated Arrays in C++ (11:49)
 *					http://www.youtube.com/watch?v=Vj8vkEB7B6c&hd=1
*/

#include <iostream>
#include "MyConsoleInput.h"	// for ReadInteger, ReadDouble
#include "MyArrayTemplates.h"	// for SelectionSort
using namespace std;	
using namespace MyArrayTemplates;
using namespace ConsoleInput;

int main()
{
	// DECLARATIONS
	int numberOfGrades;  // 'Companion' to the array
	// an pointer to what will be a dynamically allocated array
	double *ptrGrades = NULL; // initialized to NULL at this point
	double sumOfGrades = 0.0; // a sum of the grades to calculate the average
	int returnValue = 0;
	
	cout << "Dynamically Allocated Arrays" << endl
		 << "============================" << endl
		 << fixed << setprecision(1);
	
	// Determine the number of grades to be processed
	cout << "\nHow many grades do you wish to process? ";
	/************************************************************************************
	 *	INTERACTIVE: 
	 *	See what happens when you remove the domain validation, allowing the user to 
	 *  enter a negative number...
	 ************************************************************************************/
	numberOfGrades = ReadInteger(0, 100); // limited to 100
	
	try // attempt to do the following (may cause runtime exceptions)
	{
		ptrGrades = new double [numberOfGrades]; // finds room on 
			// the 'heap' for an array of doubles, reserves that 
			// memory and assigns the memory address to the pointer.
			// IF THIS FAILS, it will 'throw' a std::bad_alloc exception
		
		// now we can use ptrGrades like it is an array...
		cout << "\nPlease enter " << numberOfGrades << " grades: " << endl;
		for(int index = 0; index < numberOfGrades; index++)
		{
			// prompt for and get grade for element
			cout << "Grade " << (index + 1) << ": ";
			ptrGrades[index] = ReadDouble(0.0, 100.0); // array notation
			// *(ptrGrade + index) = ReadDouble(0.0, 100.0); // pointer notation
		}
		
		// Sort the grades
		SelectionSort(ptrGrades, numberOfGrades); // array functions and 
												// templates still work.
		
		cout << "\nHere are the " << numberOfGrades << " grades entered, sorted. " << endl;
		for(int index = 0; index < numberOfGrades; index++)
		{
			// display grade for element
			cout << "\nGrade " << (index + 1) << ": " << ptrGrades[index]; // array notation
			//cout << "Grade " << (index + 1) << ": " << *(ptrGrade + index); // pointer notation
			sumOfGrades += ptrGrades[index];
		}
		// output the average
		if(numberOfGrades) // avoid dividing by zero
		{
			cout << "\n\nThe average grade was: " << sumOfGrades/numberOfGrades << endl;
		}
		// done with the array. De-allocate the memory to avoid a memory leak.
		delete [] ptrGrades;
		
	} // end of try
	catch(bad_alloc)
	{
		cerr << "\nRUNTIME ERROR: The program failed to allocated " << numberOfGrades 
			 << " doubles in memory." << endl; // most likely cause: out of memory
		returnValue = 1; // main returns 1 to indicate a problem 
	}
	
	// done.
	cout << endl << endl;
	return returnValue; // either 0 or 1, depending of how the program ran.
} // end of main
