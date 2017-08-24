/*************************************************************************************
** Warehouse.hpp is the Warehouse derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Warehouse class represents a Space derived class. It inherits the variables
** from the Space base class. It also uses the virtual functions from the base class
** for the displayVillainInfo, setAdjSpace, moveSpace, pause, printRound, and playRound.
** Retrieved the ascii image for the Warehouse from the following ascii site:
** http://www.chris.com/ascii/index.php?art=objects/buildings
***************************************************************************************/
#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include "Space.hpp"

class Warehouse :
	public Space
{
public:
	// Default Constructor for setting the derived variables
	Warehouse(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	// Menu input for the Warehouse Space
	char spaceMenu();
	// Display the info screen for Warehouse
	void displaySpaceInfo();
	// Display the ASCII txt map for Warehouse
	void displaySpaceMap();
	// Destructor
	~Warehouse();
};

#endif