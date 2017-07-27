#include "userMenu.hpp"
#include "inputVerification.cpp"
#include <iostream>


int userMenu::makeSelection()
{
	std::cout << "Let's simulate Langton's ant. Please select an option from the following menu: \n\n ";
	std::cout << "1. Begin simulation";
	std::cout << "2. Set table size [X:Y]";
	std::cout << "3. Select the ant's starting position";
	std::cout << "4. Select the number of moves for the ant";
	std::cout << "5. Exit";
	std::cin >> choice;

//	SafeInput <int>(choice,
//		[=](int Input) -> bool {
//		return (Input > 0 && Input < 6);
//	});

	return choice;
}