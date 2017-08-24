/******************************************************************************
** LeagueOfShadows.hpp is the LeagueOfShadows derived class specification file.
** Author:  Byron Kooima
** Date: 2017/08/06
** Description: CS162 Week8 Final Project
** The LeagueOfShadows class represents a Creature derived class. It inherits the variables
** from the Creature base class. It also uses the virtual functions from the base class
** for the attack, defense and recover_strength.
***************************************************************************************/

#ifndef LEAGUEOFShadows_HPP
#define LEAGUEOFShadows_HPP

#include "Creature.hpp"
class LeagueOfShadows :
	public Creature
{
public:
	LeagueOfShadows(int, int);
	virtual int defense();
	virtual int pain(int attack, int defense);
	//Revive the Batman after the round is over
	virtual void recover_strength();

	~LeagueOfShadows();

};

#endif