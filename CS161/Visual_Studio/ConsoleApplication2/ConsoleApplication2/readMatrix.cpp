/*************************************************************************************
** readMatrix.cpp is the readMatrix class function implementation file.
** Author:  Byron Kooima
** Date: 2017/06/30
** Description: CS162 Week1 Lab1
** The readMatrix function has two parameters: a pointer to a 2D array and an integer
** as the size of the matrix. The function prompts the user to fill a square matrix
** and store the input into the 2D array.
***************************************************************************************/

#include "readMatrix.hpp"
#include <iostream>

void readMatrix::getMatrix(int **mat, int mSize)
{
	// Provide user instructions
	std::cout << "\n Please enter values into the " << mSize << "x" << mSize << " matrix. \n";
	std::cout << "The prompt will accept row values sequentially from left to right. \n";
	std::cout << std::endl;

	for (int i = 0; i < mSize; i++)
	{
		std::cout << "Enter row " << i + 1 << " values: \n";
		for (int j = 0; j < mSize; j++)
		{
			std::cout << "Column value " << (j + 1) << ":  ";
			std::cin >> mat[i][j];
 		}
	}
}
