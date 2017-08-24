/***************************************************************************************
** WayneManner.hpp is the WayneManner derived class specification file.
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The WayneManner class represents a Space derived class. It inherits the variables
** from the Space base class. It also uses the virtual functions from the base class
** for the displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
***************************************************************************************/
#ifndef WAYNEMANNER_HPP
#define WAYNEMANNER_HPP
#include "Space.hpp"
class WayneManner :
	public Space
{
public:
	// Default Constructor for setting the derived variables
	WayneManner(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	// Menu input for WayneManner Space
	char spaceMenu();
	// Display the info screen for WayneManner
	void displaySpaceInfo();
	// Display the ASCII txt map for WayneManner
	void displaySpaceMap();
	// Destructor
	~WayneManner();
};

#endif