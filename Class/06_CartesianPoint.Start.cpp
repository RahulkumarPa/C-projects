/** CartesianPoint.Start.cpp
 *	
 *	In this example program, did the following:
 *		- Examined a simple class with 'instance' data-members, a constructor, accessors, mutators.
 *   
 *	@author		<YOUR-NAME>
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		3 Feb 2018 <update to today's date>
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()

using namespace std;

// class declaration section
class CartesianPoint
{
  public:
  /* Constructor: Used to initialize objects */
    CartesianPoint(int x = 1, int y = 1) { SetPoint(x, y); }
    
  /* Accessors: Used to query the state of the object */    
	int GetX() const { return myX; }
	int GetY() const { return myY; } 
	
    // get the distance between this point and a second point
 	double GetDistanceTo(CartesianPoint pointTo) const; 
 	string ToString() const; // convert the obj to a string.	
	
  /* Mutators: Used to change the state of the object */
	void SetX(int x) { myX = x; } 
	void SetY(int y) { myY = y; } 
	void SetPoint(int x, int y) { SetX(x); SetY(y); }	
		
  private: 
  // private data members for the dimensions of the point
    int myX; // x-axis (horizontal) value
    int myY;  // y-axis (vertical) value
	 
};

// main() function
int main()
{
	// Declarations
	CartesianPoint origin (0, 0); 
	CartesianPoint destination; 
	int tempX; // temporary input variable
	int tempY;  // temporary input variable
	double distance; // to store the distance between two points
	
	try
	{
		// Input
	
		// get the coordinates from the user
		cout << "\nEnter coordinates of the destination point: " << endl;
		// prompt for, read, and store x coordinate:
		cout << "X: ";
		tempX = ConsoleInput::ReadInteger();
		destination.SetX(tempX);
		
		// prompt for, read, and store y coordinate:
		cout << "Y: ";
		tempY = ConsoleInput::ReadInteger();
		destination.SetY(tempY);
		
		// Processing
		// determine the distance between the two points
		distance = origin.GetDistanceTo(destination);
	
		// Output 
		// Show the points and the distance
		cout << fixed << setprecision(3); // formatting
		cout << "\nThe distance between " << origin.ToString()
			 << " and " << destination.ToString() << " is " 
			 << distance << ". " << endl;
	}
	
	catch(exception &ex)
	{
		cerr << ex.what() << " Ending the program." << endl;
	}
		
	// done.
	cout << endl << endl;
	return 0;
} // end of main()

// Class definition section

/** GetDistanceTo Method for CartesianPoint class
 *	Determines the distance between this point and a second point.
 *	@param	pointTo: CartesianPoint
 *	@return	the distance as a double
 */
double CartesianPoint::GetDistanceTo(CartesianPoint pointTo) const 
{
    int xDelta = pointTo.myX - myX; // difference between x values
    int yDelta = pointTo.myY - myY; // difference between y values
    // return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));
} 

/** ToString Method for CartesianPoint class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string CartesianPoint::ToString() const
{
	// declare a stringstream object
	stringstream strOut; 
	// build the string
	strOut << "(" << myX << ", " << myY << ")";
	// return the string
	return strOut.str();
}