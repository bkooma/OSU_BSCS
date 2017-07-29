/*************************************************************************************
** Recursion.hpp is the Recursion class specification file.
** Author:  Byron Kooima
** Date: 2017/07/30
** Description: CS162 Week5 Lab 5
** The Recursion class represents a Grocery List. 
***************************************************************************************/
#ifndef RECURSION_HPP
#define RECURSION_HPP

#include <string>

class Recursion {
public:
	// Default constructor for Recursion
	Recursion();
	//Use recursion to reverses the characters of a user provided string
	void reverse(std::string s);
	// Use recursion to sum up all the elements of an array
	int arraySum(int arr[], int elements);
	// Use recursion to sum up the number of elements in a triangle of size N
	int triangleSum(int rowNum);

	// Recursion menu options
	void recursionMenu();

	// Recursion Destructor
	~Recursion();
};
#endif // !RECURSION_HPP
