/*************************************************************************************
** Instructor.cpp is the Instructor base class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Lab4
** The Instructor class represents an Instructor Derived class. It inherits the name, 
** age, and do_work from the People base class. It has an additional setter/getter for
** the Rating of an instructor. It can also set a random Rating if the minimal 
** constructor is used. The do_work function passes in a maximum for the work hours and 
** then sets studentHrs to a random number less than the maximum.
***************************************************************************************/

#include "Instructor.hpp"
#include <iostream>
#include <string>
#include <random>

/*********************************************************************
** Function: Instructor::Instructor
** Description: Default constructor for Instructor. Sets all private 
**				members to default values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Student members set to default.
*********************************************************************/
Instructor::Instructor()
{
	instructHrs = 0;
	instructorRating = 0.0;
}


/*********************************************************************
** Function:		Instructor::Instructor
** Description:		User defined constructor for Instructor. Sets 
**					instructor name from user input. Rating and Age 
**					are randomly generated and set for the Instructor.
** Parameters:		iname		Instructor Name
** Pre-Conditions:	N/A
** Post-Conditions: Instructor members' values set by user/random gen.
*********************************************************************/
Instructor::Instructor(std::string iname)
{
	name = iname;
	setRandomRating();
	People::setRandomAge();
}

/*********************************************************************
** Function:		Instructor::Instructor
** Description:		User defined constructor for Instructor. Sets all
**					Instructor members	to values provided by the user.
** Parameters:		iname		Instructor Name
**					age			Instructor Age
**					rating		Instructor Rating
** Pre-Conditions:	N/A
** Post-Conditions: Student members' values set by user/random gen.
*********************************************************************/
Instructor::Instructor(std::string iname, int age, double rating) : People(iname, age)
{
	setRating(rating);
}

/*********************************************************************
** Function:		Instructor::setRating()
** Description:		Set the Instructor Rating
** Parameters:		r		Instructor's Rating
** Pre-Conditions:	N/A
** Post-Conditions: Sets instructorRating to r
*********************************************************************/
void Instructor::setRating(double r)
{
	instructorRating = r;
}

/*********************************************************************
** Function:		Instructor::setRandomGpa()
** Description:		Set the Instructor Rating to a random double 
**					between	0 and 5.
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Sets instructorRating to random double.
*********************************************************************/
void Instructor::setRandomRating()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 5);
	instructorRating = dis(gen);
}

/*********************************************************************
** Function:		Instructor::getRating()
** Description:		Get the Instructor Rating
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Gets the Instructor's rating
*********************************************************************/
double Instructor::getRating()
{
	return instructorRating;
}

/*********************************************************************
** Function:		Instructor::do_work()
** Description:		Sets the hours worked on papers to a random int
** Parameters:		x		Max value of the random int
** Pre-Conditions:	N/A
** Post-Conditions: Sets instructHrs to random int
*********************************************************************/
void Instructor::do_work(int x)
{
	instructHrs = (rand() % x + 1);
	std::cout << "Instructor " << this->name << " graded papers for " << instructHrs << " hours.\n";
}

/*********************************************************************
** Function:		Instructor::~Instructor()
** Description:		People Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Instructor::~Instructor()
{
}
