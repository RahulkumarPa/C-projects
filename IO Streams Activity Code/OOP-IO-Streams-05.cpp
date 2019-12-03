/** OOP-IO-Streams-05.cpp
 *	
 *	Guided Activity:
 *	We will complete a program that will attempt to read from a text file. 
 *	Code a loop to read each item description and price and output them 
 *	neatly in two columns. 
 *	   
 *	@author		Rahulkumar Patel
 *	@version	2015.01
 *	@since		30-07-2018
 *	@see 		Bronson, G. (2012).  Chapter 9 I/O Streams and Data Files. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
#include <iomanip>
#include <fstream>	// needed for ifstream class
using namespace std;

int main()
{
	// DECLARATIONS
	string fileName = "prices.txt";	// hold the file name to open
	ifstream inFile;		// an ifstream object to connect to the file
	string description;		// holds the item description read from the file
	double price;			// holds the item price read from the file
  	int returnValue = 0; 	// holds the return value for main()
	
	
	cout << "Unit 6, Activity 5" << endl
		 << "=====================" << endl;	 
	
	// Open the file	 
    inFile.open(fileName.c_str());
 	
 	if(inFile.fail()) // If the input file could not be opened
 	{
 		// Inform the user
		cout << "\nThe file was NOT successfully opened. "
			 << "Check that the file exists" << endl;
		
		// set the return value of main() to 1
		returnValue = 1;  // '1' indicating the program did not 
 	 				      // execute successfully
 	}
 	else
 	{
 		// All is good. We are ready to read from the file!

		// set the console output formatting
		cout  << setiosflags(ios::fixed)
		      << setiosflags(ios::showpoint)
		      << setprecision(2);
		      
        cout << left << setw(10) << "ITEM" 
			 << right << setw(6) << "PRICE" << endl;
		
		// ** Use a loop to read each item description and price and
		// output them neatly in two columns. Note how the column 
		// headings are output for hints to setting up the column 
		// widths and alignments.
        while(inFile.good)
		{ 
		    inFile >> description >> price;
		    cout << left << setw(10) << description
		         << right << setw(6) << price << endl;
		}
		
		inFile >> description >> price;
		while(inFile.good())
		{
			cout << left << setw(10) << description
		         << right << setw(6) << price << endl;
		         
		         inFile >> description >> price;
		}
		
		inFile >> description >> price;
	/*	while(inFile >> description >> price)
		{
			cout << left << setw(10) << description
		         << right << setw(6) << price << endl;
		}
		*/
		string Line;
		getline(inFile,Line);
		while(inFile.good())
		{
			cout << Line <<endl;
			getline(inFile,Line);
		}
		inFile.close(); // close the file.

 	}
 	
	cout << endl << endl;
	return returnValue;
} // end of main

