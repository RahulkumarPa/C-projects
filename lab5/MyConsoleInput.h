/*
	Name:  MyConsoleInput.h
	Author: Falgun Ghevariya,Vishwa Bhavsar
	Date: 25-03-18 13:41
	Description: The re-usable library for input validation.
*/

#ifndef MY_CONSOLE_INPUT_H  

#define MY_CONSOLE_INPUT_H //define MY_CONSOLE_INPUT_H

#include <limits>  // numeric_limits 
#include <cfloat>  // for limits of a double DBL_MIN_TEMP and DBL_MAX_TEMP
#include "MyConsoleInput.cpp" //include library file for input

namespace ConsoleInput
{
	/**	TempDouble function
	 * Reads a valid double value from the console with range checking
	 * MIN_TEMP the minimum value the user may enter; defaults to the maximum negative double.
	 * MIN_TEMP the minimum value the user may enter; defaults to the maximum double.
	 * @return A validated double input by the user.
	*/
	double ReadDouble(const double MIN_TEMP = -DBL_MAX, const double MAX_TEMP = DBL_MAX);
	
	/**	TempInteger function
	 * Reads a valid int value from the console with range checking
	 * MIN_TEMP the minimum value the user may enter; defaults to the minimum int.
	 * MIN_TEMP the minimum value the user may enter; defaults to the maximum int.
	 * @return A validated int input by the user.
	*/
	int ReadInteger(const int MIN_TEMP = INT_MIN, const int MAX_TEMP = INT_MAX);
	
}
#endif // end if
