/******************************************************************************
** Warehouse.hpp is the Warehouse derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The Warehouse class represents a Space derived class. It inherits the
** variables from the Space base class. It also uses the virtual functions.
******************************************************************************/
#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP
#include "Space.hpp"
class Warehouse :
	public Space
{
public:
	Warehouse(std::string name, Creature* bMan, Creature* vil) : Space(name, bMan, vil) {};
	char spaceMenu();
	virtual void displaySpaceInfo();
	~Warehouse();
};

#endif