/******************************************************************************
** WayneManner.hpp is the WayneManner derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The WayneManner class represents a Space derived class. It inherits the
** variables from the Space base class. It also uses the virtual functions.
******************************************************************************/
#ifndef WAYNEMANNER_HPP
#define WAYNEMANNER_HPP
#include "Space.hpp"
class WayneManner :
	public Space
{
public:
	WayneManner(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	char spaceMenu();
	virtual void displaySpaceInfo();
	~WayneManner();
};

#endif