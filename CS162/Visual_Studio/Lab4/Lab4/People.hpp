/*************************************************************************************
** People.hpp is the People parent class specification file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Lab4
** The People class represents a Personnel Base Class for the University. It allows the
** user to populate the name and age of every person. It contains getter and setter
** methods for the Base name/age. It also has a random age generator to allow the
** Derived classes to have a simplified constructor. It can also return the hours worked
** by the person.
***************************************************************************************/

#ifndef People_hpp
#define People_hpp

class People {
public:
	// Default constructor for People.
	People();
	
	// User defined constructor for People.
	People(std::string, int);

	// Setters:
	// Set the Person name
	void setName(std::string);
	// Set the Person age
	void setAge(int);
	// Set the Person age with a random integer
	void setRandomAge();

	//Getters:
	// Get the Person's name
	std::string getName();
	// Get the Person's age
	int getAge();
	// Get the Person's hours worked
	int getHours();

	// Class functions:
	// Abstract function for the derived classes to set work
	virtual void do_work(int) = 0;

	// Destructor
	virtual ~People();

protected:
	// Variables for the People and Derived classes
	std::string name;
	int age;
	int workHours;
};

#endif /* People_hpp */
