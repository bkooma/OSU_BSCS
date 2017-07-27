/*************************************************************************************
** Student.cpp is the Student base class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Lab4
** The Student class represents a Student Derived class. It inherits the name, age, and
** do_work from the People base class. It has an additional setter/getter for the GPS
** of a student. It can also set a random GPA if the minimal constructor is used. The
** do_work function passes in a maximum for the work hours and then sets studentHrs to 
**  a random number less than the maximum.
***************************************************************************************/

#include "Student.hpp"
#include <iostream>
#include <string>
#include <random>

/*********************************************************************
** Function: Student::Student
** Description: Default constructor for Student. Sets all private members
**				to default values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Student members set to default.
*********************************************************************/
Student::Student()
{
	gpa = 0.0;
	studentHrs = 0;
}

/*********************************************************************
** Function:		Student::Student
** Description:		User defined constructor for Student. Sets student
**					name from user input. GPA and Age are randomly 
**					generated and set for the Student.
** Parameters:		sname		Student Name
** Pre-Conditions:	N/A
** Post-Conditions: Student members' values set by user.
*********************************************************************/
Student::Student(std::string sname)
{
	name = sname;
	setRandomGpa();
	People::setRandomAge();
}

/*********************************************************************
** Function:		Student::Student
** Description:		User defined constructor for Student. Sets all 
**					Student members	to values provided by the user.
** Parameters:		sname		Student Name
**					age			Student Age
**					gpa			Student GPA
** Pre-Conditions:	N/A
** Post-Conditions: Student members' values set by user/random gen.
*********************************************************************/
Student::Student(std::string sname, int age, double gpa) : People(sname, age)
{
	setGpa(gpa);
}

/*********************************************************************
** Function:		Student::setGpa()
** Description:		Set the Student GPA
** Parameters:		g		Studen's GPA
** Pre-Conditions:	N/A
** Post-Conditions: Sets gpa to g
*********************************************************************/
void Student::setGpa(double g)
{
	gpa = g;
}

/*********************************************************************
** Function:		Student::setRandomGpa()
** Description:		Set the Student GPA to a random double between 
**					0 and 4.
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Sets gpa to random double.
*********************************************************************/
void Student::setRandomGpa()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 4);
	gpa = dis(gen);
}

/*********************************************************************
** Function:		Student::getGpa()
** Description:		Get the Student GPA
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Gets the Student's gpa 
*********************************************************************/
double Student::getGpa()
{
	return gpa;
}

/*********************************************************************
** Function:		Student::do_work()
** Description:		Sets the hours worked on homework to a random int
** Parameters:		x		Max value of the random int
** Pre-Conditions:	N/A
** Post-Conditions: Sets studentHrs to random int
*********************************************************************/
void Student::do_work(int x)
{
	studentHrs = (rand() % x + 1);
	std::cout << this->name << " did " << studentHrs << " hours of homework.\n";
}

/*********************************************************************
** Function:		Student::~Student()
** Description:		People Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Student::~Student()
{
}
