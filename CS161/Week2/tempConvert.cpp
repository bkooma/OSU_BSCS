/****************************************************************
** Author:  Byron Kooima
** Date: 2017/01/17
** Description: CS161 Week2 Assignment 2 - Project 2.b
**              This program prompts the user for a Celsius 
**              temperature and outputs the corresponding
**              Fahrenheit temperature
****************************************************************/

#include <iostream>

// Add using statement so we don't need to use std::
using namespace std;
 
int main()
{
    double inCel, outFah, slope, slope2;

// Have the user input a number of cents.    
    cout << "This program takes a Celcius temperature input and "
         << "outputs the corresponding Fahrenheit temperature" << endl;
    cout << "Please enter a Celsius temperature." << endl;
    cin >> inCel;

//  Find the equivalent Fahrenheit temperature
    slope = static_cast<double>(9)/5;
    outFah = slope * inCel + 32; 

//  Display the corresponding Fahrenheit temperature
    cout << "The equivalent Fahrenheit temperature is:" << endl;
    cout << outFah << endl;
    
    return 0;
}
