/************************************************************************************************************
*Authors:		Gary Baker & Rahulkumar Patel
*Date:			July 7th, 2018
*Description:	This program will allow the user to choose how many days they wish to input data for.  
				The data will be celsius temperatures for a dynamic allocation of up to 365 days. Thee output
				will display the Celsius entiries along with their cooresponding Fahrenheit equivelant.
************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cfloat>
#include "MyConsoleInput.h"
using namespace std;

// Inline function for conversion
inline double ConvertTemperature(double celsius) {return celsius * 1.8 + 32.0;}

// Report function definition 
void Report(double* temperatures, const int DAYS);

int main()
{
	//int celsiusInput = 0;
	//double calculatedFahrenheit = 0;
	int daysInput = 0;
	//bool ValidateInput(int daysInput);
	
	const int DAYS_MAX = 365;
	const int DAYS_MIN = 1;
	
	const double LOWEST = -90.0;  // lowest valid celsius temp
    const double HIGHEST = 60.0;  // highest valid celsius temp

	// A pointer to the temperature data
    double * weeklyCelsiusTemps = (double *) NULL;
    
    // Prompt and store daysInput
    cout << "How many days do you wish to enter? ";
    daysInput = ConsoleInput::ReadInteger(DAYS_MIN, DAYS_MAX);

	// A try catch works best vs a do while
	try
    {
         // Allocate the array dynamically
		weeklyCelsiusTemps = new double[daysInput];
    
	     // Prompt and store temperatures
	    cout << "\nTEMPERATURE REPORTER" << endl
	         << "======================" << endl << endl
	         << "Please enter the temperature for each day." << endl;
	    
	    // For loop for input
	    for(int day = 0; day < daysInput; day++) // input loop
	    {
	    	// Prompt for input of each temp for each day, adding 1 so it doesn't start at 0
	    	cout << "Celsius temperature for Day " << (day + 1) << ": "; 
	    	// User input validation from Thom's code 
	    	// In class I said everyone could use this. Saves time and trouble :)
	        weeklyCelsiusTemps[day] = ConsoleInput::ReadDouble(LOWEST, HIGHEST);
	    } // end of input loop
	    
	    // Call Report function and pass it the temp and days
	    Report(weeklyCelsiusTemps, daysInput);
	    
	    // Delete pointer
	    delete [] weeklyCelsiusTemps;
	}
	catch(bad_alloc)
	{
		// Output error message
		cerr << "\nCould not allocate " << daysInput << " temperatures in memory.";
	}
    cout << endl << endl;


	
	return 0;
}

// Report function definition, taking in temps and days
void Report(double* temperatures, const int DAYS)
{
    const char DEGREES = (char) 248; // the degree symbol
    const double* END = temperatures + DAYS; // pointer

    // Output Report
    // NEED TO FOR LOOP FOR THIS
    cout << "\n\nDAILY TEMPERATURE REPORT" << endl
	<< "============================"  << endl ;
    
    // Use a FOR loop to output the results, formatted of course
    for(int day = 0; day < DAYS; day++) // Loop to output results
    {
    	cout   << "Day "  << std::right << std::setw(3) << day + 1  << std::setw(8)<<std::right << temperatures[day] << DEGREES << "C" << std::setw(8) << std::right << ConvertTemperature(temperatures[day]) << "F" << DEGREES << endl;
		

	}
    
}





