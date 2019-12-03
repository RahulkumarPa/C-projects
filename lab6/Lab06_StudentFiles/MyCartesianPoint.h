/** MyCartesianPoint.h
 *	
 *	Definition of class CartesianPoint
 *   
 *	@author		<YOUR-NAME>
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		3 Feb 2018 <update to today's date>
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#ifndef MY_CARTESIAN_POINT_H

#define MY_CARTESIAN_POINT_H

#include <iostream> 		// cin, cout
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range

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
	void SetX(int x) { myX = validateCoordinateValue(x); } 
	void SetY(int y) { myY = validateCoordinateValue(y); } 
	void SetPoint(int x, int y) { SetX(x); SetY(y); }	
	
  /* Static methods: 
		- Can be used to access/mutate static data members
		- Can be called without an object  
	*/
	// get the limit
	static int GetLimit() { return sharedLimit; }
	// set the limit
	static void SetLimit(int limit) { sharedLimit = abs(limit); }

 /* Friend Functions: Nonmember functions/methods that are granted the same 
 		privileges as member methods
 */
 // TO-DO: Add ReadCartesianPoint() to the friends list
 	
	 	
  private: 
  // private data members for the dimensions of the point
    int myX; // x-axis (horizontal) value
    int myY;  // y-axis (vertical) value
    
  // Static data-member: Shared among all objects of this class.
	static int sharedLimit; 
  
  // Helper method for validation  
    int validateCoordinateValue(int value) const;
 
};

// Class definition section

/**  sharedLimit static data-member for CartesianPoint class
 *	 Used to validate the x and y coordinate values.
 */
int CartesianPoint::sharedLimit = INT_MAX;    

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

/** validateCoordinateValue Method for CartesianPoint class
 *	Determines if the parameter is valid for a coordinate value.
 *	@param	value (int) 
 *	@return	the parameter if valid
 *	@throws an out_of_range exception if not in range
 */
 
int CartesianPoint::validateCoordinateValue(int value) const
{
	// if the parameter is within the limits
	if((value < -sharedLimit || value > sharedLimit))
	{
		// throw an exception
		throw out_of_range( "Parameter (" + to_string(value) + ") must be between " 
			+ to_string(-sharedLimit) + " and " + to_string(sharedLimit) + ".");
	}
	return value;
}

#endif

