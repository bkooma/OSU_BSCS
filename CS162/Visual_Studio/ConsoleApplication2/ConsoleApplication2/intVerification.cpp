/*****************************************************************************************
** Function name: intVerification.cpp is the intVerification function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/02
** Description: CS162 Reusable Int Verification Function
** The intVerification function bounds the inputs allowed from the user. The function
** requires the cpp file calling it to pass the (low,high) of an int from the user
**
** Citation: Sections of this code were referenced from
** http://www.cplusplus.com/forum/beginner/79055/
*******************************************************************************************/

#include "intVerification.hpp"
#include <iostream>

double getNum(void)
{
	double num;
	if (!(std::cin >> num))
	{
		std::cin.clear(); // fix cin
		std::cin.ignore(80, '\n');  // remove what broke it from the buffer
		throw  "Numbers only";
	}
	std::cin.ignore(80, '\n');  // clear the buffer of any remaining characters
	return num;
}

int getInt(void)
{
	double num = getNum(); // getNum() ensures a numerical input
	if (num != static_cast<int>(num))
	{
		throw "Integers only.";
	}
	return static_cast<int>(num);
}

int getIntInRange(int low, int high, char* s)
{
	int num = getInt();  // Ensures a number and an integer
	if (num < low || num > high)
	{
		throw s;
	}
	return num;
}