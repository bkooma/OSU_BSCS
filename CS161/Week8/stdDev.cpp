/************************************************************************************
** stdDev.cpp
** Author:  Byron Kooima
** Date: 2017/02/28
** Description: CS161 Week8 Assignment 8 Project 8.b
** This function takes two parameters - an array of pointers to Students and the size 
** of the array - and returns the standard deviation for the student scores.
** StdDev = sqrt((sum ((mean-x[i])^2)/N))
**************************************************************************************/

#include "Student.hpp"
#include <iostream>
#include <string>
#include <cmath>


// Function 
double stdDev(Student *studentInfo[], int sizeArr) {

	double sum = 0, mean = 0, sumSq = 0;

	/************************************************************************************
	* First for loop to add up all of the students scores.                            
	* Could also dereference using the following: (*(studentInfo[i])).getStudentScore()
	*************************************************************************************/
	for (int i = 0; i < sizeArr; i++)
	{
		// Dereference studentInfo[i] using -> to get Student::getStudentScore()
		sum = sum + studentInfo[i]->getStudentScore();
	}
	// Calculate the mean (average) of the array.
	mean = sum / sizeArr;
	
	/************************************************************************************
	* Second for loop to add up the sum of the squares.
	* Using (x * x) instead of pow(x,2) for efficiency
	*************************************************************************************/
	for (int i = 0; i < sizeArr; i++)
	{
		sumSq += (mean - studentInfo[i]->getStudentScore()) * (mean - studentInfo[i]->getStudentScore());
	}

    // Return the standard deviation by taking the square root of the (sum / sizeArr)
	return sqrt(sumSq / sizeArr);
}


/*int main()
{
	const int MAX = 4;
	double standardDev;
	double studentScore;
	std::string studentName;

	Student** pStudent = new Student*[MAX];  // This works

	for (int index = 0; index < MAX; index++)
	{
		std::cout << "Enter the student's name: " << std::endl;
		std::cin >> studentName;

		std::cout << "Enter the student's score: " << std::endl;
		std::cin >> studentScore;

		pStudent[index] = new Student(studentName, studentScore);
	}
	standardDev = stdDev(pStudent, MAX);

	std::cout << "Student Name1: " << (*(pStudent[0])).getStudentScore() << std::endl;
	std::cout << "Student Name1: " << (*(pStudent[0])).getStudentName() << std::endl;
	std::cout << "Student Name1: " << *(pStudent) << std::endl;
//	std::cout << "Student Name1: " << *(students) << std::endl;
	std::cout << "Student Score: " << *(pStudent + 1) << std::endl;
	std::cout << "Standard Deviation: " << standardDev << std::endl;
}*/