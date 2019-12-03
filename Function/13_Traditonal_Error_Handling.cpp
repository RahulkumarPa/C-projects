/** Traditional_Error_Handing.cpp
 *	
 *	In this program we define a function that returns a special
 *	value (sentinel value) that signals an error has occurred. 
 *	   
 *	@author		Thom MacDonald
 *	@author		<your name>
 *	@version	2018.01
 *	@since		Jan 2018
 *	@see 		Bronson, G. (2012).  Chapter 14 The string Class and Exception Handling. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
#include <iomanip>
using namespace std;

/**	ConvertFahrenheitToCelsius function
 *	@param		fahrenheit - The temperature converting from in °F
 *	@return		The converted temperature in °C, or -999.9 if there is an error
*/
double ConvertFahrenheitToCelsius(double fahrenheit);  // function prototype

int main()
{
	// DECLARATIONS
	double temperature; // variable to represent the °F 
	const char DEGREE_SYMBOL = (char)248; // ASCII degree symbol
	double celsius;	// variable to represent the °C temperature	
	bool needInput = true; // control variable for the main program loop
	
	cout << "TRADITIONAL ERROR HANDLING" << endl
		 << "==========================" << endl
		 << fixed << setprecision(1);	
	
	do
	{
		// INPUT
		// prompt for a temperature in °F 
		cout << "\nPlease enter a temperature in " << DEGREE_SYMBOL << "F: ";
		// read the temperature from the console until a numeric value is entered.
		while(!(cin >> temperature))
		{
			cin.clear();
			cin.sync();
			cout << "* Numeric please: ";
		}
			
		// PROCESSINGF
		celsius = ConvertFahrenheitToCelsius(temperature);
		
		if(celsius == -999.9) // what's this?
		{
			cerr << "\nThat is impossibly cold! Since you can't be serious, I'm shutting you down." << endl;
			needInput = false;
		}
		else
		{
			// OUTPUT
	
			cout << endl << temperature << DEGREE_SYMBOL << "F converts to " 
				<< celsius << DEGREE_SYMBOL << "C." << endl;
		}
		
	}while (needInput);
		
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	ConvertFahrenheitToCelsius function definition
double ConvertFahrenheitToCelsius(double fahrenheit)  
{	
	const double ABSOLUTE_ZERO_F = -459.67; // Absolute Zero (O°K)
	const double ERROR = -999.9; // a sentinel that signals an error
	double celsius; // converted temperature
	 
	// is the parameter valid? 
	if(fahrenheit >= ABSOLUTE_ZERO_F)
	{
		// calculate Celsius
		celsius = (5.0/9.0) * (fahrenheit - 32.0);
	}
	else // not valid
	{
		// Now what?
		celsius = ERROR; // set to a sentinel
	}
	// return Celsius
	return celsius;
}
