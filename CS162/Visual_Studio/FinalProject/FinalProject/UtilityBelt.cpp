/*************************************************************************************
** UtilityBelt.cpp is the UtilityBelt class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
** The UtilityBelt class represents a List of Items. It allows the user to store Item
** objects in a UtilityBelt object. When a user adds a new item, the Item object is 
** created and added to the List object. The Items are stored in a dynamic array[7]. 
** The array resizes when additional Item objects are added above the initial four.
** There are UtilityBelt functions to Add Items, Remove Items, and Display the Belt.
** There is also a function to calculate the total items of all the Items in the list
***************************************************************************************/

#include "UtilityBelt.hpp"
#include "inputVerification.cpp"

#include <string>
#include <iomanip>
#include <algorithm>
#include <iostream>


/*********************************************************************
** Function: UtilityBelt::UtilityBelt()
** Description: Default constructor for Belt. Sets all private members
**				to default values.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: List members set to default.
*********************************************************************/
UtilityBelt::UtilityBelt(){
    itemCount = 0;
    arraySize = 7;
	utilityBelt = new Item[arraySize];
}

/*********************************************************************
** Function:		UtilityBelt::add_Items(string, string, int, bool)
** Description:		Adds Item to Belt and checks to ensure the Item
** 					name does not exist in the array. If it does, the
** 					Item qty is updated. The function also determines
**					if the array of the UtilityBelt has filled up.
** Parameters:		iName		Item Name
**					uName		Item description
**					qInput		Quantity of Item
**					special		Determine if the Item is required
** Pre-Conditions:	UtilityBelt object is initialized
** Post-Conditions: UtilityBelt array is updated with Creature Items
*********************************************************************/
bool UtilityBelt::addItems(std::string iName, std::string uName, int qInput, bool special){
	Item tempItem = Item(iName, uName, qInput, special);
    bool itemExist = false;
	std::string updatePrompt{};
    
    // If the new Item matches an existing Item in the List object, 
	// adds quantity to current Item of the same name.
    for (int i=0; i < itemCount; ++i)
        if (utilityBelt[i] == tempItem){
			itemExist = true;
			utilityBelt[i].updateItem(tempItem);
        }
    
	// If there are no spaces left in the array, let the player know to remove an Item
	if (itemCount == arraySize) {
		std::cout << "The Utility Belt is full. It can only hold " << arraySize << " items.\n";
		std::cout << "Manage inventory first to remove unneeded items.\n";
		return false;
	}
	// If there were no Items in the Utility Belt with the same name,
	// add the item to the Belt
    else if (!itemExist){
        utilityBelt[itemCount] = tempItem;
        itemCount++;
		// Bool to keep track if Item was added
		return true;
    }   
    return false;
}


/*********************************************************************
** Function:		UtilityBelt::removeItems()
** Description:		Allows the user to select an Item from the List
** 					object for deletion. Function re-sequences the array
** 					if the user deletes the Item
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Removes Item from Belt and re-allocates the array
*********************************************************************/
void UtilityBelt::removeItems(){
//    bool match = false;
    int listItem = 0;
    
	// Make sure there are Items in the Utility Belt
	if (itemCount > 0) {
		print();

		char verString[100] = { "Please select an item number from inventory to remove (0 to exit)\n" };
		std::cout << verString;

		SafeInput <int>(listItem,
			[=](int Input) -> bool {
			return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input >= 0 && Input < itemCount + 1));
		}, verString);

		// If the user doesn't exit, delete the item number from the list
		if (listItem != 0) {
			if (utilityBelt[listItem - 1].get_special())
			{
				std::cout << utilityBelt[listItem - 1].get_itemName() << " is a special item. You're going to need it later.\n";
			}
			else {
				std::cout << "You have deleted ";
				std::cout << utilityBelt[listItem - 1].get_itemName();
				std::cout << " from the Utility Belt. \n";

				// Shift the array Items left
				for (int i = listItem - 1; i < itemCount - 1; i++)
					utilityBelt[i] = utilityBelt[i + 1];

				itemCount--;
			}
		}
	}
	else
		std::cout << "\nYour Utility Belt is empty. Nothing to delete.\n";
    return;
}

