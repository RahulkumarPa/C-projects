	
#include <iostream>
#include <iomanip>	//To Formatting Output
#include <fstream>	//To use  ifstream class
#include <string>		//To use strng class
using namespace std;

int main()
{
	string sourceFileName = "hours.txt";	// for input text file
	string destinationFileName = "pay.txt";//for output text File
    
	// instance for object of input abd outp ut file	
	ifstream inFile;		
	ofstream outFile;		
	int returnValue = 0; 	
	int i =0;					//variable for loop
	double grandTotal = 0;	//hold the grand total of all employees
	struct payRecord			//Structure for Employees record
	{
		string firstName;			//to store First name of employee
		string lastName;		   //to store Last name of  employee
		double weeklyHours;		//to store Weekly Hours of employee
		double wagePerHours;		//to store Wage Per Hours of employee
		double weeklySalary;		//to store Weekly total Salary
	};
	
	//structure array for Employees
	payRecord pR[5000];			
	// to open the input file	 
    inFile.open(sourceFileName.c_str());
	 //to open the output file 
 	 outFile.open(destinationFileName.c_str());
	if(inFile.fail()) // If the input file can not be opened
 	{
 		// Prompt to user
		cout << "\nThe file was NOT successfully opened. "
			 << "Check that the file exists" << endl;
		
		// set the return value of main() to 1
		returnValue = 1;  // '1' indicating the program did not execute successfully
 	 				       
 	}
 	
 	else
 	 {
 		outFile << "Prepared BY: Ian," << " Rahulkumar Patel" << endl << endl ;
		outFile << "***************PAY FOR THIS WEEK*******************" << endl;
		outFile << "===================================================" << endl << endl ;
		// set the console output formatting
		outFile  << setiosflags(ios::fixed)
		      << setiosflags(ios::showpoint)
		      << setprecision(2);
		//Output the Title at top of each Entity
      outFile << right << setw(7) << "Name" << right << setw(15) << "Hours*" << right << setw(13) <<"Wage*" 
		<< right << setw(15) << "Salary*" <<endl ;
		
		
		//to read the first record from input file
		inFile >>pR[i].firstName>>pR[i].lastName>>pR[i].weeklyHours>>pR[i].wagePerHours;
		//to calculate the Weekly Salary for first record.
		pR[i].weeklySalary = (pR[i].weeklyHours) * (pR[i].wagePerHours);
		//to check if the output file fail
		if(outFile.fail())
		{
			cout <<"\nThe file was NOT successfully opened.";
		}
		else
		{
			//While Loop run stile the end of the input file
			while (!inFile.eof())			
			{
				//to calculate the Grand Total for all employees
				grandTotal += pR[i].weeklySalary;
				//to print the entity in the output file
				outFile << pR[i].firstName.at(0) << "." << right << setw(10) << pR[i].lastName
				 << right << setw(9) << pR[i].weeklyHours <<right << setw(9) << "$" << pR[i].wagePerHours 
				 << right << setw(9) << "$" <<pR[i].weeklySalary << endl;
				//to increaement the incraeament variable
				i++;
				//to read the record from input file
				inFile >>pR[i].firstName>>pR[i].lastName>>pR[i].weeklyHours
						 >>pR[i].wagePerHours;
				//to calculate the Weekly Salary
				pR[i].weeklySalary = pR[i].weeklyHours * pR[i].wagePerHours;
			}
			outFile << "===================================================" << endl;
			//Print the Grand Total in output text file
			outFile << right << setw(36) << "Total:"<< right << setw(7) << "$" << grandTotal
					  <<  endl << endl <<endl ;
			
		
	}
	    // Close the input and output text file.
		outFile.close(); 
		inFile.close(); 
 	}
	cout << endl << endl;
	return returnValue;
}
