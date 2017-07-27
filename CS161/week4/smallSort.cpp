/****************************************************************
** Author:  Byron Kooima
** Date: 2017/01/28
** Description: CS161 Week4 Assignment 4 - Project 4.b
**              This function takes three int parameters by reference
**              and sorts the values into ascending order.
****************************************************************/

#include <iostream>

// Add using statement so we don't need to use std::
using std::cin;
using std::cout;
using std::endl;

void smallSort(int& val1, int& val2, int& val3)
{
    int temp;
//  First check of the first two integers.
    if (val1 > val2)
    {
      temp = val1;
      val1 = val2;
      val2 = temp;  
    }  
//  Next check of last two integers.
    if (val2 > val3)
    {
      temp = val2;
      val2 = val3;
      val3 = temp;
     }

//  Last check of the first two integers.
    if (val1 > val2)
    {
      temp = val1;
      val1 = val2;
      val2 = temp;
     }
}

/*
int main()
{
    int value1, value2, value3;

// Have the user input the time an object has fallen.
    cout << "Please enter the first integer. " << endl;
    cin >> value1;
    cout << "Please enter the second integer." << endl;
    cin >> value2;
    cout << "please enter the third integer." << endl;
    cin >> value3;

    smallSort(value1, value2, value3);

    cout << value1 << ", " << value2 << ", " << value3 << endl;
  
    return 0;
}
*/
