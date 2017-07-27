/************************************************************************************
** smallSort2.cpp
** Author:  Byron Kooima
** Date: 2017/03/01
** Description: CS161 Week8 Assignment 8 Project 8.a 
** This function takes as parameters the addresses of three int variables and sorts the
** ints at those addresses into ascending order.
**************************************************************************************/

#include <iostream>

//findMode function    
void smallSort2 (int* num1, int* num2, int* num3)
{
	int temp;
	//  First check of the first two integers.
	if (*num1 > *num2)
	{
		temp = *num1;
		*num1 = *num2;
		*num2 = temp;
	}
	//  Next check of last two integers.
	if (*num2 > *num3)
	{
		temp = *num2;
		*num2 = *num3;
		*num3 = temp;
	}

	//  Last check of the first two integers.
	if (*num1 > *num2)
	{
		temp = *num1;
		*num1 = *num2;
		*num2 = temp;
	}
}

int main()
{
	int a = 14;
	int b = -90;
	int c = 2;
	smallSort2(&a, &b, &c);
	std::cout << a << ", " << b << ", " << c << std::endl;
}