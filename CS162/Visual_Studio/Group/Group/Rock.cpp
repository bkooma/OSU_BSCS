/**************************************************************************************
** Rock.cpp is the Rock derived class function implementation file.
** Authors:  Byron Kooima, Alexander Jennison, Polly Sobeck,
**           Dai Duong Nguyen, Zachary Bellone
** Date: 2017/07/30
** Description: CS162 Week5 Group10
** The Rock class represents a Rock Derived class. It inherits the strength, type, and
** fight() function from the Tool base class. The fight function passes in a Tool
** pointer and establishes the strength of Rock when playing against Paper or Scissors.
** fight() returns the enumerated "Fight" value based on the results of taking on
** the computer's Tool.
****************************************************************************************/

#include "Rock.hpp"
#include <iostream>

/*********************************************************************
** Function: 		Rock::Rock
** Description:		Default constructor for Rock. Sets all protected
** 					members	to initial values.
** Parameters:		N/A
** Pre-Conditions: 	N/A
** Post-Conditions: Rock members initialized.
*********************************************************************/
Rock::Rock()
{
	this->setStrength(1);
	this->type = 'r';
}

/*********************************************************************
** Function:		Rock::Rock
** Description:		User defined constructor for Rock. Sets Rock
**					strength from user input.
** Parameters:		strength		Rock strength for this round
** Pre-Conditions:	N/A
** Post-Conditions: Rock strength value is set by user.
*********************************************************************/
Rock::Rock(int strength) : Tool(strength)
{
	this->type = 'r';
}

/*********************************************************************
** Function:		Rock::fight()
** Description:		Passes in a Tool randomly created by the computer
** 					and determines the Rock's strength based on the
** 					computer input.
** Parameters:		Tool*		Tool that Rock is fighting against
** Pre-Conditions:	Enumerated values for Fight must be established
** Post-Conditions: The round is played and the resulting winner is
** 					returned to the main game.
*********************************************************************/
FightResult Rock::fight(Tool* tool)
{
	int rStrength = 1;
	FightResult roundWLD;

  // Adjust strength of Rock against computer opponent
	if (tool->getType() == 'p')
		rStrength = (this->getStrength())/2;
	else if (tool->getType() == 's')
		rStrength = (this->getStrength())*2;
	else
		rStrength = this->getStrength();

	std::cout << "Your rock strength is " << rStrength << "\n";
	
	// Compare strengths after adjusting for opposing computer's Tool
	if (rStrength < tool->getStrength())
		roundWLD = LOSE;
	else if (rStrength > tool->getStrength())
		roundWLD = WIN;
	else
		roundWLD = DRAW;

	// Returns the enumerated value if user wins/loses/ties
	return roundWLD;
}
