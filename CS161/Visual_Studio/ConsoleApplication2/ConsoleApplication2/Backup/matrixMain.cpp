/*************************************************************************************
** Program name: matrixMain.cpp is the matrixMain class function implementation file.
** Author:  Byron Kooima
** Date: 2017/06/30
** Description: CS162 Week1 Lab1
** The Main program allows the user to select the size of the matrix (2x2 or 3x3) and
** enter values to fill that matrix. The program then finds the determinant using the 
** appropriately named function.
**
** Citation: Sections of this code were referenced from 
** http://www.cplusplus.com/forum/beginner/206474/
***************************************************************************************/

#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>

int main()
{
	int mSize;                      //variable to represent size of matrix
	int detVal;							 //variable to represent determinant

	//Prompts user to enter desired matrix size
	std::cout << "\nThis program reads in a square matrix (2x2 or 3x3) \n";
	std::cout << "and finds the determinant of the supplied matrix values. \n \n";
	std::cout << "Please enter 2 for a 2x2 matrix or 3 for a 3x3 matrix. \n";
	std::cin >> mSize;

	//Input validation 
    // TODO: move to reusable function
	while ((mSize < 2) || (mSize > 3))
	{
		std::cout << "Matrix size must be 2 or 3. \n";
		std::cin >> mSize;
	}

	//Creates matrix based on user input
	int** iMatrix = new int *[mSize];			//Matrix rows
	for (int mRow = 0; mRow < mSize; mRow++)
	{
		iMatrix[mRow] = new int[mSize];			//Matrix columns
	}

	//Calls getMatrix to create user defined matrix
	readMatrix rM;
	rM.getMatrix(iMatrix, mSize);

	//Calls getDeterminant to calculate the determinant of user defined matrix.
	determinant dM;
	detVal = dM.getDeterminant(iMatrix, mSize);

	//Print the user defined matrix on screen
	std::cout << "\nUser defined Matrix.\n";
	for (int i = 0; i < mSize; i++)
	{
		std::cout << std::endl;
		std::cout << "[";							// Display matrix row
		for (int j = 0; j < mSize; j++)
		{
			std::cout << iMatrix[i][j] << " ";		//Display the value of matrix element
		}
		std::cout << "]";
	}
	std::cout << std::endl;

	std::cout << "\nThe determinant of the " << mSize << "x" << mSize << " user defined matrix is:  " << detVal << " \n" << std::endl;

	//Frees dynamically allocated memory
	for (int mRow = 0; mRow < mSize; mRow++)
	{
		delete[] iMatrix[mRow];
	}
	delete[] iMatrix;
	iMatrix = 0;

	return 0;
}