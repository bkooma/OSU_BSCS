/***************************************************************************************
** Program name: main_Info.cpp is the University Information System implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Lab 4
** The Main program populates a default set of people and buildings to populate the 
** University Info System. It calls the University menu to prompt the user for input.
***************************************************************************************/

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "People.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Building.hpp"
#include "University.hpp"

int main() {

	// Seed the random generator
	std::srand(static_cast<unsigned int>(time(0)));

	// Update output formatting
	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	// Create a University Object
	University OSU;

	// Set the University name
	OSU.setName("Oregon State University");

	//Create a group of People to populate the University personnel list
	People *student1 = new Student("Byron Kooima", 37, 3.8);
	OSU.addPeople(student1);
	People *instructor1 = new Instructor("Han Solo", 56, 4.9);
	OSU.addPeople(instructor1);

	// Using alternate constructor to create random Age and GPA/Rating
	People *student2 = new Student("Random Dude");
	OSU.addPeople(student2);
	People *instructor2 = new Instructor("Darth Vader");
	OSU.addPeople(instructor2);

	// Create a group of Buildings located on the University
	Building *OSU1 = new Building("Adams Hall", 11168, "606 SW 15TH ST, CORVALLIS, OR 97331");
	OSU.addBuilding(OSU1);
	Building *OSU2 = new Building("Austin Hall", 107613, "2751 SW JEFFERSON WAY, CORVALLIS, OR 97331");
	OSU.addBuilding(OSU2);
	Building *OSU3 = new Building("Kelley Engineering Center", 152166, "110 SW PARK TERRACE, CORVALLIS, OR 97331");
	OSU.addBuilding(OSU3);
	
	// Display University Information System menu
	OSU.universityMenu();

	return 0;
}