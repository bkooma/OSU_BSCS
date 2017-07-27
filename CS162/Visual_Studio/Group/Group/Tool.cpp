/******************************************************************************
** Tool.cpp is the Paper class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week5 Group 10
** Description: Implementation file for the Tool class. It contains default
				behavior that will be inherited by classes derived from Tool.
******************************************************************************/
#include "Tool.hpp"

//Default constructor
Tool::Tool()
{
	this->strength = 1;
}

//Parameterized constructor
Tool::Tool(int strength)
{
	this->strength = strength;
}

void Tool::setStrength(int strength)
{
	this->strength = strength;
}

int Tool::getStrength() const
{
		return this->strength;
}

char Tool::getType() const
{
		return this->type;
}

//Destructor
Tool::~Tool()
{
}