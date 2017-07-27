/*************************************************************************************
** People.cpp is the People base class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Lab4
** The People class represents a Personnel Base Class for the University. It allows the
** user to populate the name and age of every person. It contains getter and setter 
** methods for the Base name/age. It also has a random age generator to allow the 
** Derived classes to have a simplified constructor. It can also return the hours worked
** by the person.
***************************************************************************************/

#include <iostream>
#include "People.hpp"

/*********************************************************************
** Function: People::People
** Description: Default constructor for People. Sets all protected
**				members to default values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: People members set to default.
*********************************************************************/
People::People() {
	age = 0;
	workHours = 0;
	setName("");
}

/*********************************************************************
** Function:		People::People
** Description:		User defined constructor for People. Sets all Item
**					members	to values provided by the user.
** Parameters:		Name		Person Name
**					age			Person Age
** Pre-Conditions:	N/A
** Post-Conditions: People members' values set by user.
*********************************************************************/
People::People(std::string Name, int age) {
	this->name = Name;
	this->age = age;
}

/*********************************************************************
** Function:		People::setName()
** Description:		Set the Person name
** Parameters:		pName		Person's name
** Pre-Conditions:	N/A
** Post-Conditions: Sets name to pName
*********************************************************************/
void People::setName(std::string pName) {
	name = pName;
}

/*********************************************************************
** Function:		People::setAge()
** Description:		Set the Person age
** Parameters:		x		Person's age
** Pre-Conditions:	N/A
** Post-Conditions: Sets age to x
*********************************************************************/
void People::setAge(int x) {
	age = x;
}

/*********************************************************************
** Function:		People::setRandomAge()
** Description:		Set the Person's Age based on a random integer<100
** Parameters:		age		Person's random age
** Pre-Conditions:	N/A
** Post-Conditions: Sets age to random int between 18 and 100
*********************************************************************/
void People::setRandomAge()
{
	age = (rand() % (82 + 1)+18);
}

/*********************************************************************
** Function:		People::getName()
** Description:		Get the Person name
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a string of the name
*********************************************************************/
std::string People::getName() {
	return name;
}

/*********************************************************************
** Function:		People::getAge()
** Description:		Get the Person age
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns an int of the age
*********************************************************************/
int People::getAge() {
	return age;
}

/*********************************************************************
** Function:		People::getHours()
** Description:		Get the Person hours worked
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns an int of the workHours
*********************************************************************/
int People::getHours() {
	return workHours;
}

/*********************************************************************
** Function:		People::~People()
** Description:		People Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
People::~People() {}