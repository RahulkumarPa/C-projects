/** DynamicObjectArrays.cpp
 *	
 *	In this example program we created a simple array of objects dynamically.
 *   
 *	@author		<YOUR-NAME>
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		3 Mar 2018 <update to today's date>
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#include <iostream>
#include <iomanip>  // for output formatting
#include <cstdlib>  // for rand()
#include <ctime>	// for time()
#include <vector> 	// for vectors
#include "MyConsoleInput.h" // for numeric input validation from the console.
#include "MyPlayingCard.h"	// for class PlayingCard
using namespace std;	

int main()
{
	try
	{
		// DECLARATIONS
		const int MAXIMUM_CARDS = 10;
		int numberOfCards; // a variable to determine the number of cards
		PlayingCard *cards; // a pointer to hold the address of the array of cards
		
		// Output an information header
		cout << "Dynamic Object Arrays" << endl
			 << "=====================" << endl;
		
		srand(time(NULL)); // seed the random number algorithm 
		
		// INPUT
		// prompt for the number of cards
		cout << "How many cards do you want? "; 
		// get the number of cards
		numberOfCards = ConsoleInput::ReadInteger(1, MAXIMUM_CARDS);
		
		// PROCESSING
		
		cards = new PlayingCard[numberOfCards]; // create the array
		
		// For each card
		for(int index = 0; index < numberOfCards; index++)
		{
			// determine a random suit number
			int suit = rand() % PlayingCard::SUITS;
			// determine a random rank number
			int rank = 1 + rand() % PlayingCard::RANKS;
			// set the rank, suit, and flip the current card
			cards[index].SetRank(rank);
			cards[index].SetSuit(suit);
			// flip the current card
			cards[index].FlipCard();
		}
	
		// OUTPUT
		cout << "\nHere are the your cards: " << endl;
		// Using a for loop to traverse the array
		for(int index = 0; index < numberOfCards; index++)
		{
			// display the card
			cout << "\t" << cards[index].ToString() << endl;		 
		}
		
		// free the memory
		delete [] cards;
		
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

