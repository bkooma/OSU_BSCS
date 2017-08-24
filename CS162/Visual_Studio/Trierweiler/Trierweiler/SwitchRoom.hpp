/****************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: The switchRoom initially has all of its doors hidden until
* the character interacts with the specialCharacter which is denoted 'S'. The
* 'S' represents a switch the player must flip  to change the spaces state.
* Once the switch is flipped  all available doors are revealed. There are gaurds
* which the player must avoid, and if caught the game is over. The gaurds are
* represented by objects of the Gaurd class
****************************************************************************/
#ifndef SWITCHROOM_HPP
#define SWITCHROOM_HPP

#include "Space.hpp"
#include "Gaurd.hpp"

class SwitchRoom : public Space
{
private:
	bool isMainRoom;
	int numGaurds;
	Gaurd** gaurdArray;

	virtual void createGrid();
	virtual void changingState(char);
	void moveGaurds();
	bool checkForGaurds();

public:
	SwitchRoom(Space*, Space*, Space*, Space*, 
                   int, int, char, std::string, BlueMen*, int, bool);
	~SwitchRoom();

	virtual void hint();
}; 

#endif


