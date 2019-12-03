/** Function_Overloading.cpp
 *	
 * 	In this program, we wrote two functions to examine function overloading. 
 *  The first returned the absolute value of an int argument. The second 
 *  returned the absolute value of a double argument. Both functions are called 
 *  AbsoluteValue.
 *
 *  Function overloading is an example of 'ad-hoc' polymorphism. 
 *	   
 *	@author		Thom MacDonald
 *	@author		<your name>
 *	@version	2018.01
 *	@since		Jan 2018
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
 *  @see		Polymorphism (computer science). (2018). En.wikipedia.org. 
 *					Retrieved 28 January 2018, from https://en.wikipedia.org/wiki/Polymorphism_(computer_science)
 *  @see		Function overloading. (2018). En.wikipedia.org. 
 *					Retrieved 28 January 2018, from https://en.wikipedia.org/wiki/Function_overloading
*/

#include <iostream>	
#include <iomanip>	// for output formatting

using namespace std;

/**	AbsoluteValue(int) function
 *	@param		int initialValue - The value to convert
 *	@return		the absolute value of initialValue
*/
int AbsoluteValue(int initialValue);  // function prototype

/**	AbsoluteValue(double) function
 *	@param		double initialValue - The value to convert
 *	@return		the absolute value of initialValue
*/
double AbsoluteValue(double initialValue);  // function prototype

int main()
{
	// DECLARATIONS
		
	int wholeNumber = -4;					
	float roughNumber = -4.12F;				
	double realNumber = -4.12345;
	
	cout << "Functions Overloading" << endl
		 << "=====================" << endl;
		
	// PROCESSING / OUTPUT
	
	cout << "Whole Number: " << AbsoluteValue(wholeNumber) << endl;
	cout << "Rough Number: " << AbsoluteValue(roughNumber) << endl;
	cout << " Real Number: " << AbsoluteValue(realNumber) << endl;
			
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	AbsoluteValue(int) function definition
int AbsoluteValue(int initialValue)
{
	// Declare and initialize absoluteValue to initialValue
	int absoluteValue = initialValue;
	
	// if absoluteValue is negative
	if(absoluteValue < 0)
	{
		// make it positive
		absoluteValue = -absoluteValue;
	}
	// return the absolute value
	return absoluteValue;
	
	// Alternatively, I could use the ternary conditional operator:
	//return (initialValue < 0)?-initialValue:initialValue;
}

//	AbsoluteValue(double) function definition
 
double AbsoluteValue(double initialValue) 
{
	// Declare and initialize absoluteValue to initialValue
	double absoluteValue = initialValue;
	
	// if absoluteValue is negative
	if(absoluteValue < 0)
	{
		// make it positive
		absoluteValue = -absoluteValue;
	}
	// return the absolute value
	return absoluteValue;
	
	// Alternatively, I could use the ternary conditional operator:
	//return (initialValue < 0)?-initialValue:initialValue;
}

