/****************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: The Treasure room contains an item, a char value, that is added
* to the BlueMen's items. 'K' which is the dungeon key unlocks all inaccessable
* doors in the dungeon, and 'B' which is a BlueMen that increase the amount of
* BlueMen. The special character the player must interact with to change the
* spaces state is the char 'T'. Once the player collects the treasure the space 
* state is changed and the player cannot collect the treasure again 
*******************************************************************************/
#ifndef TREASUREROOM_HPP
#define TREASUREROOM_HPP

#include "Space.hpp"

class TreasureRoom : public Space
{
private:
	char treasure;

	virtual void createGrid();
	virtual void changingState(char);

public:
	TreasureRoom(Space*, Space*, Space*, Space*, 
                     int, int, char, std::string, BlueMen*, char, bool);
	~TreasureRoom();

	virtual void hint();
};

#endif


