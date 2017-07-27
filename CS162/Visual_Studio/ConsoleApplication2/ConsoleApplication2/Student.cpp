/*************************************************************************************
** Student.cpp is the Student class function implementation file. 
** Author:  Byron Kooima
** Date: 2017/02/28
** Description: CS161 Week8 Assignment 8 Project 8.b
** The Student class has two data members - a string variable for a student
** name and a double variable for the student's score. It has a constructor that takes
** two values and uses them to initialize the data members. It has a get method for both
** data members.
***************************************************************************************/

#include <iostream>
#include <string>
#include "Student.hpp"


// Default Student constructor
Student::Student(){}

// Student constructor
Student::Student(std::string studentName, double studentScore)
{
	name = studentName;
	score = studentScore;
}

// Student destructor
Student::~Student()
{}

/************************************************************************************
*                             Student::getStudentName
* This function returns the current student Name.
*************************************************************************************/
std::string Student::getStudentName()
{
	return name;
}

/************************************************************************************
*                             Student::getStudentScore
* This function returns the current student score.
*************************************************************************************/
double Student::getStudentScore()
{
	return score;
}

