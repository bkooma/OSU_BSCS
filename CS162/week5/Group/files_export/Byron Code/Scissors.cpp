/**************************************************************************************
** scissors.cpp is the Scissors derived class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/30
** Description: CS162 Week5 Group10
** The scissors class represents a Scissors Derived class. It inherits the strength, 
** type, and fight() function from the Tool base class. The fight function passes in a 
** Tool pointer and establishes the strength of Scissors when playing against Rock or 
** Paper. fight() returns the enumerated "Fight" value based on the results of taking on
** the computer's Tool.
****************************************************************************************/

#include "Scissors.hpp"
#include <iostream>

/*********************************************************************
** Function: 		Scissors::Scissors
** Description:		Default constructor for Scissors. Sets all 
**					protected members to initial values.
** Parameters:		N/A
** Pre-Conditions: 	N/A
** Post-Conditions: Scissors members initialized.
*********************************************************************/
Scissors::Scissors()
{
	this->strength = 1;
	this->type = 's';
}

/*********************************************************************
** Function:		Scissors::Scissors
** Description:		User defined constructor for Scissors. Sets 
**					Scissors strength from user input.
** Parameters:		strength		Scissors strength for this round
** Pre-Conditions:	N/A
** Post-Conditions: Scissors strength value is set by user.
*********************************************************************/
Scissors::Scissors(int strength) : Tool(strength)
{
	this->type = 's';
}

/*********************************************************************
** Function:		Scissors::fight()
** Description:		Passes in a Tool randomly created by the computer
** 					and determines the Scissors's strength based 
** 					on the computer input.
** Parameters:		Tool*		Tool that Scissors is fighting against
** Pre-Conditions:	Enumerated values for Fight must be established
** Post-Conditions: The round is played and the resulting winner is
** 					returned to the main game.
*********************************************************************/
FightResult Scissors::fight(Tool* tool)
{
	int sStrength = 1;
	FightResult roundWLD;

	// Adjust strength of Rock against computer opponent
	if (tool->getType() == 'r')
		sStrength = (this->strength) / 2;
	else if (tool->getType() == 'p')
		sStrength = (this->strength) * 2;
	else
		sStrength = this->strength;

	std::cout << "Your scissors strength is " << sStrength << "\n";
	
	// Compare strengths after adjusting for opposing computer's Tool
	if (sStrength < tool->getStrength())
		roundWLD = LOSE;
    else if (sStrength > tool->getStrength())
		roundWLD = WIN;
    else
		roundWLD = DRAW;

	// Returns the enumerated value if user wins/loses/ties
	return roundWLD;
}
