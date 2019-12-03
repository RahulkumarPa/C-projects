/** OOP-IO-Streams-02.cpp
 *	
 *	Guided Activity:
 *	We will complete a simple program that will attempt to open a text file 
 *	for writing (output), prompting the user for an overwrite decision.
 *	Add the code for the following:
 *	- Open the file in input mode to see if it exists
 *	- Open the file in output mode, creating a new file
 *	- Open the file in append mode, put the position marker at the end
 *	- Checking for a successful file opens.
 *	- Closing the files
 *	   
 *	@author		Rahulkumar Patel
 *	@version	2015.01
 *	@since		30-07-2018
 *	@see 		Bronson, G. (2012).  Chapter 9 I/O Streams and Data Files. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
#include <fstream>	// needed for ifstream class
using namespace std;

/**	GetOverwriteDecision function
 *  - Displays a menu to the user and gets their decision to 
 *	  overwrite, append, or keep and existing file.
 *	@return		'O' (overwrite), 'A' (append), or 'K' (keep)
*/
char GetOverwriteDecision();

int main()
{
	// DECLARATIONS
	ifstream fileTester;	// an object to test if the file exists
	ofstream outFile;		// an ofstream object to connect to the file
	string fileName = "";	// hold the file name to open
  	int returnValue = 0; 	// holds the return value for main()
	char overwriteChoice = 'O'; 	// holds the user overwrite decision; defaults to 'O'
	
	cout << "Unit 6, Activity 2" << endl
		 << "==================" << endl;	 
		 
 	// INPUT
 	// Prompt for and get the filename
 	cout << "Enter the name of the file you wish to write to: ";
 	getline(cin, fileName);

    // **Attempt to open the file in input mode to see if it exists
       			 		 	 	  	// .c_str accesses the C-style string
									// stored inside a std::string 
	fileTester.open(fileName.c_str())								
	
	// ** Check for a SUCCESSFUL open: the file exists!
	if(fileTester.good())
	
	{
		// Inform the user that the file exists and prompt for overwrite
		cout << "A file by the name " + fileName + " exists.\n";
		// prompt for a get the user's overwrite choice
		overwriteChoice = GetOverwriteDecision();
		// ** close the file.
		fileTester.close();
	}
	
	// Does the user wish to proceed? (true if the file didn't exist)
	if(overwriteChoice != 'K') // NOT keep and exit
	{
		// Does the user what to overwrite OR file didn't exist
		if(overwriteChoice == 'O') 
		{
			// **open the file, creating a new file
			outFile.open(fileName.c_str());			
		}
		else // overwriteChoice == 'A'
		{
			// **open the existing file, put the position marker at the end
			outFile.open(fileName.c_str(), ios::app);
		}
		
		// **Either way (out or app), did the file open?
		if(outFile.fail())
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
			 cout << "\nThe file has been successfully opened for output." << endl;
			 // statements to write to the file would be placed here
			 
			 
			 // **close the file.
			 outFile.close();
		}
		
	} // end of if

	
	cout << endl << endl;
	return returnValue;
} // end of main

// GetOverwriteDecision definition
char GetOverwriteDecision()
{
 	char overwriteChoice; // holds the user's decision
	
	do // start looping until user enter's a valid choice
	{
		// Prompt the user to overwrite, append, or exit
		cout << "\nPlease select your choice: " << endl
			 << "\'O\' - overwrite the existing file." << endl
			 << "\'A\' - add to the end of the existing file." << endl
			 << "\'K\' - keep the existing file and exit." << endl
			 << ": ";
	
		// get a single char from the user
		cin >> overwriteChoice;
		// clear the input buffer
		fflush(stdin);
	    // convert the char to uppercase
		overwriteChoice = toupper(overwriteChoice);
		// display a message to the user based on their input
		switch(overwriteChoice)
		{
			case 'O': // overwrite
				cout << "\nThe existing file will be overwritten." << endl;
				break;
			case 'A': // append
				cout << "\nThe existing file will be appended." << endl;
				break;
			case 'K': // keep and exit
				cout << "\nThe existing file will NOT be modified." << endl;
				break;
			default:  // invalid choice
				cout << "\nPlease enter \'O\', \'A\' or \'K\'." << endl;
		}
	// keep looping while user input is not 'O','A', or 'K'
	}while (!(overwriteChoice == 'O' || overwriteChoice == 'A' || overwriteChoice == 'K'));
	
	return overwriteChoice;
}
