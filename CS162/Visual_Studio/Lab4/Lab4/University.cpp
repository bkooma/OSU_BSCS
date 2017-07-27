/*************************************************************************************
** University.cpp is the University class function implementation file.
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

#include "University.hpp"
#include "People.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Building.hpp"
#include "userMenu.hpp"
#include "inputVerification.cpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>

/*********************************************************************
** Function: University::University
** Description: Default constructor for University. Sets all protected
**				members to default values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Universtiy members set to default.
*********************************************************************/
University::University()
{
	name = "Oregon State University";
	n = 0;
	m = 0;
	menuOpt = -1;
}

/*********************************************************************
** Function:		University::setName()
** Description:		Set the University name
** Parameters:		uName		University's name
** Pre-Conditions:	N/A
** Post-Conditions: Sets name to uName
*********************************************************************/
void University::setName(std::string uName)
{
	name = uName;
}

/*********************************************************************
** Function:		University::setNumBuilding()
** Description:		Set the number of buildings in the University
** Parameters:		numBldg		University's number of buildings
** Pre-Conditions:	N/A
** Post-Conditions: Sets n to numBldg
*********************************************************************/
void University::setNumBuilding(int numBldg)
{
	n = numBldg;
}

/*********************************************************************
** Function:		University::setNumPeople()
** Description:		Set the number of people at the University
** Parameters:		numPeople	University's number of personnel
** Pre-Conditions:	N/A
** Post-Conditions: Sets m to numPeople
*********************************************************************/
void University::setNumPeople(int numPeople)
{
	m = numPeople;
}

/*********************************************************************
** Function:		University::getName()
** Description:		Get the University name
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a string of the name
*********************************************************************/
std::string University::getName()
{
	return name;
}

/*********************************************************************
** Function:		University::getNumBuilding()
** Description:		Get the number of buildings at the University 
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns an int of the number of buildings
*********************************************************************/
int University::getNumBuilding()
{
	return n;
}

/*********************************************************************
** Function:		University::getNumPeople()
** Description:		Get the number of people at the University
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns an int of the number of people
*********************************************************************/
int University::getNumPeople()
{
	return m;
}

