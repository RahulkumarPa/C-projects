/** 
 *	
 *	@author		Rahulkumar Patel,Heth Patel
 *	@author		Thom MacDonald
 *	@version	2018.02
 *	@since		Jul 2018 4-10-2018
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#include <iostream>		
#include <stdexcept>
#include <sstream>
#include "PlayingCard.h"
#include <ctime>

using namespace std;

// Container class
class StandardDeck
{
	private:
		PlayingCard * myArray;  // pointer to a dynamically-allocated c-array 
		int mySize;		// the size of the c-array
		
	public:
		PlayingCard Pcard(52); //Object of  PlayingCard class
		StandardDeck(); // constructor
		virtual void Initialize(int size); 	// Can be called on construction or any time after

		~StandardDeck() { delete [] myArray;} // destructor
		int CardsRemaining() const { return mySize; } // mySize accessor

		PlayingCard DrawNextCard();	  			// for removing an element from the front/start
		PlayingCard	DrawRandomCard();			// for removing an element from the random position
		void Shuffle();                       // for the shuffle
}; 

int main()
{
	try
	{
		StandardDeck cards(52);  //object of StandaedDeck
		
	    // Show the object debug info
		 Pcard << "\nAs Initialized: " << endl;
		cout <<  Pcard.DebugString() << endl;
		
		//for Card Insert
		 Pcard.Insert(4, PlayingCard("Queen", "Hearts"));
		//for card removing
		Pcard.Remove(1);
	}
	catch(const exception& ex)
	{
		cerr << endl << ex.what() << endl;
	}
	
	// END-OF-PROGRAM
	cout << endl << endl;
	return 0;
} // end of main()


// constructor
StandardDeck::StandardDeck()
{
	// Set the pointer to zero
	myArray = 0;
	int size = 52;
	// Call the initialization method
	StandardDeck.Initialize(size);
}

// to initialize or re-initialize the object
void StandardDeck::Initialize(int size)
{
	// if the pointer is not 0, memory has been allocated
	if(myArray != 0)
		// delete the existing memory
		delete [] myArray;
		
	// Allocate a new array dynamically on construction
	myArray = new PlayingCard [size]; // may throw bad_alloc exception
	mySize = size; // set the size
	
	// Loop for each element
	for(int i = 0; i < mySize; i++)
	{
		// give the playing card a random suit and rank
		myArray[i].SetSuit(rand() % (PlayingCard::SUITS)); 
		myArray[i].SetRank(1 + rand() % (PlayingCard::RANKS)); 
	}
	
}

// for removing an element from the start/front
PlayingCard StandardDeck::DrawNextCard()
{
	// If the container is empty, throw an error
	if (mySize <= 0)
		throw out_of_range("Cannot .DrawNextCard() an empty container. ");
	// preserve the first value
	PlayingCard card = myArray[0];

	// Shift all the existing element value forward by 1 spot:
	for (int moveTo = 0; moveTo < mySize - 1; moveTo++)
	{
		myArray[moveTo] = myArray[moveTo + 1];
	}

	// Make the container smaller by 1
	Resize(mySize - 1);
	// return the former last value
	return card;
}

// for removing an element from the Random access
PlayingCard StandardDeck::DrawRandomCard()
{
	// If the container is empty, throw an error
	if (mySize <= 0)
		throw out_of_range("Cannot .DrawRandomCard() an empty container. ");

	int index = (rand() % mySize) + 1;	//For Access Random value

	// preserve the first value
	PlayingCard card = myArray[index];

	// Shift all the existing element value forward by 1 spot:
	for (int moveTo = index; moveTo < mySize - 1; moveTo++)
	{
		myArray[moveTo] = myArray[moveTo + 1];
	}

	// Make the container smaller by 1
	Resize(mySize - 1);
	// return the former last value
	return card;
}

// for removing an element from the Random access
void StandardDeck::Shuffle()
{
	// If the container is empty, throw an error
	if (mySize <= 0)
		throw out_of_range("Cannot .DrawRandomCard() an empty container. ");

	int index = 0, i = 0, ListSize = mySize;	//For Access Random value
	int TrackCardRandomOrderList[ListSize] = { 0 };	//For avoid override value

	//Ace of Heart Card logic to be added
	// preserve the first value
	PlayingCard card = myArray[index];
	
	// Shift all the existing element value forward by 1 spot:
	for (int moveTo = 0; moveTo < mySize - 1; moveTo++)
	{
		Retry:
		index = (rand() % mySize) + 1;
			while (i <= ListSize) {
				if (index == TrackCardRandomOrderList[i]) {
					goto Retry;	//if given number already assigend then retry for another number
				}
				i++;
			};
		TrackCardRandomOrderList[i++] = index;
		myArray[moveTo] = myArray[moveTo + 1];
	}

	// Make the container smaller by 1
	Resize(mySize - 1);
	// return the former last value
	return card;
}
