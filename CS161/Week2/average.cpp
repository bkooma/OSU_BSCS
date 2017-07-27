/****************************************************************
** Author:  Byron Kooima
** Date: 2017/01/14
** Description: CS161 Week2 Assignment 2 - Project 2.a
**              This program prompts the user for five inputs and
**              outputs the average of the numbers.
****************************************************************/

#include <iostream>

// Add using statement so we don't need to use std::
using namespace std;
 
int main()
{
    double avgNum1, avgNum2, avgNum3, avgNum4, avgNum5;
    double avgSum;
    double avgCalc;

// Have the user input 5 numbers.    
    cout << "This program takes five numbers and outputs the average.\n" << endl;
    cout << "Please enter five numbers." << endl;
    cin >> avgNum1;
    cin >> avgNum2;
    cin >> avgNum3;
    cin >> avgNum4;
    cin >> avgNum5;
    
//  Find the sum of the five numbers and calculate the average
    avgSum = avgNum1 + avgNum2 + avgNum3 + avgNum4 + avgNum5;
    avgCalc = avgSum / 5;

//  Display the average    
    cout << "The avergae of those numbers is: \n" << avgCalc << endl;
    
    return 0;
}
