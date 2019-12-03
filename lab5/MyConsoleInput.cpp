/*
	Name:  MyConsoleInput.cpp
	Author: Falgun Ghevariya,Vishwa Bhavsar
	Date: 25-03-18 13:41
	Description: This is the implement file for a library of input validation functions.
*/

#include <iostream> //cin,cout
#include <iomanip>  //formating
#include <cmath>   //math 
#include <limits> // numeric_limits
#include <cfloat>  // for limits of a double DBL_MIN_TEMP and DBL_MAX_TEMP

using namespace std;

namespace ConsoleInput
{
	// ReadDouble function definition
	double TempDouble(const double MIN_TEMP, const double MAX_TEMP)
	{
	       
	       double validNumber = 0.0; // holds the user input
	       
		   cin >> validNumber;       // try to get input
		   
		   // remove any remaining characters from the buffer.
	       cin.ignore(numeric_limits<streamsize>::max(), '\n');
	       
	       if(cin.fail())            // if user input fails
	       {
	           cin.clear(); // Reset the fail() state of the cin object.
			   cin.sync();  // clear the buffer 
	           
	           cerr << "* Invalid input. Please try again and enter a numeric value.\n";//error
	           
	           validNumber = TempDouble(MIN_TEMP, MAX_TEMP);  //Try again
	       } 
	       else if(validNumber < MIN_TEMP || validNumber > MAX_TEMP)// if value is outside range
	       {
	           
	           cerr << " * Invalid input. Please try again and enter a value between "
	                << MIN_TEMP << " and " << MAX_TEMP << ".\n";  //error
	          
	           validNumber = TempDouble(MIN_TEMP, MAX_TEMP); // Try again
	       }
	       
	       return validNumber; // returns a valid value to the calling function.
	}
	
	// TempInteger function definition
	int TempInteger(const int MIN_TEMP, const int MAX_TEMP)
	{
	       
	       double validNumber = 0.0; // holds the user input
	       
	       validNumber = TempDouble(MIN_TEMP, MAX_TEMP); // Get user input as a double
		   
	       if(validNumber > (int) validNumber)      // If user input is not a whole number
	       {
	           cerr << " * Invalid input. Please try again and enter whole number.\n"; //errpr
	           validNumber = TempInteger(MIN_TEMP, MAX_TEMP); // try again using recursion.
	       }
	       return (int) validNumber; // returns a valid value 
	}	
	
}
