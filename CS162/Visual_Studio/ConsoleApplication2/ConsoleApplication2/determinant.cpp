/*************************************************************************************
** determinant.cpp is the determinant class function implementation file.
** Author:  Byron Kooima
** Date: 2017/06/30
** Description: CS162 Week1 Lab1
** The determinant function has two parameters: a pointer to a 2D array and an integer
** as the size of the matrix. The function returns an integer value which is the 
** determinant of the matrix stored in the 2D array.
***************************************************************************************/

#include "determinant.hpp"
#include <iostream>
#include <math.h>


int determinant::getDeterminant(int **mat, int mSize)
{
	if (mSize == 2)
	{
		return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
	}
	else
	{
		return ((mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])) - (mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])) + (mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0])));
	}
}
