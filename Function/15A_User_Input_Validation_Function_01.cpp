/** User_Input_Validation_Function_01.cpp
 *	
 *  In this activity, we create a re-usable input validation function.
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
#include <iomanip>
#include <cmath>
#include <limits> // numeric_limits
#include <cfloat>  // for limits of a double DBL_MIN and DBL_MAX
using namespace std;

/**	ReadDouble function
 * Reads a valid double value from the console with range checking
 *
 * @param  MIN the minimum value the user may enter; defaults to the defaults to the maximum negative double.
 * @param  MIN the minimum value the user may enter; defaults to the maximum double.
 * @return A validated double input by the user.
*/
double ReadDouble(const double MIN = -DBL_MAX, const double MAX = DBL_MAX);

int main()
{
	// DECLARATIONS
    const int MIN_INPUT = 0;		// minimum value
    const int MAX_INPUT = 100;		// maximum value
	double inputValue;		 		// hold the input from the user
	
	cout << "ReadDouble() Function" << endl
		 << "=====================" << endl;
	
	// INPUT
	// Prompt for input
	cout << "Please enter a number: ";
	
	// Get the input using our function
	inputValue = ReadDouble(MIN_INPUT, MAX_INPUT);
	 
	// OUTPUT
	// Display the value entered
	cout << "\nCongratulations on entering the value " << inputValue << "!";
        
	// done.
	cout << endl << endl;
	return 0;
} // end of main

// ReadDouble function definition
double ReadDouble(const double MIN, const double MAX)
{
       
       double validNumber = 0.0; // holds the user input
       
	   cin >> validNumber;       // try to get input
	   
	   // remove any remaining characters from the buffer.
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       
       if(cin.fail())            // if user input fails...
       {
           cin.clear(); // Reset the fail() state of the cin object.
		   cin.sync();  // clear the buffer 
           // report the problem to the user.
           cerr << "* Invalid input. Please try again and enter a numeric value.\n";
           // Try again by calling the function again (recursion)
           validNumber = ReadDouble(MIN, MAX);
       } 
       else if(validNumber < MIN || validNumber > MAX)// if value is outside range...
       {
           // report the problem to the user.
           cerr << " * Invalid input. Please try again and enter a value between "
                << MIN << " and " << MAX << ".\n";
           // Try again by call the function again (recursion)
           validNumber = ReadDouble(MIN, MAX);
       }
       
       return validNumber; // returns a valid value to the calling function.
}
