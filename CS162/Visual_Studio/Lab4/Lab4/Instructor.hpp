/*************************************************************************************
** Instructor.hpp is the Instructor derived class specification file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Lab4
** The Instructor class represents an Instructor Derived class. It inherits the name,
** age, and do_work from the People base class. It has an additional setter/getter for
** the Rating of an instructor. It can also set a random Rating if the minimal
** constructor is used. The do_work function passes in a maximum for the work hours and
** then sets studentHrs to a random number less than the maximum.
***************************************************************************************/

#ifndef Instructor_hpp
#define Instructor_hpp

#include <iostream>
#include "People.hpp"

class Instructor : public People {
public:
	// Default constructor for Instructor
	Instructor();

	// User defined constructor for Instructor
	Instructor(std::string);
	// User defined constructor for Instructor (overloaded)
	Instructor(std::string, int, double);

	// Setters:
	// Set the Instructor's Rating
	void setRating(double);
	// Set the Instructor's Rating to a random double
	void setRandomRating();

	// Getters:
	// Get the Instructor's Rating
	double getRating();

	// Class functions:
	// Abstract function for the derived classes to set work
	void do_work(int);

	// Destructor
	~Instructor();

private:
	// Variables for Instructor
	double instructorRating;
	int instructHrs;
};

#endif /* Instructor_hpp */
