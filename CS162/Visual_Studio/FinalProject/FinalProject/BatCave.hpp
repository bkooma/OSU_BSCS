/*************************************************************************************
** BatCave.hpp is the BatCave derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Batcave class represents a Space derived class. It is the main corridor for all
** Space objects in the Batman Game. It inherits the variables from the Space base
** class. It also uses the virtual functions from the base class for the
** displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
***************************************************************************************/
#ifndef BATCAVE_HPP
#define BATCAVE_HPP

#include "Space.hpp"
#include "Batman.hpp"

class BatCave : public Space
{
public:
	// Default Constructor for setting the derived variables
	BatCave(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	// Menu input for the BatCave Space
	char spaceMenu();
	// Display the info screen for the BatCave
	void displaySpaceInfo();
	// Display the ASCII txt map for the BatCave
	void displaySpaceMap();
	// Destructor
	~BatCave();
};
#endif
