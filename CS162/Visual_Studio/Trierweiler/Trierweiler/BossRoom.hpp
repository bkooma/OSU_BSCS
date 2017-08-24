/*******************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: The BossRoom contains the special character 'D', which the player
* must interact with to change the spaces state. Once the spaces state is changed
* a battle simulated from Assignment 3 and 4 takes place between a BlueMen and
* Vampire object. Once the battle is lost/won by the BlueMen the game is over.
* The BlueMen initially start with one, but the player can collect more in 
* TreasureRooms to increase their chance of winning the battle
*******************************************************************************/
#ifndef BOSSROOM_HPP
#define BOSSROOM_HPP

#include "Space.hpp"
#include "Vampire.hpp"

class BossRoom : public Space
{

private:
	Vampire* Dracula;

	virtual void createGrid();;
	virtual void changingState(char);

public:
	BossRoom(Space*, Space*, Space*, Space*, 
                 int, int, char, std::string, BlueMen*, bool);
	~BossRoom();

	virtual void hint();
};

#endif

