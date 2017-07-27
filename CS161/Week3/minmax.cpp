/****************************************************************
** Author:  Byron Kooima
** Date: 2017/01/22
** Description: CS161 Week3 Assignment 3 - Project 3.a
**              This program prompts the user for how many
**              integers to enter. The user will then be prompted
**              for that number of integers. After all numbers are
**              entered, the program returns the largest and 
*               smallest of those numbers.
****************************************************************/

#include <iostream>

// Add using statement so we don't need to use std::
using namespace std;
 
int main()
{
    int intNum, intCnt, intInput, intMin, intMax;

// Have the user input the number of integers they want.    
    cout << "How many integers would you like to enter?" << endl;
    cin >> intNum;

// Initialize value of integer counter
    intCnt = 2;

// User enters the number of integers requested
    cout << "Please enter " << intNum << " integers" << endl;
    cin >> intInput;
    
    intMin = intInput;
    intMax = intInput;

// Loop through integers provided by user
    while (intCnt <= intNum)
    {
      cin >> intInput;
      // If integer is less than current min
      if (intInput < intMin)
      {
         // Set min to current integer
         intMin = intInput;
      }
      // If integer is more than current max
      else if (intInput > intMax)
      {
         // Set max to current integer
         intMax = intInput;
      }

// Increment the counter
    intCnt++;
    }

//  Display the min and max integer
    cout << "min: " << intMin << endl;
    cout << "max: " << intMax << endl;
    
    return 0;
}
