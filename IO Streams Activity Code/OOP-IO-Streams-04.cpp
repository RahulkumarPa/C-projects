/** OOP-IO-Streams-04.cpp
 *	
 *	Guided Activity:
 *	We will complete a simple program that will write text to an output file.
 *	Add the code to write the following data to prices.txt:
 *		Kettle     23.95
 *		Toaster    25.49
 *		Stove      549.99
 *		Microwave  99.00
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
	ofstream outFile;		// an ofstream object to connect to the file
  	int returnValue = 0; 	// holds the return value for main()
	
	cout << "Unit 6, Activity 4" << endl
		 << "==================" << endl;	 
	
	// Open the file	 
    outFile.open(fileName.c_str());
 	
 	if(outFile.fail()) // If the output file could not be opened
 	{
 		// Inform the user
		cout << "\nThe file was NOT successfully opened for output." << endl;
		// set the return value of main() to 1
		returnValue = 1;  // '1' indicating the program did not 
 	 				      // execute successfully
 	}
 	else
 	{
 		// All is good. We are ready to write to the file!

		// **set the output file stream formats
		outFile << setiosflags(ios::fixed)
		        << setiosflags(ios::showpoint)
		        << setprecision(2);
		// **send data to the file
		outFile << "Kettle   "<< 23.95 << endl
			    << "Toaster   "<< 25.49 << endl
			    << "Stove   "<< 549.99 << endl
			    << "Microwave   "<< 99.00 << endl
		outFile.close(); // close the file.
		
		// Inform the user
		cout << "\nThe file has been successfully written to." << endl;
 	}
 	
	cout << endl << endl;
	return returnValue;
} // end of main

