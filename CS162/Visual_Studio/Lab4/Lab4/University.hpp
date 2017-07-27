/*************************************************************************************
** University.hpp is the University parent class specification file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Lab 4
** The University class represents a University Information Syste. It allows the user
** Print information about all of the buildings or Personnel assigned to the university.
** It also allows the user to pick an individual to do work based on whether they are
** a student or instructor. Additional options were added to allow the user to manually
** add a Person to the university roster. Additionally, the user can export and import
** a text file containing the University personnel.
***************************************************************************************/

#ifndef University_hpp
#define University_hpp

#include <iostream>
#include <vector>
#include "Building.hpp"
#include "People.hpp"

class University {
public:
	// Default constructor for University.
	University();

	// Setters:
	// Set the University name
	void setName(std::string);
	// Set the number of Buildings in the info system
	void setNumBuilding(int);
	// Set the number of People in the info system
	void setNumPeople(int);

	// Getters:
	// Get the University name
	std::string getName();
	// Get the number of buildings on the university
	int getNumBuilding();
	// Get the number of people at the university
	int getNumPeople();

	// Class functions:
	// Provide user with menu options
	void universityMenu();

	// Add People objects to the ppl vector
	void addPeople(People*);
	// Add Building objects to the bldg vector
	void addBuilding(Building*);
	// Print the University information
	void printUniversity();
	// Print the People information
	void printPeople();
	// Print the Building information
	void printBuilding();

	// Destructor
	virtual ~University();

protected:
	//Variables for the University
	std::string name;
	int n;
	int m;
	int menuOpt;
	std::vector <People*> ppl;
	std::vector <Building*> bldg;
};

#endif /* University_hpp */
