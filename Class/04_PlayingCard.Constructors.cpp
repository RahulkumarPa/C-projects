/** PlayingCard.Constructors.cpp
 *	
 *	In this example program, we did the following:
 *		- Added default and parameterized constructors to the class.
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
		/* Constructor(s): Used to initialize objects
		 *	- always the same name as the class
		 *	- never have a return type
		 *	- called automatically when an obj is instantiated
		 *	- should set values for each member variable
		 */
		 
		// Default constructor using an initialization list
		// - by default, the card is a face down Ace of Hearts with a value of 1
		PlayingCard(): myRank("Ace"), mySuit("Hearts"), myValue(1), IsFaceUp(false) {}
		
		// Parametrized constructor
		PlayingCard(string rank, string suit, int value = -999, bool faceUp = false);
		
		/* Accessor(s): Used to query the state of the object
		 *	- never modifies the object
		 *	- should specify const at the end of the prototype/header
		 */
		string GetRank() const { return myRank; } // gets rank name as a string
		string GetSuit() const { return mySuit; } // gets suit name as a string
		int GetValue() const {return myValue; }   // gets the value of the card
		string ToString() const; // convert the obj to a string.

		
		/* Mutator(s): Used to change the state of the object
		 *	- should contain logic to ensure object remains in a valid state.
		 *	- typically sets a member variable to a parameter
		 */
		void SetRank(string rank, bool updateValue = true); // sets the rank
		void SetSuit(string suit); // sets the suit
		void SetValue(int value = -999); // sets the value

		bool FlipCard() {return (IsFaceUp = !IsFaceUp);} // changes the face up state
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
		int myValue;   // a integer to represent the 'value' of the card. 
		
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
		// DECLARATIONS
		PlayingCard cardObj; // default ctor used
		
		// TO-DO: Use parametrized ctor
		PlayingCard blackJack;
		
		// Display the playing cards as initialized
		cout << "\n\nAs Initialized" << endl
			 << "============================" << endl
			 << "cardObj is   : " << cardObj.ToString() << endl
			 << "blackJack is : " << blackJack.ToString() << endl << endl;
		
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

/** Parametrized Constructor for PlayingCard class
 *  @param	rank: int (a number between 1 and 13)
 *  @param	suit: int (a number between 0 and 3)
 *  @param	faceUp: bool (true if face-up, false if not)
 *	@throws	out_of_range exception if rank or suit params are invalid
 */
PlayingCard::PlayingCard(string rank, string suit, int value, bool faceUp)
{
	// Set the rank and suit with validation
	SetRank(rank); 
	SetSuit(suit);
	if(value == -999)
	{
		myValue = GetDefaultValue();
	}
	else
	{
		myValue = value;
	}
	// set the face-up field
	IsFaceUp = faceUp;
}

/** SetRank Method for PlayingCard class
 *	Sets the rank of this PlayingCard object.
 *  @param	rank: string
 *  @param  updateValue: bool (defaults to true)
 *	@throws	invalid_argument exception if the param is invalid
 */
void PlayingCard::SetRank(string rank, bool updateValue)
{
	// if the rank parameter is one of the valid ranks
	if(rank == "Ace" || rank == "Two" || rank == "Three" || rank == "Four" || rank == "Five" || 
	   rank == "Six" || rank == "Seven" || rank == "Eight" || rank == "Nine" || rank == "Ten" || 
	   rank == "Jack" || rank == "Queen" || rank == "King") // whew! There has to be a better way!
	{
	   	// set myRank to the parameter
		myRank = rank;
	   	
	   	// if update value parameter is true   
		if(updateValue)
	   	{
	   		// set myValue to the default value
			myValue = GetDefaultValue();
		}
	}
	else // rank parameter is not valid
	{
		// throw an appropriate exception
		throw invalid_argument(rank + " is not a recognized playing card rank.");
	}
}

/** SetSuit Method for PlayingCard class
 *	Sets the suit of this PlayingCard object.
 *  @param	suit: string 
 *	@throws	invalid_argument exception if the param is invalid
 */
void PlayingCard::SetSuit(string suit)
{
	// if the suit parameter is one of the valid suits
	if(suit == "Spades" || suit == "Hearts" || suit == "Diamonds" || suit == "Clubs") 
	{
	   	// set mySuit to the parameter
		mySuit = suit;
	}
	else // suit parameter is not valid
	{
		// throw an appropriate exception
		throw invalid_argument(suit + " is not a recognized playing card suit.");
	}
}

/** SetValue Method for PlayingCard class
 *	Sets the suit of this PlayingCard object.
 *  @param	value: int (defaults to -999) 
 */
void PlayingCard::SetValue(int value)
{
	// if the value parameter is -999 the likely cause is that it defaulted to -999
	if(value -999) 
	{
	   	// set myValue to the default value
		myValue = GetDefaultValue();
	}
	else // value was specified
	{
		// set myValue to the parameter
		myValue = value;
	}
}

/** ToString Method for PlayingCard class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string PlayingCard::ToString() const
{
	// declare an empty string
	string cardString;
	
	// if the card is face-up
	if(IsFaceUp)
	{
		// build a descriptive string from the obj state
		cardString = myRank + " of " + mySuit + " (" + to_string(myValue) + ")";
	}
	else // card is face-down
	{
		// string indicates face-down
		cardString = "Face-Down";
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
