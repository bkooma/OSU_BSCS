/*************************************************************************************
** userMenu.hpp is the userMenu class specification file.
** Author:  Byron Kooima
** Date: 2017/07/02
** Description: CS162 Re-usable menu class object
***************************************************************************************/

#ifndef USERMENU_HPP
#define USERMENU_HPP
#include <vector>
#include <string>

class userMenu
{
private:
	std::vector<std::string> choice;
	int selectedChoice;

public:
	void add_choice(std::string);
//	void display_choice(size_t);
	void printMenu();
	int makeChoice();
};

#endif // !USERMENU_HPP