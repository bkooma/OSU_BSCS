/**************************************************************************************
** rock.cpp is the Rock derived class specification file.
** Author:  Byron Kooima
** Date: 2017/07/30
** Description: CS162 Week5 Group10
** The rock class represents a Rock Derived class. It inherits the strength, type, and
** fight() function from the Tool base class. The fight function passes in a Tool
** pointer and establishes the strength of Rock when playing against Paper or Scissors.
** fight() returns the enumerated "Fight" value based on the results of taking on
** the computer's Tool.
****************************************************************************************/

#include "Tool.hpp"

class Rock : public Tool
{
public:
	//Default constructor for Rock.
	Rock();

    // User defined constructor for Rock.
	Rock(int strength);

	/*******************************************************************************
	// Passes in a Tool randomly created by the computer and determines the Rock's
	// strength based on the computer input. The strengths of each Tool is compared
	// to determine the winner of the current round.
	*******************************************************************************/
	FightResult fight(Tool* tool);
};
