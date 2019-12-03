/** Inline_Functions.cpp
 *	
 *	In this program we define an in-line function. Normally when we define a 
 *	function, it is loaded into it's memory at run-time. Whenever the function 
 *	is called, execution is transfered to the memory block that where the 
 *  function deinition is located, then execution is transfered back when it 
 *  is done. There is both a memory and performance cost to this.
 *
 *  The keyword 'inline' requests that the complier replaces the function call 
 *  with the instructions in the function definition at compile-time, basically
 *  re-writing our program so that it does not have to load a separate
 *  function into memory or have to deal with transferring back and forth. 
 *  If the function is small and simple, this may be more efficient. 
 *	
 * 'inline' is only a request. If the function is too large or complex to be
 *	in-lined, it will be treated like a regular function. 
 *	   
 *	@author		Thom MacDonald
 *	@author		<your name>
 *	@version	2018.01
 *	@since		Jan 2018
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
 *	@see	    What is C++ inline functions - C++ Articles. (2014). Cplusplus.com. 
 					Retrieved 28 January 2018, from http://www.cplusplus.com/articles/2LywvCM9/  
*/

#include <iostream>
#include <iomanip>
using namespace std;

/**	ConvertFahrenheitToCelsius function
 *	@param		fahrenheit - The temperature converting from in °F
 *	@return		The converted temperature in °C
*/

/* Notes: 
	* This is using an exception to Allman style, but does not have to.
	* You can still prototype and have a separate definition. Use the keyword inline on one or the other.
*/
inline double ConvertFahrenheitToCelsius(double fahrenheit) { return (5.0/9.0) * (fahrenheit - 32.0); } 

int main()
{
	// DECLARATIONS
	const double FAHRENHEIT = 100.0; // named constant to represent the °F 
	const char DEGREE_SYMBOL = (char)248; // ASCII degree symbol
	double celsius;	// variable to represent the °C temperature	
	
	// function call
	celsius = ConvertFahrenheitToCelsius(FAHRENHEIT);
	
	// OUTPUT
	cout << "Inline Functions" << endl
		 << "================" << endl
		 << fixed << setprecision(1);
		 
	cout << FAHRENHEIT << DEGREE_SYMBOL << "F converts to " 
		<< celsius << DEGREE_SYMBOL << "C." << endl;
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main
