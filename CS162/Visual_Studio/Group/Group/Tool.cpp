/******************************************************************************
** Tool.cpp is the Paper class function implementation file.
** Authors:  Byron Kooima, Alexander Jennison, Polly Sobeck,
**           Dai Duong Nguyen, Zachary Bellone
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
Tool::Tool() : strength(1)
{
}

/*********************************************************************
** Function:		Tool::Tool
** Description:		User defined constructor for Tool. Sets Tool
**					strength from user input.
** Parameters:		strength		Tool strength for this round
** Pre-Conditions:	N/A
** Post-Conditions: Tool strength value is set by user.
*********************************************************************/
Tool::Tool(int str) : strength(str)
{
}

/*********************************************************************
** Function:		Tool::setStrength
** Description:		Setter for setting the set Tool strength
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Tool strength value is set.
*********************************************************************/
void Tool::setStrength(int str) {
	this->strength = str;
}

/*********************************************************************
** Function:		Tool::getStrength
** Description:		Getter for getting the set Tool strength
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Tool strength value is returned.
*********************************************************************/
int Tool::getStrength()
{
	return this->strength;
}

/*********************************************************************
** Function:		Tool::getType
** Description:		Getter for returning the Tool type
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Tool type char is returned.
*********************************************************************/
char Tool::getType()
{
	return this->type;
}

//Destructor
Tool::~Tool()
{
}