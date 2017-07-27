/*************************************************************************************
** Building.hpp is the Building parent class specification file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Lab4
** The Building class represents a University buildings. It allows the user to populate
** the name, sqFt, and Address of every building. It contains getter and setter
** methods for the name/sqFt/Address.
***************************************************************************************/

#ifndef Building_hpp
#define Building_hpp

#include <iostream>

class Building {
public:
	// Default constructor for Building.
	Building();
	// User defined constructor for Building.
	Building(std::string, int, std::string);

	// Setters:
	// Set the Building name
	void setName(std::string);
	// Set the Building square footage
	void setSqFt(int);
	// Set the Building address
	void setAddress(std::string);

	// Getters:
	// Get the Building name
	std::string getName();
	// Get the Building square footage
	int getSqFt();
	// Get the Building address
	std::string getAddress();

	// Destructor
	virtual ~Building();

protected:
	// Variables for Building
	std::string name;
	int bldgSqFt;
	std::string bldgAddress;
};

#endif /* Building_hpp */