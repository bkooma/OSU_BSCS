/*************************************************************************************
** IvyLair.hpp is the IvyLair derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The IvyLair class represents a Space derived class. It inherits the variables
** from the Space base class. It also uses the virtual functions from the base class
** for the displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
***************************************************************************************/
#ifndef IVYLAIR_HPP
#define IVYLAIR_HPP

#include "Space.hpp"
class IvyLair :
	public Space
{
public:
	// Default Constructor for setting the derived variables
	IvyLair(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	// Menu input for IvyLair Space
	char spaceMenu();
	// Display the info screen for IvyLair
	void displaySpaceInfo();
	// Display the ASCII txt map for IvyLair
	void displaySpaceMap();
	// Destructor
	~IvyLair();
};

#endif
