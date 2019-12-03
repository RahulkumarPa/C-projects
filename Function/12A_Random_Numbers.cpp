/** Random_Numbers.cpp
 *	
 *	In this program, we will examine seeding, generating and scaling random numbers.
 *	   
 *	@author		Thom MacDonald
 *	@author		<your name>
 *	@version	2018.01
 *	@since		Jan 2018
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>	
#include <cstdlib> // for srand(), rand(), RAND_MAX
#include <ctime> // for time(), ctime(), time_t

using namespace std;

int main()
{
	// DECLARATIONS
	const unsigned int QUANTITY = 10; 	// the quantity of random numbers we wish to produce
	const int MIN_VALUE = 2;			// the minimum random value desired
	const int MAX_VALUE = 12;			// the maximum random value desired
	time_t startTime = time(NULL);		// a variable to hold the current time.
	int randomValue;					// a variable to hold a random value
	
	srand(time(NULL)); // seed the random number algorithm with time()
	
	cout << "Random Numbers" << endl
		 << "==============" << endl
		 << ctime(&startTime) << endl; // ctime converts the time_t value to a string
		
	cout << "\nThe maximum pseudo-random that can be generated is " << RAND_MAX << "." << endl;
	cout << "\nGenerating " << QUANTITY << " random numbers:\n" << endl;
	
	for(int loopCount = 0; loopCount < QUANTITY; loopCount++)
	{
		// 	Random value is scaled between MIN_VALUE and MAX_VALUE (inclusively).
		randomValue = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1); 
		
		cout << randomValue << endl;
	}
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main


