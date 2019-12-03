/*
	Name:			Rahulkumar Patel, Ian Carlos
	Date:			July 13, 2018
	Description:	This program will have the user enter a series of Cartesian
					points which will be stored in a vector, then calculated and 
					have the total distance between each potints in sequence.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cfloat>
#include <vector>
#include "MyConsoleInput.h"
#include "MyCartesianPoint.h"

using namespace std;

/*
	TotalDistance function
	- Will calculate the total distance between each point.
	
	@param		points - the vector<int> to calculate total distance, passed by const reference
	@returns	total distance of each sequence
*/
int TotalDistance(const vector<CartesianPoint> &points);

int main() 
{
	try
	{
		CartesianPoint::SetLimit(10);				// Set all CartesianPoint objects to 10.
		vector<CartesianPoint> points;				// Empty vector of CartesianPoint objects.
		points.push_back(CartesianPoint(0,0));		// Start at 0,0.

		// Variables declaration
		int x, y;									// Store user x and y variables.
		int incr;									// Increment counter?
		int size;										// Store the size of the vector.
		
		
		//To provide information to user
		cout << "You will be travelling from (0,0) to (10,10) in as many steps you like. Enter (10,10) to end." << endl;
		
		// Create a loop, that run until user not entered x and y = 10
		do 
		{
			
			cout << "\nMove from (" << points.back().ToString() << ") to where?" << endl;   // To show user's current position
			cout << "\nX: ";
			x = ConsoleInput::ReadInteger(-100, 100);          // To Check user Input  through MyConsoleInput
			cout << "\nY: ";
			y = ConsoleInput::ReadInteger(-100, 100);         // To Check user Input  through MyConsoleInput
			
			points.push_back(CartesianPoint(x, y));	          // Push current values to this vector.
			
			incr++;
			
		}while(x!=10 && y!=10);
			
	size = points.size();	// Store size of points vector in this variable.
		
	cout << "\nThe total distance between " << size << " points is " << TotalDistance(points);
		
	}	

	catch(const exception& ex) //To find an exception					   	   
	{
		cerr << ex.what() << "Please try again."; // display the exception message.
	}
	
	return 0;
}

// TotalDistance function definition.
int TotalDistance(const vector<CartesianPoint> &points)
{
	int totalDistance;								// Stores total distance.
	
	CartesianPoint currentPoint = points.at(0);		// Object related to CartesianPoint which will be used as an identifier.
	
	// Debugging header.
	cout << "\nDEBUGGING ONLY:" << endl;
	
	// Show debug message to show the user to see if the distance(s) are being calculated correctly.
	for(int index = 1; index < points.size(); index++)
	{
		cout << setprecision(2)
		<< right << setw(10) << currentPoint.ToString() << "->"						// Convert stored user input into string format.
		<< left << setw(10) << currentPoint.ToString() << ":"						// Convert stored user input into string format.
		<< right << setw(10) << currentPoint.GetDistanceTo(points.at(index));		// Calculate distance between this and that point.
		
		
		
		currentPoint = points.at(index);											// Make from point equal to this point.
	}	
	totalDistance += currentPoint.GetDistanceTo(points.size());				// Sum up overall distance.
	return totalDistance;
}
