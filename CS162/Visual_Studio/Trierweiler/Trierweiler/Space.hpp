/******************************************************************************
* Author: Daniel Trierweiler
* Date: December 6th, 2016
* Description: Space class contains 4 pointers to other Spaces (one each for
* a bearing on a North, East, South, West space). A space is represented by
* a 2D char array that is dynamically allocated. The player is represented
* by a BlueMen pointer which is an adaptation from assignments 3 and 4. The 
* player manipulates the space and the space also manipualtes the player.
* Char specialCharacter is the character the player has to interact with to 
* change the state of the space. ChanginState is a pure virtual method since
* each derived class has a different state. The subsequently led to the
* createGrid being a pure virtual method since the childSwitch Room has 
* different conditions when being created than other child classes. The main
* driver for the space is the userInput method which calls upon other methods
* as input is recieved from the user
******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include "Creature.hpp"
#include "BlueMen.hpp"
#include <iostream>
#include <string>
#include <limits>

class Space
{
protected:
	Space* northSpace;
	Space* eastSpace;
	Space* southSpace;
	Space* westSpace;
	char** grid;
	int numRows;
	int numColumns;
	char specialCharacter;
	std::string spaceName;
	bool changeState;
	bool gameOver;
	bool canEnter;
	BlueMen* Bluemen;

	virtual void createGrid() = 0;
	virtual void changingState(char) = 0;

public:
	Space(Space*, Space*, Space*, Space*, 
              int, int, char, std::string, BlueMen*);
	virtual ~Space();

	void setNorthSpace(Space*);
	void setEastSpace(Space*);
	void setSouthSpace(Space*);
	void setWestSpace(Space*);
	void setBlueMen(int, int);
	bool getGameOver();
	void printMenu();
	void printGrid();
	bool canEnterRoom();
	Space* moveToRoom();
	bool userInput();

	virtual void hint() = 0;
};

#endif



