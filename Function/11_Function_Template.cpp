/** Function_Template.cpp
 *	
 *  In this activity, we create a function template which will be used
 *	to dynamically create overloaded versions of the function at run-time
 *	when needed.
 *
 *	Function templates are an example of 'parametric polymorphism' and is
 *  often called 'generic' programming. 
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
*/

#include <iostream>	
#include <iomanip>	// for output formatting

using namespace std;

/**	AbsoluteValue(T) function template
 *	@param		T initialValue - The value to convert
 *	@return		the absolute value of initialValue
*/
template <class T>
T AbsoluteValue(T initialValue);  // function prototype

int main()
{
	// DECLARATIONS
		
	int wholeNumber = -4;					
	float roughNumber = -4.12F;				
	double realNumber = -4.12345;
	
	cout << "Function Template" << endl
		 << "=================" << endl;
		
	// PROCESSING / OUTPUT
	
	cout << "Whole Number: " << AbsoluteValue(wholeNumber) << endl;
	cout << "Rough Number: " << AbsoluteValue(roughNumber) << endl;
	cout << " Real Number: " << AbsoluteValue(realNumber) << endl;
			
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	AbsoluteValue(T) function template definition
template <class T>
T AbsoluteValue(T initialValue)
{
	// Declare and initialize absoluteValue to initialValue
	T absoluteValue = initialValue;
	
	// if absoluteValue is negative
	if(absoluteValue < 0)
	{
		// make it positive
		absoluteValue = -absoluteValue;
	}
	// return the absolute value
	return absoluteValue;
}
