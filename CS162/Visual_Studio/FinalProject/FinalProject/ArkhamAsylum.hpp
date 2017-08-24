/**************************************************************************************
** ArkhamAsylum.hpp is the ArkhamAsylum derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The ArkhamAsylum class represents a Space derived class. It inherits the variables
** from the Space base class. It also uses the virtual functions from the base class
** for the displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
***************************************************************************************/
#ifndef ARKHAMASYLUM_HPP
#define ARKHAMASYLUM_HPP

#include "Space.hpp"

class ArkhamAsylum : public Space
{
public:
	// Default Constructor for setting the derived variables
	ArkhamAsylum(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	// Menu input for the ArkhamAsylum Space
	char spaceMenu();
	// Display the info screen for ArkhamAsylum
	void displaySpaceInfo();
	// Display the ASCII txt map for ArkhamAsylum
	void displaySpaceMap();
	// Destructor
	~ArkhamAsylum();
};
#endif
