/****************************************************************
** Author:  Byron Kooima
** Date: 2017/01/14
** Description: CS161 Week2 Assignment 2 - Project 2.c
**              This program prompts the user for a number of 
**              cents and outputs how many of each type of coin
**              would represent that amount
****************************************************************/

#include <iostream>

// Add using statement so we don't need to use std::
using namespace std;
 
int main()
{
    int cents, quarter, dime, nickle, penny;
    int remainder;

// Have the user input a number of cents.    
    cout << "This program takes a number of cents and determines "
         << "the fewest number of coins to represent that number \n" << endl;
    cout << "Please enter an amount in cents less than a dollar." << endl;
    cin >> cents;
//  Find the number of quarters
    quarter = cents / 25; 
    remainder = cents % 25;

//  Find the number of dimes
    dime = remainder / 10;
    remainder = remainder % 10;

//  Find the number of nickles
    nickle = remainder / 5;
    remainder = remainder % 5;

//  Find the number of pennies
    penny = remainder;

//  Display the corresponding change
    cout << "Your change will be:" << endl;
    cout << "Q: " << quarter << endl;
    cout << "D: " << dime << endl;
    cout << "N: " << nickle << endl;
    cout << "P: " << penny << endl;
    
    return 0;
}
