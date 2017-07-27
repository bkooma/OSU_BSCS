/**************************************************************************************
** paper.cpp is the Paper derived class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/30
** Description: CS162 Week5 Group10
** The paper class represents a Paper Derived class. It inherits the strength, type, and
** fight() function from the Tool base class. The fight function passes in a Tool
** pointer and establishes the strength of Paper when playing against Rock or Scissors.
** fight() returns the enumerated "Fight" value based on the results of taking on
** the computer's Tool.
****************************************************************************************/

#include "Paper.hpp"
#include <iostream>

/*********************************************************************
** Function: 		Paper::Paper
** Description:		Default constructor for Paper. Sets all protected
** 					members	to initial values.
** Parameters:		N/A
** Pre-Conditions: 	N/A
** Post-Conditions: Paper members initialized.
*********************************************************************/
Paper::Paper()
{
	this->strength = 1;
	this->type = 'p';
}

/*********************************************************************
** Function:		Paper::Paper
** Description:		User defined constructor for Paper. Sets Paper
**					strength from user input.
** Parameters:		strength		Paper strength for this round
** Pre-Conditions:	N/A
** Post-Conditions: Paper strength value is set by user.
*********************************************************************/
Paper::Paper(int strength) : Tool(strength)
{
  this->type = 'p';
}

/*********************************************************************
** Function:		Paper::fight()
** Description:		Passes in a Tool randomly created by the computer
** 					and determines the Paper's strength based on the
** 					computer input.
** Parameters:		Tool*		Tool that Paper is fighting against
** Pre-Conditions:	Enumerated values for Fight must be established
** Post-Conditions: The round is played and the resulting winner is
** 					returned to the main game.
*********************************************************************/
FightResult Paper::fight(Tool* tool)
{
	int pStrength = 1;
	FightResult roundWLD;

	// Adjust strength of Paper against computer opponent
	if (tool->getType() == 's')
	{
		pStrength = (this->strength) / 2;
	}
	else if (tool->getType() == 'r')
	{
		pStrength = (this->strength) * 2;
	}
	else {
		pStrength = this->strength;
	}

  std::cout << "Your paper strength is " << pStrength << "\n";
  // Compare strengths after adjusting for opposing computer's Tool
  if (pStrength > tool->getStrength())
  {
      roundWLD = WIN;
  }
  else if (pStrength < tool->getStrength())
  {
      roundWLD = LOSE;
  }
  else
  {
      roundWLD = DRAW;
  }

  // Returns the enumerated value if user wins/loses/ties
  return roundWLD;
}