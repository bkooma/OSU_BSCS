/****************************************************************
** Author:  Byron Kooima
** Date: 2017/01/28
** Description: CS161 Week4 Assignment 4 - Project 4.a
**              This function takes falling time as an argument.
**              The function returns the distance in meters that 
**              the object has fallen in that time.
****************************************************************/

#include <iostream>
#include <cmath>

// Add using statement so we don't need to use std::
using std::cin;
using std::cout;
using std::endl;

double fallDistance(double fallingTime)
{
    const double Grav = 9.8;    
    return (1.0 / 2) * Grav * pow(fallingTime, 2.0);
}

/* 
int main()
{
    double fallTime, distance;

// Have the user input the time an object has fallen.    
    cout << "Please enter the time an object has fallen." << endl;
    cin >> fallTime;
    distance = fallDistance(fallTime);

    cout << "The distance the object fell was: " << distance << " meters." << endl;

   
    return 0;
}
*/