/*********************************************************************
** Function:		University::universityMenu()
** Description:		Get the menu selection from the user and perform
**					the requested option
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: The menu option is executed
*********************************************************************/
void University::universityMenu()
{
	int personNum = 0;
	// Print the university information
	printUniversity();

	// Populate the userMenu class vector with some options
	userMenu menu;
	menu.add_choice("Print information on University Buildings.");
	menu.add_choice("Print information on University Personnel.");
	menu.add_choice("Choose University Personnel to Do Work (Homework/Grade Papers).");
	menu.add_choice("Add Additional Personnel to the University Roster.");
	menu.add_choice("Import Personnel List from External Source (*.txt).");
	menu.add_choice("Export Personnel List to External Source (*.txt).");
	menu.add_choice("Exit the University Program.");

	// Make sure the choice is valid
	menuOpt = menu.makeChoice();

	// Populate a sub userMenu class vector with additional options for the doWork function
//	userMenu subMenu;
//	subMenu.add_choice("");

	while (menuOpt != 7) {
		std::cout << "\n";

		// Print the university building information
		if (menuOpt == 1) {
			printBuilding();
		}
		// Print the university personnel information
		else if (menuOpt == 2) {
			printPeople();
		}
		// All user to identify personnel to do work
		else if (menuOpt == 3) {
			// Print the current personnel list
			printPeople();
			// If there are personnel in the list
			if (m > 0) {
				// Input validation function to make sure the quantity variable entered by user is valid
				char verString[100] = { "Please select a number for the University personnel you would like to do work (0 to exit)\n" };
				std::cout << verString;

				SafeInput <int>(personNum,
					[=](int Input) -> bool {
					return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input >= 0 && Input < m + 1));
				}, verString);

				// Have the selected person do work using a random number generator
				if (personNum != 0) {
					ppl[personNum - 1]->do_work(80);
				}
			}
			else std::cout << "There are no personnel to do work.";
		}
		
		// Add personnel to the university roster
		else if (menuOpt == 4) {
			// Set the variables
			std::string personPrompt;
			int personAge;
			double sGpa;
			double iRating;
			std::string sName;

			// Prompt for the personnel name
			std::cout << "Please enter the Person's name:\n";
			std::cin.ignore();
			std::getline(std::cin, sName);

			char varString2[100] = { "Please enter the Person's age (Between 15 and 100):\n" };
			std::cout << varString2;
			SafeInput <int>(personAge,
				[=](int Input) -> bool {
				return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input >= 15 && Input < 101));
			}, varString2);

			// Make sure the user is selecting a Student or an Instructor
			char varString[100] = { "Please enter S or I\n" };
			std::cout << "Please indicate if the individual is a Student or Instructor (S/I)." << std::endl;
			SafeInput <std::string>(personPrompt,
				[=](std::string Input) -> bool {
				std::transform(Input.begin(), Input.end(),
					Input.begin(), ::toupper);
				return (Input.compare("S") == 0 || Input.compare("I") == 0);
			}, varString);

			// If it is a Student, enter the GPA
			if (personPrompt == "s" || personPrompt == "S") {
				char varString3[100] = { "Please enter the Student's GPA (Between 0.0 and 4.0):\n" };
				std::cout << varString3;
				SafeInput <double>(sGpa,
					[=](double Input) -> bool {
					return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0.0 && Input <= 4.0));
				}, varString3);

				// Create the student object
				Student* student = new Student(sName,personAge,sGpa);
				// Push into the vector
				addPeople(student);
			}
			// If it is an Instructor, enter the Rating
			else if (personPrompt == "i" || personPrompt == "I") {
				char varString3[100] = { "Please enter the Instructor's Rating (Between 0.0 and 5.0):\n" };
				std::cout << varString3;
				SafeInput <double>(iRating,
					[=](double Input) -> bool {
					return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0.0 && Input <= 5.0));
				}, varString3);

				// Create the instructor object
				Instructor* instructor = new Instructor(sName, personAge, iRating);
				// Push into the vector
				addPeople(instructor);
			}
		}
		
		// Import from external text file
		else if (menuOpt == 5) {
			std::vector<std::string> myLines;
			std::string line;
			std::string inFileName;

			// Prompt the user for an input file name
			std::cout << "Please enter the name of the University Personnel text file.\n";
			std::cin >> inFileName;

			// Set ifstream parameter to user file name
			std::ifstream inFile(inFileName);

			// Check to see if the file can be opened
			if (inFile.is_open()) {

				// Grab each line of the file
				for (std::string line; std::getline(inFile, line);) {
					myLines.push_back(line);
				}

				// For each line in the file, check to see if it is a student or instructor
				for (size_t i = 0; i < myLines.size(); i++) {
					if (myLines[i] == "Student") {
						// If it is a student, populate the vector with the new Student object
						Student* student = new Student(myLines[i+1], std::stoi(myLines[i+2]), std::stod(myLines[i+3]));
						ppl.push_back(student);
					}
					else if (myLines[i] == "Instructor") {
						// If it is an instructor, populate the vector with a new Instructor object
						Instructor* instructor = new Instructor(myLines[i + 1], std::stoi(myLines[i + 2]), std::stod(myLines[i + 3]));
						ppl.push_back(instructor);
					}
				}
				// Close the input file
				inFile.close();
			}
			else std::cout << inFileName << " cannot be opened. Please try again\n";

			// Clear the vector
			myLines.clear();
		}

		// Export the personnel information to an external file
		else if (menuOpt == 6) {
			std::string outFileName;

			// Prompt the user for the output file name
			std::cout << "Please enter the name of the University Personnel output file.\n";
			std::cin >> outFileName;

			// Set ofstream parameter to user file name
			std::ofstream outFile(outFileName);

			// Send the University personnel info to the output file
			for (size_t i = 0; i < ppl.size(); i++) {
				Student* sPeople = dynamic_cast<Student*>(ppl[i]);
				Instructor* iPeople = dynamic_cast<Instructor*>(ppl[i]);

				if (sPeople) {
					outFile << "Student\n" << sPeople->getName() << "\n" << sPeople->getAge() << "\n" << sPeople->getGpa() << "\n\n";
				}
				else if (iPeople) {
					outFile << "Instructor\n" << iPeople->getName() << "\n" << iPeople->getAge() << "\n" << iPeople->getRating() << "\n\n";
				}
			}

			//Close the output file
			outFile.close();
		}
		menuOpt = menu.makeChoice();
	}
}

/*********************************************************************
** Function:		University::addPeople()
** Description:		Push the new People object into the vector
** Parameters:		People *p1		The People object
** Pre-Conditions:	N/A
** Post-Conditions: Increases the vector with the addtional object
*********************************************************************/
void University::addPeople(People *p1)
{
	ppl.push_back(p1);
	m = ppl.size();
}

