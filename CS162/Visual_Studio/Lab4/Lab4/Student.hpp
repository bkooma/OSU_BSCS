/*************************************************************************************
** Student.hpp is the Student derived class specification file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Lab4
** The Student class represents a Student Derived class. It inherits the name, age, and
** do_work from the People base class. It has an additional setter/getter for the GPS
** of a student. It can also set a random GPA if the minimal constructor is used. The
** do_work function passes in a maximum for the work hours and then generates sets
** studentHrs to a random number less than the maximum.
***************************************************************************************/

#ifndef Student_hpp
#define Student_hpp

#include <iostream>
#include "People.hpp"

class Student : public People {
public:
	// Default constructor for Student
	Student();

	// User defined constructor for Student
	Student(std::string);
	// User defined constructor for Student (overloaded)
	Student(std::string, int, double);

	// Setters:
	// Set the Student's GPA
	void setGpa(double);
	// Set the Student's GPA to a random double
	void setRandomGpa();
	// Getters:
	// Get the Student's GPA
	double getGpa();

	// Class functions:
	// Abstract function for the derived classes to set work
	void do_work(int);

	// Destructor
	~Student();

private:
	// Variables for the Student
	double gpa;
	int studentHrs;
};

#endif /* Student_hpp */
