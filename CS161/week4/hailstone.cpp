/*******************************************************************
** Author:  Byron Kooima
** Date: 2017/01/28
** Description: CS161 Week4 Assignment 4 - Project 4.c
**              This function takes a positive integer and starts a
**              hailstone sequence. If integer is even, it is divided
**              by two to get the next integer in the sequence. If 
**              integer is odd, then it is multiplied by three and 
**              add one to get the next integer in the sequence. The
**              function then returns the number of steps it takes to 
**              reach 1.
********************************************************************/

#include <iostream>

// Add using statement so we don't need to use std::
using std::cin;
using std::cout;
using std::endl;

int hailstone(int val1)
{
    int count = 0;
//  Check the integer to see if it is even or odd.
    while (val1 != 1)
    {
      // If it is even, divide by two
      if (val1 % 2 == 0)
       {
         val1 = val1 / 2;
       }
      // Else it is odd and multiply by three and add one
      else
       {
         val1 = val1 * 3 + 1;
       }
      // Increment counter
      count++;
    }  
    // Return only the counter
    return count;
}

// Comment out main for function use.
/*
int main()
{
    int value1, seqCnt;

// Have the user input a random positive integer.
    cout << "Please enter an integer. " << endl;
    cin >> value1;

    seqCnt = hailstone(value1);

    cout << "The integer " << value1 << " took " << seqCnt << " hailstone sequences to get to one." << endl;
  
    return 0;
}
*/
