/****************************************************************
** Author:  Byron Kooima
** Date: 2017/01/22
** Description: CS161 Week3 Assignment 3 - Project 3.b
**              This program prompts the user for the name of an
**              input file and then attempts to open it. If file
**              can be opened, the list of integers are read in,
**              find the sum, and output the sum to a file.
****************************************************************/

#include <iostream>
#include <string>
#include <fstream>

// Add using statement so we don't need to use std::
using namespace std;
 
int main()
{
    ifstream inputFile;          // File stream object
    string fileName;             // User entered file name
    int value, total;            // Integers from input file

    // Prompt the user for the name of a file
    cout << "This program reads integers from an input file \n";
    cout << "and outputs the sum of the values to a file. \n";
    cout << "Enter the name of the file to read from: ";
    cin >> fileName;    

    // inputFile object equals 0 if open fails, is non-zero if open is successful
    inputFile.open(fileName);
    
    // Check if open succeeds
    if (inputFile)
      {      
        // Loop until EOF
        while (inputFile >> value)
          {
            total += value;      //Add value to total
          }
        
        // Close the input file
        inputFile.close();

        // Open output file
        ofstream outputFile;
        outputFile.open("sum.txt");
        
        // Write sum to output file
        outputFile << total;

        // Close the output file
        outputFile.close();
      }
    else
      {
        cout << "Could not access file." << endl;
      }

    return 0;
}
