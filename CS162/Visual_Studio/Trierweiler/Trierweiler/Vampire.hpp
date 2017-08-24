/****************************************************************************
* Author: Daniel Trierweiler
* Date: November 20th, 2016
* Description: Vampire that inherits from the parent class Creature. Vampire
* defines the virtual abstract functions attack and defense. The vampire is
* unique in that it can invoke charm and has a 50% chance of deflecting an
* incoming attack
*
* Update December 6th, 2016: Updates made for this class are noted in 
* Creature.hpp
*******************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

class Vampire : public Creature
{
public:
	Vampire(int, int, int, int, int, int, std::string);
	
	virtual int attack();
	virtual void defense(int);
};

#endif

