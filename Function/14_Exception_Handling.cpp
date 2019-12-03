/** Exception_Handing.cpp
 *	
 *	In this program we define a function that throws a standard
 *	exception when an error has occurred. 
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
#include <stdexcept> // for invalid_argument and other standard exceptions
using namespace std;

/**	ConvertFahrenheitToCelsius function
 *	@param		fahrenheit - The temperature converting from in °F
 *	@return		The converted temperature in °C
 *	@thows		std::invalid_argument if the parameter is not valid.
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

		try // something in this block might throw an exception
		{		
			// PROCESSING
			celsius = ConvertFahrenheitToCelsius(temperature);
		
			// OUTPUT
			cout << endl << temperature << DEGREE_SYMBOL << "F converts to " 
				<< celsius << DEGREE_SYMBOL << "C." << endl;
		}
		catch(invalid_argument &ex) // specifically, an invalid_argument was thrown
		{
			cerr << ex.what() << endl // information about the exception.
				 << "That is impossibly cold! Since you can't be serious, I'm shutting you down." << endl;
			needInput = false;
		}
		catch(exception &ex) // more generally, a exception of some type was thrown
		{
			cerr << ex.what() << endl // information about the exception.
				 << "That's odd. I don't know what exactly happened." << endl;
			needInput = false;
		}
		
		catch(...) // something was throw, could be anything
		{
			cerr << "\nThat's really odd. I don't know what happened at all." << endl;
			needInput = false;
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
	double celsius; // converted temperature
	 
	// is the parameter valid? 
	if(fahrenheit >= ABSOLUTE_ZERO_F)
	{
		// calculate Celsius
		celsius = (5.0/9.0) * (fahrenheit - 32.0);
	}
	else // not valid
	{

		throw invalid_argument("Argument (" + to_string(fahrenheit) 
			+ ") cannot be less than absolute zero (" + to_string(ABSOLUTE_ZERO_F) + ").");
			
		/************************************************************************************
		 *	INTERACTIVE: 
		 *	Try throwing different things instead.
		 ************************************************************************************/
		//	throw exception(); 
		//	throw out_of_range("Brrr.. too cold!");
		//	throw "Hello, world.";		 
	}
	// return Celsius
	return celsius;
}
