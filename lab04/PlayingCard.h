/** PlayingCard.h
 *	
 *	This is a version of the PlayingCard class developed from OOP 2200.
 *   
 *	@author		Thom MacDonald
 *	@version	2018.04
 *	@since		Jul 2018 
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#ifndef _PLAYING_CARD

#define _PLAYING_CARD

#include <iomanip> 		// for output formatting
#include <cctype>		// for toupper()
#include <stdexcept>	// for invalid_argument

using namespace std;	


class PlayingCard // Class declaration section
{
	public:	
		/************************************************************************************
		 *	Static arrays of strings to represent the ranks and suits
		 ************************************************************************************/
		static const string CARD_RANK[]; // an array that holds the names of the ranks								
		static const string CARD_SUIT[]; // an array that holds the names of the suits
		static const int RANKS; // the number of ranks
		static const int SUITS; // the number of suits
		
		// by default, the card is a face up Ace of Hearts with a value of 1
		PlayingCard(): myRankIndex(1), mySuitIndex(1), myValue(1), IsFaceUp(true) {}
		
		// Parametrized constructors
		PlayingCard(string rank, string suit, int value = DEFAULT_VALUE_WANTED, bool faceUp = true);
		PlayingCard(int rankIndex, int suitIndex, int value = DEFAULT_VALUE_WANTED, bool faceUp = true);

		// Accessors		
		string GetRank() const { return CARD_RANK[myRankIndex]; } // gets rank name as a string
		string GetSuit() const { return CARD_SUIT[mySuitIndex]; } // gets suit name as a string
		int GetValue() const {return myValue; }   // gets the value of the card
		//string ToString() const; // convert the obj to a string.
		operator string() const; // convert the obj to a string.
		
		// Mutators
		void SetRank(int rankIndex, bool updateValue = true); // sets the rank by number
		void SetSuit(int suitIndex); // sets the suit
		void SetRank(string rank, bool updateValue = true); // sets the rank by number
		void SetSuit(string suit); // sets the suit
		void SetValue(int value = DEFAULT_VALUE_WANTED); // sets the value
		bool FlipCard() {return (IsFaceUp = !IsFaceUp);} // changes the face up state
			 							  				 // defined in-line
		//	Public member variables
		bool IsFaceUp; // true if face-up, false if face-down
	
	private:

		int myRankIndex; // an int to represent the rank {1 - 13}
		int mySuitIndex; // an int to represent the suit (0 - 3}
		int myValue;   // an int to represent the 'value' of the card. 

		static const int DEFAULT_VALUE_WANTED = -999;
				
		// Private Methods - useful internally
		int GetDefaultValue() const; // gets the default value for the rank
		
}; // end of class declaration section


// Static data member initialization
const string PlayingCard::CARD_SUIT[] = { "Spades", "Hearts", "Diamonds", "Clubs" };
const string PlayingCard::CARD_RANK[] = { "Not Used", "Ace", "Two", "Three", "Four", "Five", 
								"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const int PlayingCard::RANKS = 13;
const int PlayingCard::SUITS = 4;

// Class definition section (method definitions)

/** Parametrized Constructor for PlayingCard class
 *  @param	rank: int (a number between 1 and 13)
 *  @param	suit: int (a number between 0 and 3)
 *  @param	faceUp: bool (true if face-up, false if not)
 *	@throws	out_of_range exception if rank or suit params are invalid
 */
PlayingCard::PlayingCard(int rankIndex, int suitIndex, int value, bool faceUp)
{
	// Set the rank and suit with validation
	SetRank(rankIndex); 
	SetSuit(suitIndex);
	if(value == DEFAULT_VALUE_WANTED)
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

/** Parametrized Constructor for PlayingCard class
 *  @param	rank: string 
 *  @param	suit: string
 *  @param	faceUp: bool (true if face-up, false if not)
 *	@throws	out_of_range exception if rank or suit params are invalid
 */
PlayingCard::PlayingCard(string rank, string suit, int value, bool faceUp)
{
	// Set the rank and suit with validation
	SetRank(rank); 
	SetSuit(suit);
	if(value == DEFAULT_VALUE_WANTED)
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
 *  @param	rankIndex: int
 *  @param  updateValue: bool (defaults to true)
 *	@throws	invalid_argument exception if the param is invalid
 */
void PlayingCard::SetRank(int rankIndex, bool updateValue)
{
  	// if the parameter is valid
	if(rankIndex > 0 && rankIndex <= RANKS) // simple range check
	{
	   	// set myRankIndex to the rankIndex parameter
		myRankIndex = rankIndex;
	   	
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
		throw invalid_argument(to_string(rankIndex) + " is not a recognized playing card rank.");
	}
}

/** SetRank Method for PlayingCard class
 *	Sets the rank of this PlayingCard object.
 *  @param	rank: string
 *  @param  updateValue: bool (defaults to true)
 *	@throws	invalid_argument exception if the param is invalid
 */
void PlayingCard::SetRank(string rank, bool updateValue)
{
	bool valid = false; // is the parameter a valid rank
	int rankIndex = 1; 	// holds the index of the rank in the rank array if valid
	
	// for each possible rank until we find a match
	while(!valid && rankIndex <= RANKS)
	{
		if(rank == CARD_RANK[rankIndex])
		{
			valid = true; // a match was found
		}
		else
		{
			 rankIndex++; // next index
		}
	}
	
  	// if the parameter is valid
	if(valid) 
	{
	   	// set myRankIndex to the rankIndex found
		myRankIndex = rankIndex;
	   	
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
 *  @param	suitIndex: int 
 *	@throws	invalid_argument exception if the param is invalid
 */
void PlayingCard::SetSuit(int suitIndex)
{
	// if the suit parameter is valid
	if(suitIndex >= 0 && suitIndex < SUITS)
	{
	   	// set mySuitIndex to the parameter
		mySuitIndex = suitIndex;
	}
	else // suit parameter is not valid
	{
		// throw an appropriate exception
		throw invalid_argument(to_string(suitIndex) + " is not a recognized playing card suit.");
	}
}

/** SetSuit Method for PlayingCard class
 *	Sets the suit of this PlayingCard object.
 *  @param	suit: string 
 *	@throws	invalid_argument exception if the param is invalid
 */
void PlayingCard::SetSuit(string suit)
{
	bool valid = false; // is the parameter a valid rank
	int suitIndex = 0; 	// holds the index of the suit in the suit array if valid	
	
	// for each possible suit until we find a match
	while(!valid && suitIndex < SUITS)
	{
		if(suit == CARD_SUIT[suitIndex])
		{
			valid = true; // a match was found
		}
		else
		{
			suitIndex++; // next index
		}
	}
	
	// if the suit parameter is one of the valid suits
	if(valid)
	{
	   	// set mySuitIndex to the suitIndex found
		mySuitIndex = suitIndex;
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
	if(value == DEFAULT_VALUE_WANTED) 
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

/** string Method for PlayingCard class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
PlayingCard::operator string() const
{
	// declare an empty string
	string cardString;
	
	// if the card is face-up
	if(IsFaceUp)
	{
		// build a descriptive string from the obj state
		cardString = CARD_RANK[myRankIndex] + " of " + CARD_SUIT[mySuitIndex] + " (" + to_string(myValue) + ")";
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
	int defaultValue = 10; // Ten, Jack, King, Queen
	
	// if rank is Ace or One through Nine 
	if(myRankIndex < defaultValue)
	{
		defaultValue = myRankIndex; // update default value accordingly

	}
	
	// return default value
	return defaultValue;
}

#endif
