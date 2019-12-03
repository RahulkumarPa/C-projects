/** PlayingCard.DataMembers.cpp
 *	
 *	In this example program, we did the following: 
 *		- Declared a class with public and private members.
 *   
 *	@author		<YOUR-NAME>
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		2 Feb 2018 <update to today's date>
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#include <iostream>
#include <iomanip> 		// for output formatting
#include <stdexcept>	// for invalid_argument
using namespace std;	


class PlayingCard // Class declaration section
{
	//	Public members are accessible outside of the class
	//	  - typically member functions (called methods)
	public:	
		/* Public member variables
		 *	- only use if they cannot cause an invalid state.
		 *	- not very common.
		 */
		// true if face-up, false if face-down
	
	// Private members are only accessible inside the class
	//	- typically member variables
	private:
		// Private data members - we are protecting these from invalid values
		// a string to represent the rank
		// a string to represent the suit
		// a integer to represent the 'value' of the card. 
}; // end of class declaration section

// main() function typically defined first
int main()
{
	// Output an information header
	cout << "PlayingCard Class Demo" << endl
		 << "======================" << endl;

	// declare a card
	// make it face-up
	// set the rank to "Ace"
	// set the suit to "Spades"
		
	// done.
	cout << endl << endl;
	return 0;
} // end of main

// Class definition section (method definitions)
