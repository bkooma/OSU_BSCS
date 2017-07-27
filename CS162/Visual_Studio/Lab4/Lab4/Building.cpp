/*************************************************************************************
** Building.cpp is the Instructor base class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Lab4
** The Building class represents a University buildings. It allows the user to populate
** the name, sqFt, and Address of every building. It contains getter and setter
** methods for the name/sqFt/Address. 
***************************************************************************************/

#include "Building.hpp"
#include <iostream>
#include <string>

/*********************************************************************
** Function: Building::Building
** Description: Default constructor for Building. Sets all protected
**				members to default values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Building members set to default.
*********************************************************************/
Building::Building()
{
	setName("");
	bldgSqFt = 0;
	setAddress("");
}

/*********************************************************************
** Function:		Building::Building
** Description:		User defined constructor for Building. Sets all Item
**					members	to values provided by the user.
** Parameters:		Name			Building Name
**					Sqft			Building Square Feet
**					bldgAddress		Building Address
** Pre-Conditions:	N/A
** Post-Conditions: Building members' values set by user.
*********************************************************************/
Building::Building(std::string Name, int Sqft, std::string bAddress)
{
	name = Name;
	bldgSqFt = Sqft;
	bldgAddress = bAddress;
}

/*********************************************************************
** Function:		Building::setName()
** Description:		Set the Building name
** Parameters:		pName		Building's name
** Pre-Conditions:	N/A
** Post-Conditions: Sets name to bName
*********************************************************************/
void Building::setName(std::string bName)
{
	name = bName;
}

/*********************************************************************
** Function:		Building::setSqFt()
** Description:		Set the Building Square footage
** Parameters:		Sqft		Building's square footage
** Pre-Conditions:	N/A
** Post-Conditions: Sets bldgSqFt to Sqft
*********************************************************************/
void Building::setSqFt(int Sqft)
{
	bldgSqFt = Sqft;
}

/*********************************************************************
** Function:		Building::setAddress()
** Description:		Set the Building Address
** Parameters:		bAddress		Building's address
** Pre-Conditions:	N/A
** Post-Conditions: Sets bldgAddress to bAddress
*********************************************************************/
void Building::setAddress(std::string bAddress)
{
	bldgAddress = bAddress;
}

/*********************************************************************
** Function:		Building::getName()
** Description:		Get the Building name
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a string of the name
*********************************************************************/
std::string Building::getName()
{
	return name;
}

/*********************************************************************
** Function:		Building::getSqFt()
** Description:		Get the Building square footage
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns an int of the bldgSqFt
*********************************************************************/
int Building::getSqFt()
{
	return bldgSqFt;
}

/*********************************************************************
** Function:		Building::getAddress()
** Description:		Get the Building address
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a string of the bldgAddress
*********************************************************************/
std::string Building::getAddress()
{
	return bldgAddress;
}

/*********************************************************************
** Function:		Building::~Building()
** Description:		Building Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: N/A
*********************************************************************/
Building::~Building()
{
}
