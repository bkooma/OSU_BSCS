/******************************************************************************
** Tool.cpp is the Paper class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week5 Group 10
** The Tool class represents a Tool Base class. It creates the strength, type,
** and fight() function for the RPG derived classes. The fight function passes
** in a Tool pointer and establishes the strength of Tool when playing against
** computer Tool. fight() returns the enumerated "FightResult" value based on
** the results of taking on the computer's Tool.
******************************************************************************/
#include "Tool.hpp"

/*********************************************************************
** Function: 		Tool::Tool
** Description:		Default constructor for Tool. Sets all protected
** 					members	to initial values.
** Parameters:		N/A
** Pre-Conditions: 	N/A
** Post-Conditions: Tool members initialized.
*********************************************************************/
Tool::Tool()
{
	this->strength = 1;
}

/*********************************************************************
** Function:		Tool::Tool
** Description:		User defined constructor for Tool. Sets Tool
**					strength from user input.
** Parameters:		strength		Tool strength for this round
** Pre-Conditions:	N/A
** Post-Conditions: Tool strength value is set by user.
*********************************************************************/
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