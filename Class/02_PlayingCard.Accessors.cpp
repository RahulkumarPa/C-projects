/** PlayingCard.Accessors.cpp
 *	
 *	In this example program, we did the following: 
 *		- Added accessors to the class.
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
	
		/* Accessor(s): Used to query the state of the object
		 *	- never modifies the object
		 *	- should specify const at the end of the prototype/header
		 */
		string GetRank() const { return myRank; } // gets rank name as a string
// TO-DO: Add GetSuit() method 
		 // gets suit name as a string
// TO-DO: Add GetValue() method 
	     // gets the value of the card
		string ToString() const; // convert the obj to a string.
						  				 // defined in-line
		
		/* Public member variables
		 *	- only use if they cannot cause an invalid state.
		 *	- not very common.
		 */
		bool IsFaceUp; // true if face-up, false if face-down
	
	// Private members are only accessible inside the class
	//	- typically member variables
	private:
		// Private data members - we are protecting these from invalid values
		string myRank; // a string to represent the rank
		string mySuit; // a string to represent the suit
		int myValue; 	 // a integer to represent the 'value' of the card. 
		
		// Private Methods - useful internally
		int GetDefaultValue() const; // gets the default value for the rank		
}; // end of class declaration section

// main() function typically defined first
int main()
{
	// Output an information header
	cout << "PlayingCard Class Demo" << endl
		 << "======================" << endl;

	try
	{
		PlayingCard testCard; // declare a card
		
		// Display the card
		cout << "\ntestCard rank is " << testCard.GetRank() << " and suit is " << testCard.GetSuit();
		cout << "\ntestCard value is " << testCard.GetValue(); 
   	    cout << "\ntestCard as a string is "<< testCard.ToString() << endl;
	}
	catch(const exception& ex) // Inclusion polymorphism:
						   	   //  std::out_of_range thrown, but
						   	   //  std::exception caught. 
	{
		cerr << ex.what(); // display the exception message.
	}
	
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main

// Class definition section (method definitions)

/** ToString Method for PlayingCard class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string PlayingCard::ToString() const
{
// TO-DO: Finish coding this method.
	// declare an empty string
	string cardString;
	
	// if the card is face-up
	if(IsFaceUp)
	{
		// build a descriptive string from the obj state
	
	}
	else // card is face-down
	{
		// string indicates face-down
	
	}
	// return the string
	return cardString;
}

/** GetDefaultValue Method for PlayingCard class
 *	Determines and returns the default value for the card based on its rank. 
 *	@return	the default value for the card.
 */
int PlayingCard::GetDefaultValue() const
{
	// set default value to 10
	int defaultValue = 10; // Jack, King, Queen
	
	// if rank is Ace or One through Nine, 
	// 	 update default value accordingly
	
	if(myRank == "Ace")  
	{
		defaultValue = 1;
	} 
	else if(myRank == "Two")
	{
		defaultValue = 2;
	} 
	else if(myRank == "Three")
	{
		defaultValue = 3;
	}  
	else if(myRank == "Four")
	{
		defaultValue = 4;
	} 
	else if(myRank == "Five")
	{
		defaultValue = 5;
	} 
	else if(myRank == "Six")
	{
		defaultValue = 6;
	} 
	else if(myRank == "Seven" )
	{
		defaultValue = 7;
	}  
	else if(myRank == "Eight")
	{
		defaultValue = 8;
	} 
	else if(myRank == "Nine")
	{
		defaultValue = 9;
	}	// There must be a better way to do this! 
	
	// return default value
	return defaultValue;
}
