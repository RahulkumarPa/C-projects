/** ObjectVectors.cpp
 *	
 *	In this example program we created a simple vector of objects.
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
		vector<PlayingCard> cards; // empty vector of cards
		
		// Output an information header
		cout << "Object Vectors" << endl
			 << "==============" << endl;
		
		srand(time(NULL)); // seed the random number algorithm 
		
		// INPUT
		// prompt for the number of cards
		cout << "How many cards do you want? "; 
		// get the number of cards
		numberOfCards = ConsoleInput::ReadInteger(1, MAXIMUM_CARDS);
		
		
		// PROCESSING
		cards.reserve(numberOfCards); // reserve enough memory (optional!)
		
		// TO DO: A for loop that, for each card, determines
		// a random suit number, a random rank number, 
		// pushes a card initialized (rank & suit) to the vector
		// thenflips the current card.
		
	
		// OUTPUT
		cout << "\nHere are the your cards: " << endl;
		// Using a counter-based for loop to traverse the vector
		for(int index = 0; index < cards.size(); index++)
		{
			// display the card
			cout << "\t" << cards.at(index).ToString() << endl;		 
		}
		
//		// Using a 'range-based for loop (C++ 11) 
//		for(PlayingCard & card: cards) 
//		{
//			// display the card
//			cout << "\t" << card.ToString() << endl;
//		}
		
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

