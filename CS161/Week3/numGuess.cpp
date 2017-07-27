/****************************************************************
** Author:  Byron Kooima
** Date: 2017/01/22
** Description: CS161 Week3 Assignment 3 - Project 3.c
**              This program prompts the user for an integer that
**              a player will try to guess. The program will then
**              accept prompt for the guess and display if the
**              guess is too high or too low. The program will 
**              loop until the correct answer is guessed.
****************************************************************/

#include <iostream>

// Add using statement so we don't need to use std::
using namespace std;
 
int main()
{
    int inputNum, guessNum, guessCnt;

// Have the user input an integer.    
    cout << "Enter the number for the player to guess." << endl;
    cin >> inputNum;
    guessCnt = 0;
    
// Loop until correct number is guessed
    do
    {
       // Have a player enter a guess.
       cout << "Enter your guess." << endl;
       cin >> guessNum;
       
       // If guess is too low, let user know
       if (guessNum < inputNum)
          {
            cout << "Too low - try again." << endl;
          }
       // If guess is too high, let user know
       else if (guessNum > inputNum)
          {
            cout << "Too high - try again." << endl;
          }
       
       // Increment guess counter
       guessCnt++;
     }  while (guessNum != inputNum);

    // Output number of guesses to get correct answer
    cout << "You guessed it in " << guessCnt << " tries." << endl;
    
    return 0;
}
