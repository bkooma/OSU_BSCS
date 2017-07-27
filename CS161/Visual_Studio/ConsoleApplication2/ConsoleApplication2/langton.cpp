#include "langton.hpp"

#include <iostream>

using namespace std;

Ant::Ant() {
	m_direction = DIR_NORTH;
}

Ant::~Ant() {
}

int Ant::getX() {
	return m_x;
}

int Ant::getY() {
	return m_y;
}

void Ant::setX(int x) {
	m_x = x;
}

void Ant::setY(int y) {
	m_y = y;
}

void Ant::turnRight() {
	// turn 90 degress right, which is dependent on the current direction.
	switch (m_direction) {
	case DIR_NORTH: m_direction = DIR_EAST; m_x += 1; break; // move right in array
	case DIR_EAST: m_direction = DIR_SOUTH; m_y += 1; break; // move down in array
	case DIR_SOUTH: m_direction = DIR_WEST; m_x -= 1; break; // move left in array
	case DIR_WEST: m_direction = DIR_NORTH; m_y -= 1; break; // move up in array.
	default: m_direction = DIR_NORTH; break; // should not happen.
	}
}

void Ant::turnLeft() {
	// turn 90 degress left, which is dependent on the current direction.
	switch (m_direction) {
	case DIR_NORTH:	m_direction = DIR_WEST;	m_x -= 1; break; // move right in array
	case DIR_WEST: m_direction = DIR_SOUTH; m_y += 1; break; // move down in array
	case DIR_SOUTH: m_direction = DIR_EAST; m_x += 1; break; // move left in array
	case DIR_EAST: m_direction = DIR_NORTH; m_y -= 1; break; // move up in array.
	default: m_direction = DIR_NORTH; break;
	}
}

//-----------------------------------------------------------------------------

Plane::Plane() {
	// initialize an array with all zeroes. 
	for (int i = 0; i < Plane::HEIGHT; i++) {
		for (int j = 0; j < Plane::WIDTH; j++) {
			m_plane[i][j] = 0;
		}
	}
}

Plane::~Plane() {
}

void Plane::setAnt(Ant* ant) {
	m_ant = ant;
}

void Plane::flipColor(Ant* ant) {
	/*
	* NOTE: This color flipping could also just be done using the !
	* operator, because I'm using ones and zeroes only. But that'll
	* pose a problem in some (possible) future expansion, so I just left
	* it like this.
	*/

	int color = m_plane[ant->getY()][ant->getX()];

	if (color == Plane::OFF) {
		m_plane[ant->getY()][ant->getX()] = Plane::ON;
	}
	else {
		m_plane[ant->getY()][ant->getX()] = Plane::OFF;
	}
}

int Plane::getColorAt(Ant* ant) {
	std::cout << "The value on the plane: " << ant->getX() << "  " << ant->getY();
	// simply gets the value on the plane where the ant is residing.
	return m_plane[ant->getY()][ant->getX()];
}

void Plane::moveAnt() {
	flipColor(m_ant); // flip a color where the current ant is.

	if (getColorAt(m_ant) == Plane::OFF) {
		// if the color is off, turn left.
		m_ant->turnLeft();
	}
	else if (getColorAt(m_ant) == Plane::ON) {
		// and if on, turn right.
		m_ant->turnRight();
	}

	// check whether we went out of bounds of the array. If so,
	// wrap around (i.e. x > width -> x = 0, etc.
	checkWrap();
}

void Plane::checkWrap() {
	// make sure we wrap around the thing:
	if (m_ant->getX() < 0) {
		m_ant->setX(Plane::WIDTH - 1);
	}

	if (m_ant->getY() < 0) {
		m_ant->setY(Plane::HEIGHT - 1);
	}

	if (m_ant->getX() > Plane::WIDTH - 1) {
		m_ant->setX(0);
	}

	if (m_ant->getY() > Plane::HEIGHT - 1) {
		m_ant->setY(0);
	}
}

void Plane::output() {
	// simple outputting here
	for (int i = 0; i < Plane::HEIGHT; i++) {
		for (int j = 0; j < Plane::WIDTH; j++) {
			if (i == m_ant->getY() && j == m_ant->getX()) {
				cout << "@"; // Output the ant position on the board
			}
			else if (m_plane[i][j] == Plane::OFF) {
				cout << "."; // for OFF colors, print a dot
			}
			else if (m_plane[i][j] == Plane::ON) {
				cout << "#"; // for ON colors, print an asterisk0rize
			}
		}
		cout << '\n'; // no endl for this plx.
	}
}