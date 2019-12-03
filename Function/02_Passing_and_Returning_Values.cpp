/** Passing_and_Returning_Values.cpp
 *	
 *	In this program we define a function that takes a parameter by value 
 *	and returns a value. 
 *	   
 *	@author		Thom MacDonald
 *	@author		Rahulkumar Patel
 *	@version	2018.01
 *	@since		May 2018
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
#include <iomanip>
using namespace std;

/**	ConvertFahrenheitToCelsius function
 *	@param		fahrenheit - The temperature converting from in °F
 *	@return		The converted temperature in °C
*/
double ConvertFahrenheitToCelsius(double fahrenheit);  // function prototype
double ConvertCelsiusToFahrenheit(double celsius);

int main()
{
	// DECLARATIONS
	//const double FAHRENHEIT = 100.0; // named constant to represent the °F 
	const char DEGREE_SYMBOL = (char)248; // ASCII degree symbol
	double temperature = 0.0;	// variable to represent the °C temperature	
	char tempScale;
	double tempInput = 0.0;
	
	// get user input of temperature and letter
	cout << "Enter a temperature followed by C or F" << endl
	     << "to convert to celsius or Fahrenhit: ";
    cin>> tempInput >> tempScale;
    
    // converts user input letter to uppercase
    tempScale = toupper(tempScale);
    
    // Determine the letter entered and calculate accordingly
    if(tempScale == 'F')
    {
    	temperature = ConvertFahrenheitToCelsius(tempInput);
	}
    else if(tempScale == 'C')
    {
    	temperature = ConvertCelsiusToFahrenheit(tempInput);
	}
	// function call
	// OUTPUT
	cout << "Passing and Returning Values" << endl
		 << "============================" << endl
		 << fixed << setprecision(1);
		 
	cout << tempInput << DEGREE_SYMBOL << tempScale
	     << " converts to "
		<< temperature << DEGREE_SYMBOL;
		if(tempScale == 'F')
		    cout << "C";
		 else   
	        cout << "F";

	cout << endl << endl;
	return 0;
} // end of main

//	ConvertFahrenheitToCelsius function definition
double ConvertFahrenheitToCelsius(double fahrenheit)  // function header
{	// function body
  // return Celsius temperature formula
  return (5.0/9.0) * (fahrenheit - 32.0);
}

//	ConvertCelsiusToFahrenheit function definition
double ConvertCelsiusToFahrenheit(double Celsius)  // function header
{	// function body
  // returnFahrenhit temperature formula
  return (9.0/5.0) * Celsius + 32.0;
}
