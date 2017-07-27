/*************************************************************************************
** Student.hpp is the Student class specification file.
** Author:  Byron Kooima
** Date: 2017/02/28
** Description: CS161 Week8 Assignment 8 Project 8.b
** The Student class has two data members - a string variable for a student
** name and a double variable for the student's score. It has a constructor that takes
** two values and uses them to initialize the data members. It has a get method for both
** data members.
***************************************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>

class Student
{
private:
	std::string name;
	double score;

public:
	// default constructor
	Student();

	// constructor with parameters
	Student(std::string, double);

	// getters
	std::string getStudentName();
	double getStudentScore();

	//destructor
	~Student();
};

#endif // !STUDENT_HPP

