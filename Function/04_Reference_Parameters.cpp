/** Reference_Parameters.cpp
 *	
 *	In this program we define a function that takes a parameters by value and by reference. 
 * 	
 *	Arguments are passed by value by default. The parameter is a separate data item that 
 *	is initialized by the argument. Put another way, the parameter is a copy of the argument
 *	passed to it. Changes to the parameter do not effect the argument. 	
 *
 *	When an argument is passed as a reference, then the parameter is just another name for 
 *	the same data item. Changes made to the parameter change the argument as well.
 *   
 *	@author		Thom MacDonald
 *	@author		<your name>
 *	@version	2018.01
 *	@since		Jan 2018
 *	@see 		Bronson, G. (2012). Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see	 	Passing arguments by reference. (2018). Learn C++. 
 					Retrieved 28 January 2018, from http://www.learncpp.com/cpp-tutorial/73-passing-arguments-by-reference/
*/

#include <iostream>	
#include <iomanip>	// for output formatting
#include <cctype> 	// for toupper()
using namespace std;

/**	ConvertTemperature function
 *	@param		fromTemperature - The temperature converting from
 *	@param		fromScale - The scale converting from
 *	@param		& toTemperature - Reference to the temperature converting to
 *	@param		& toScale - Reference to the scale converting to
 *	@return		true if the fromScale was valid (i.e. the conversion 
 *					was possible), otherwise false.
*/
bool ConvertTemperature(double fromTemperature, char fromScale, double & toTemperature, char & toScale);  // function prototype

int main()
{
	// DECLARATIONS
	const char DEGREE_SYMBOL = (char)248; // ASCII degree symbol
	double inTemperature;			// variable to represent the temperature input
	double outTemperature;			// variable to represent the temperature to output
	char inScale;					// variable to represent the scale input
	char outScale;					// variable to represent the scale to output
	bool validScale;				// variable to represent if the input scale is valid
	
	
	cout << "Reference Parameters" << endl
		 << "====================" << endl
		 << fixed << setprecision(1);


	// INPUT
	
	// prompt for the input temperature and scale
	cout << "\nPlease enter the temperature to convert from. "
		 << "\n(Value followed by \'C\' or \'F\')\n: ";
	
	// get the input temperature and scale
	cin >> inTemperature >> inScale;
	
	// PROCESSING
	
	validScale = ConvertTemperature(inTemperature, inScale, outTemperature, outScale);
	
	// OUTPUT
	if(validScale) // Did the conversion work?
	{
		// output the converted temperature message.
		cout << endl << inTemperature << DEGREE_SYMBOL << inScale << " converts to " 
			 << outTemperature << DEGREE_SYMBOL << outScale << "." << endl;
		
	}
	else
	{
		// output an error message
		cout << "\nConversion was not successful. \'" << inScale 
			 << "\' is not a valid scale." << endl;
	}
		
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	ConvertTemperature function definition
bool ConvertTemperature(double fromTemperature, char fromScale, double & toTemperature, char & toScale)
{	
  	bool validScale = true; // by default, valid scale is true
  	
  	// convert fromScale to upper case
  	fromScale = toupper(fromScale); // #include <cctype> is needed
	
	// Are we converting from °F to °C?
	if (fromScale == 'F')
  	{
  		// convert the temperature from °F to °C
		toTemperature = 5.0 / 9.0 * (fromTemperature - 32.0);
  		// set the toScale to °C
		toScale = 'C';
  	}
  	// Otherwise, // Are we converting from °C to °F?
	else if (fromScale == 'C')
	{
		// convert the temperature from °C to °F
		toTemperature = fromTemperature * 9.0 / 5.0 + 32.0;
  		// set the toScale to °F
		toScale = 'F';
	}
	// Otherwise, the fromScale is not °F to °C
	else 
	{
		validScale = false; // scale was invalid
	}
	// return true of false, based on the fromScale
	return validScale;
}

