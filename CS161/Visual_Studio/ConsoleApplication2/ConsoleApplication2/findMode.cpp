/************************************************************************************
** findMode.cpp
** Author:  Byron Kooima
** Date: 2017/02/22
** Description: CS161 Week7 Assignment 7 Project 
** This function takes parameters as an array of int and the size of the array. It then
** returns a vector containing the mode(s) of the array values. If there is only a 
** single mode, the vector will only contain that one value. If multiple values tie for
** the mode, the vector will contain all modes. Each mode only appears once in the 
** vector and the values are in ascending order within the vector. 
**************************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

//findMode function    
std::vector<int> findMode(int xArr[], int sizeArr) {
	int i, j, tempCount;
	int maxNum = 0;
	int xArrVal;
	int xArrTemp;

	// Initialize the results vector.
	std::vector<int> results;

	// Loop to count the highest frequency value of an array.
	for (i = 0; i<sizeArr; i++) {
		tempCount = 0;
		xArrTemp = xArr[i]; //xArrTemp will equal the value of xArr[i]

		// Second loop to iterate frequency counter.
		for (j = i; j<sizeArr; j++) {
			if (xArrTemp == xArr[j])
				tempCount++;
		}
		// Find the highest frequency number (maxNum).
		if (tempCount > maxNum)
		{
			xArrVal = xArrTemp;
			maxNum = tempCount;
		}
	}

    // Loop through array again to compare the count to the highest frequency value and push that value into vector.
	for (i = 0; i<sizeArr; i++) {
		tempCount = 0;
		xArrTemp = xArr[i]; //xArrTemp will equal the value of xArr[i]

		// Second loop to iterate frequency counter again.
		for (j = i; j<sizeArr; j++) {
			if (xArrTemp == xArr[j])
				tempCount++;
		}
		// This time check to see if the temporary frequency counter matches the max counter.
		if (tempCount == maxNum)
		{
			results.push_back(xArr[i]);   // Push the highest frequency values to a results vector.
		}
	}

	// Sort the mode vector.
	std::sort(results.begin(), results.end());
	return results;   // Returns the sorted vector
}