/*********************************************************************
** Function:		UtilityBelt::removeQty(string)
** Description:		Removes one Qty from Item. If Item qty goes to 0,
**					the Item is deleted from the array.
** Parameters:		iName		Item name to search for
** Pre-Conditions:	N/A
** Post-Conditions: Removes Qty from Belt and re-allocates the array
*********************************************************************/
void UtilityBelt::removeQty(std::string iName)
{
	// Look through the Belt to find the Item
	for (int i = 0; i < itemCount; ++i) {
		if (utilityBelt[i].get_itemName() == iName) {
			utilityBelt[i].removeQty();
		}
		// Shift the contents of the Belt array
		if (utilityBelt[i].get_Quantity() == 0) {
			for (int j = i; j < itemCount - 1; j++)
			utilityBelt[i] = utilityBelt[i + 1];
			// Decrement item counts
			itemCount--;
		}
	}
}

/*********************************************************************
** Function:		UntilityBelt::print()
** Description:		Prints the entire Belt for all of the Items. Also
** 					provides the total for all Items
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Prints the full List
*********************************************************************/
void UtilityBelt::print(){
	int totalItems = 0;
	if (itemCount > 0) {
		std::cout << std::string(100, '-') << std::endl;
		std::cout << std::setw(10) << std::left << "Item #";
		std::cout << std::setw(15) << "Item Name";
		std::cout << std::setw(5) << "Qty";
		std::cout << std::setw(70) << "Description";
		std::cout << std::endl << std::string(100, '-') << std::endl;

		for (int i = 0; i < itemCount; ++i) {
			std::cout << "#" << std::left << std::setw(9) << i + 1;
			utilityBelt[i].print();
			totalItems++;
		}
		std::cout << std::string(100, '=') << std::endl;
		std::cout << "* = Special Tool (helps progress through the game)\n";
		std::cout << std::setw(30) << "Utility Belt Total:";
		std::cout << std::setw(25) << totalItems << "\n\n";
	}
	else
		std::cout << "The Utility Belt is empty. Please add items before printing.\n";
    return;
}

/*********************************************************************
** Function:		UntilityBelt::printItems()
** Description:		Prints a linear list of the Item names and Qty
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Prints just the Items/Qty for the Game screen
*********************************************************************/
void UtilityBelt::printItems()
{
	// Step through Belt array and format the output
	for (int i = 0; i < itemCount; ++i) {
		std::cout << utilityBelt[i].get_itemName() << "(" << utilityBelt[i].get_Quantity() << "), ";
	}
}

/*********************************************************************
** Function:		UntilityBelt::returnItem(string)
** Description:		Returns the Item by item name
** Parameters:		iName		Item name
** Pre-Conditions:	N/A
** Post-Conditions: Returns the Item found by searching the Belt array
*********************************************************************/
Item UtilityBelt::returnItem(std::string iName)
{
	for (int i = 0; i < itemCount; ++i) {
		if (utilityBelt[i].get_itemName() == iName)
			return utilityBelt[i];
	}
	return utilityBelt[0];
}

/*********************************************************************
** Function:		UntilityBelt::searchItems(string)
** Description:		Search the Belt array for a specific Item
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a bool for whether the Item exists
*********************************************************************/
bool UtilityBelt::searchItems(std::string iName)
{
	for (int i = 0; i < itemCount; ++i) {
		if (utilityBelt[i].get_itemName() == iName)
			return true;
	}
	return false;
}

/*********************************************************************
** Function:		UtilityBelt::total_items()
** Description:		Calculate the total Items in the Utility Belt
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns an int for the total number of Items
*********************************************************************/
int UtilityBelt::total_items(){
    int total = 0;
    
    for (int i=0; i < itemCount; ++i)
        total += utilityBelt[i].get_Quantity();
    
    return total;
}

/*********************************************************************
** Function:		UtilityBelt::~UtilityBelt()
** Description:		UtilityBelt Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Removes dynamic array memory allocated for the Belt
*********************************************************************/
UtilityBelt::~UtilityBelt(){
    delete[] utilityBelt;
}