/*********************************************************************
** Function:		University::addBuilding()
** Description:		Push the new Building object into the vector
** Parameters:		Building *b1		The Building object
** Pre-Conditions:	N/A
** Post-Conditions: Increases the vector with the addtional object
*********************************************************************/
void University::addBuilding(Building *b1)
{
	bldg.push_back(b1);
	n = bldg.size();
}

/*********************************************************************
** Function:		University::printUniversity()
** Description:		Print the current University information
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: The output is displayed on the command prompt
*********************************************************************/
void University::printUniversity()
{
	std::cout << "This is the " << name << " information system.\n";
	std::cout << "There are currently " << n << " buildings & " << m << " Personnel assigned to this university.\n";
}

/*********************************************************************
** Function:		University::printPeople()
** Description:		Print the current People information
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: The output is displayed on the command prompt
*********************************************************************/
void University::printPeople()
{
	std::vector<People *>::const_iterator iterator;
	int listCount = 1;

	// If the number of personnel is not 0
	if (m != 0){
		for (iterator = ppl.begin(); iterator != ppl.end(); iterator++) {
			// Establish a pointer to People and set it to the iterator pointer
			People* pPeople = *iterator;

			// Perform a dynamic cast down from the base Person class to the Student derived class. If the person selected 
			// is not a Student derived class the sPeople Student object is NULL and can be used in a boolean argument.
			Student* sPeople = dynamic_cast<Student*>(pPeople);

			// Perform a dynamic cast down from the base Person class to the Instructor derived class. If the person selected 
			// is not an Instructor derived class the iPeople Instructor object is NULL and can be used in a boolean argument.
			Instructor* iPeople = dynamic_cast<Instructor*>(pPeople);

			// Format the Personnel list 
			std::cout << std::string(95, '-') << std::endl;
			std::cout << std::setw(10) << std::left << "Person #";
			std::cout << std::left << std::setw(15) << "Position";
			std::cout << std::setw(30) << "Name";
			std::cout << std::setw(5) << "Age";

			// If the object is a Student
			if (sPeople) {
				std::cout << std::setw(10) << "GPA" << std::endl;
				std::cout << std::setw(10) << std::left << listCount;
				std::cout << std::setw(15) << "Student:";
				std::cout << std::setw(30) << sPeople->getName();
				std::cout << std::setw(5) << sPeople->getAge();
				std::cout << std::setw(10) << sPeople->getGpa() << "\n";

			}
			// If the object is an Instructor
			else if (iPeople) {
				std::cout << std::left << std::setw(10) << "Rating" << std::endl;
				std::cout << std::setw(10) << std::left << listCount;
				std::cout << std::setw(15) << "Instructor:";
				std::cout << std::setw(30) << iPeople->getName();
				std::cout << std::setw(5) << iPeople->getAge();
				std::cout << std::setw(10) << iPeople->getRating() << "\n";
			}
			listCount++;
		}
	}	else {
		std::cout << "There were no people assigned to this university. Please add people before printing.\n";
	}
	std::cout << std::string(95, '=') << std::endl;
}

/*********************************************************************
** Function:		University::printBuilding()
** Description:		Print the current Building information
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: The output is displayed on the command prompt
*********************************************************************/
void University::printBuilding()
{
	if (n != 0) {
		for (size_t i = 0; i<bldg.size();i++){

			std::cout << std::string(95, '-') << std::endl;
//			std::cout << std::setw(10) << std::left << "Building #";
//			std::cout << std::left << std::setw(15) << "Position";
			std::cout << std::left<< std::setw(30) << "Building Name";
			std::cout << std::setw(15) << "Square Feet";
			std::cout << std::setw(45) << "Address" << std::endl;

			std::cout << std::setw(30) << bldg[i]->getName();
			std::cout << std::setw(15) << bldg[i]->getSqFt();
			std::cout << std::setw(45) << bldg[i]->getAddress() << "\n";
		}
	}
	else {
		std::cout << "There were no buildings assigned to this university. Please add buildings before printing.\n";
	}
	std::cout << std::string(95, '=') << std::endl;
}

/*********************************************************************
** Function:		University::~University()
** Description:		University Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: The dynamic memory pointers are deleted from the
**					vectors
*********************************************************************/
University::~University()
{
	for (size_t i = 0; i < ppl.size(); i++) {
		delete ppl[i];
	}
	for (size_t j = 0; j < bldg.size(); j++) {
		delete bldg[j];
	}
}
