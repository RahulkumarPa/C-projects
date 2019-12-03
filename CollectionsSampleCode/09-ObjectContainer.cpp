/** 09-ObjectContainer.cpp
 *	
 *  In this version, we create a container class of PlayingCard objects rather than ints.
 *
 *	@author		Thom MacDonald
 *	@version	2018.02
 *	@since		Jul 2018
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#include <iostream>		
#include <stdexcept>
#include <sstream>
#include "PlayingCard.h"
#include <ctime>

using namespace std;

// Container class
class PlayingCards
{
	private:
		PlayingCard * myArray;  // pointer to a dynamically-allocated c-array 
		int mySize;		// the size of the c-array
		
	public:
		PlayingCards(int size); // constructor

		~PlayingCards() { delete [] myArray;} // destructor
		PlayingCards(const PlayingCards &source); // copy constructor
		PlayingCards& operator=(const PlayingCards &source); // assignment operator	

		int Size() const {return mySize;} // mySize accessor
		PlayingCard operator[](int index) const;  // accessor version of []
		PlayingCard& operator[](int index);		  // mutator version of []

		string DebugString() const; // an accessor to show info about the state of the object		

		void Resize(int newSize);	// re-sizing mutator

		void PushBack(PlayingCard newCard); // for adding an element to the back/end
		PlayingCard PopBack();				 // for removing an element from the back/end
		void PushFront(PlayingCard newCard); // for adding an element to the front/start
		PlayingCard PopFront();	  			// for removing an element from the front/start

}; 


int main()
{
	/*	In main(), we will test some functionality of the PlayingCards class
	 *	This is not a comprehensive test of all functionaility however.
	 */
	
	try
	{
		int size; 	// holds user input for the number of elements to store
	    
		// Prompt for and get the number of elements from the user
		cout << "\n\nHow many playing cards do you want to store in the OBJECT? ";
		cin >> size;		
		fflush(stdin);
		
		PlayingCards cards(size); // Declare a container object
		
		// Show the object debug info
		cout << "\nAs Initialized: " << endl;
		cout << cards.DebugString() << endl;
		cin.ignore();
		
		// Randomize the playing cards in the object
		cout << "\nRandomizing cards in the OBJECT:" << endl;
		srand(time(NULL)); // seed the random number generator
		// Loop for each element of the 'container'
		for(int i = 0; i < cards.Size(); i++)
		{
			// give the playing card a random suit and rank
			cards[i].SetSuit(rand() % (PlayingCard::SUITS)); 
			cards[i].SetRank(1 + rand() % (PlayingCard::RANKS)); 
	
			// Output the element value to the console
			cout << "\n[" << i << "]: " << (string) cards[i] << endl;
		}
		cin.ignore();
		
		// Show each playing card as it is removed from the object
		cout << "\nRemoving cards from the OBJECT:" << endl;
		while(cards.Size() > 0)
		{
			cout << "Removing "<< (string) cards.PopFront() << endl;
		}
		
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
PlayingCards::PlayingCards(int size)
{
	// Allocate a new array dynamically on construction
	myArray = new PlayingCard [size]; // may throw bad_alloc exception
	mySize = size; // set the size
}

// copy constructor
PlayingCards::PlayingCards(const PlayingCards &source)
{
	// Allocate a new array dynamically on construction
	mySize = source.mySize; // set the size
	myArray = new PlayingCard [mySize]; // may throw bad_alloc exception
	// Initialize each element to the corresponding playing card in the source object
	for(int i = 0; i < mySize; i++)
		myArray[i] = source.myArray[i];
}

// assignment operator
PlayingCards& PlayingCards::operator=(const PlayingCards &source)
{
	delete [] myArray; // free up the old memory
	// Allocate a new array dynamically on construction
	mySize = source.mySize; // set the size
	myArray = new PlayingCard [mySize]; // may throw bad_alloc exception
	// Initialize each element to the corresponding playing card in the source object
	for(int i = 0; i < mySize; i++)
		myArray[i] = source.myArray[i];
	
	return *this;
} 

// an accessor to show info about the state of the object	
string PlayingCards::DebugString() const
{
	stringstream debug;
	debug << "\n==================== DEBUG ====================" << endl
		  << "myArray: " << myArray << endl
		  << "mySize:  " << mySize << endl;
	for(int i = 0; i < mySize; i++)
	{
		debug << "[" << i << "]: " << (string) myArray[i] << endl;
	}

	debug << "\n===============================================" << endl;
	return debug.str();
}

// operator [] accessor for an element of myArray
PlayingCard PlayingCards::operator[](int index) const
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= mySize)
		throw out_of_range("Index must be between 0 and " + to_string(mySize - 1) + ".");
	// return the playing card stored at element index BY VALUE
	return myArray[index]; 
}	
// operator [] mutator for an element of myArray
PlayingCard& PlayingCards::operator[](int index) 
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= mySize)
		throw out_of_range("Index must be between 0 and " + to_string(mySize - 1) + ".");
	// return a REFERENCE to the playing card at index
	return myArray[index]; 
}

// re-sizing mutator
void PlayingCards::Resize(int newSize)
{
	PlayingCard * newArray = new PlayingCard[newSize]; // throws bad_alloc on failure
	int elementsToCopy = (mySize < newSize)? mySize : newSize; // whichever is smaller
	
	// Copy each each existing playing card to the new array
	for(int i = 0; i < elementsToCopy; i++)
		newArray[i] = myArray[i];

	// Set the new size
	mySize = newSize;
	
	// Delete the old array
	delete [] myArray;
	
	// Set the myArray pointer to the new array
	myArray = newArray;
}

// for adding an element to the back/end
void PlayingCards::PushBack(PlayingCard newCard)
{
	// Make the container larger by 1
	Resize(mySize + 1);
	// Add the new value to the end
	myArray[mySize - 1] = newCard;
}

// for adding an element to the front/start
void PlayingCards::PushFront(PlayingCard newCard)
{
	// Make the container larger by 1
	Resize(mySize + 1);
	
	// Shift all the existing element value backward 1 spot:
	for(int moveTo = mySize - 1; moveTo > 0; moveTo--)
	{
		myArray[moveTo] = myArray[moveTo - 1];
	}
	
	// Add the new value to the front
	myArray[0] = newCard;
}

// for removing an element from the back/end
PlayingCard PlayingCards::PopBack()
{
	// If the container is empty, throw an error
	if(mySize <= 0)
		throw out_of_range("Cannot .PopBack() an empty container. ");
	// preserve the last value
	PlayingCard card = myArray[mySize - 1];
	// Make the container smaller by 1
	Resize(mySize - 1);
	// return the former last value
	return card;
}

// for removing an element from the start/front
PlayingCard PlayingCards::PopFront()
{
	// If the container is empty, throw an error
	if(mySize <= 0)
		throw out_of_range("Cannot .PopFront() an empty container. ");
	// preserve the first value
	PlayingCard card = myArray[0];
	
	// Shift all the existing element value forward by 1 spot:
	for(int moveTo = 0; moveTo < mySize - 1; moveTo++)
	{
		myArray[moveTo] = myArray[moveTo + 1];
	}
	
	// Make the container smaller by 1
	Resize(mySize - 1);
	// return the former last value
	return card;
}
