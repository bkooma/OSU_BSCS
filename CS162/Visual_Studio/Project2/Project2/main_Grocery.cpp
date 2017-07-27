/*************************************************************************************
** Program name: main_Grocery.cpp is the Grocery Shopping List implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Project 2
** The Main program allows the user to select the menu option to Add items to a grocery
** list, Remove items from the list, and Print the list.
***************************************************************************************/


#include <iostream>
#include <iomanip>
#include "List.hpp"
#include "inputVerification.cpp"
#include "userMenu.hpp"

int main() {

	int menuOpt = -1;
	List list;
	
	// Update output formatting
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "Welcome to the Grocery Shopping List. \n";
    
    // Populate the menu options
    userMenu menu;
    menu.add_choice("Add items to the Shopping List. ");
    menu.add_choice("Remove items from the Shopping List. ");  
    menu.add_choice("Print the Shopping List. ");            
	menu.add_choice("Exit the Shopping List program. "); 
    
	// make a valid selection from the menu
	menuOpt = menu.makeChoice();
    
    while (menuOpt != 4){
        std::cout << "\n";
        
		// Add items to the list
		if (menuOpt == 1)
			list.add_Items();
		// Remove items from the list
		else if (menuOpt == 2)
			list.remove_Items();
		// Print out the current list
		else if (menuOpt == 3)   
			list.print();
		else
			std::cout << "\n Thank you for shopping. Good bye!\n" << std::endl;

		// Repeat the menu options
		menuOpt = menu.makeChoice();
	}
    
    std::cout << std::endl;
    return 0;
}
