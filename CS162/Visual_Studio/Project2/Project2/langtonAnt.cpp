/*************************************************************************************
** langtonAnt.cpp is the Ant class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/06
** Description: CS162 Week2 Project1
** The Ant class sets/gets the ant's position and direction. It also sets/gets the 
** number of moves the ant will perform. It also has the function calls to turn the
** ant right or left depending on the ant's current direction.
**
** Citation: Sections of this code were referenced from
** https://ubuntuforums.org/showthread.php?t=812784&page=2
***************************************************************************************/

#include "langtonAnt.hpp"

#include <iostream>
#include <stdlib.h>

//Default Constructor
Ant::Ant() {

	a_direction = static_cast<Direction>(0);
	setMoves(80);
	setX(40);
	setY(20);
}

//Destructor
Ant::~Ant() {
}

// Gets the current x position of the ant.
int Ant::getX() {
	return a_x;
}

// Gets the current y position of the ant.
int Ant::getY() {
	return a_y;
}

// Gets the current dirction of the ant.
int Ant::getDir() {
	return a_direction;
}

// Gets the current number of moves of the ant.
int Ant::getMoves() {
	return a_z;
}

// Sets the x position of the ant.
void Ant::setX(int x) {
	a_x = x;
}

// Sets the y position of the ant.
void Ant::setY(int y) {
	a_y = y;
}

// Sets the direction of the ant.
void Ant::setDir(int d) {
	a_direction = static_cast<Direction>(d);
}

// Sets the number of moves of the ant.
void Ant::setMoves(int z) {
	a_z = z;
}

// Turns left. Dependend on the current direction, the x or y
// coordinate of the ant is changed.
void Ant::turnL() {
	// turn 90 degress left, which is dependent on the ant's direction.
	switch (a_direction) {
	case DIR_NORTH:	a_direction = DIR_WEST;	a_x -= 1; break; // move right in array
	case DIR_WEST: a_direction = DIR_SOUTH; a_y += 1; break; // move down in array
	case DIR_SOUTH: a_direction = DIR_EAST; a_x += 1; break; // move left in array
	case DIR_EAST: a_direction = DIR_NORTH; a_y -= 1; break; // move up in array.
	default: a_direction = DIR_NORTH; break;
	}
}

// Turns right. Dependend on the current direction, the x or y
// coordinate of the ant is changed.
void Ant::turnR() {
	// turn 90 degress right, which is dependent on the ant's direction.
	switch (a_direction) {
	case DIR_NORTH: a_direction = DIR_EAST; a_x += 1; break; // move right in array
	case DIR_EAST: a_direction = DIR_SOUTH; a_y += 1; break; // move down in array
	case DIR_SOUTH: a_direction = DIR_WEST; a_x -= 1; break; // move left in array
	case DIR_WEST: a_direction = DIR_NORTH; a_y -= 1; break; // move up in array.
	default: a_direction = DIR_NORTH; break; // should not happen.
	}
}
