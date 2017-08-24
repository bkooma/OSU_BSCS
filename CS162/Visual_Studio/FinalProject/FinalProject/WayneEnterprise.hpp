/*************************************************************************************
** WayneEnterprise.hpp is the WayneManner derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The WayneEnterprise class represents a Space derived class. It inherits the variables
** from the Space base class. It also uses the virtual functions from the base class
** for the displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
***************************************************************************************/
#ifndef WAYNEENTERPRISE_HPP
#define WAYNEENTERPRISE_HPP
#include "Space.hpp"
class WayneEnterprise :
	public Space
{
public:
	// Default Constructor for setting the derived variables
	WayneEnterprise(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	// Menu input for WayneEnterprise Space
	char spaceMenu();
	// Display the info screen for WayneEnterprise
	void displaySpaceInfo();
	// Display the ASCII txt map for WayneEnterprise
	void displaySpaceMap();
	// Destructor
	~WayneEnterprise();
};

#endif