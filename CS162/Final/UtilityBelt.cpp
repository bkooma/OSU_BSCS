/*************************************************************************************
** List.cpp is the List class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Project 2
** The List class represents a Grocery List. It allows the user to store Item
** objects in a List object. When a user adds a new item, the Item object is created
** and added to the List object. The Items are stored in a dynamic array[4]. The array
** resizes when additional Item objects are added above the initial four.
** There are List functions to Add Items, Remove Items, and Display the shopping list.
** There is also a function to calculate the total price of all the Items in the list
***************************************************************************************/

#include "UtilityBelt.hpp"

#include <string>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include "inputVerification.cpp"

/** Initialize a List by default
 size is set to 4, first empty space is at 0 */
UtilityBelt::UtilityBelt(){
    itemCount = 0;
    arraySize = 5;
	utilityBelt = new Item[arraySize];
}

/** Add an Item to the List */
void UtilityBelt::addItems(std::string iName, std::string uName, int qInput, bool special){
	Item tempItem = Item(iName, uName, qInput, special);
//    Item tempItem = get_Item();
    bool itemExist = false;
	std::string updatePrompt{};
    
    // If the new Item matches an existing Item in the List object, 
	// adds quantity to current Item of the same name.
    for (int i=0; i < itemCount; ++i)
        if (utilityBelt[i] == tempItem){
			itemExist = true;
			utilityBelt[i].updateItem(tempItem);
        }
    
	// If there are no spaces left in the array, copy current List
	// to a new larger List 
	if (itemCount == arraySize) {
		// Update array size for new, bigger array
		arraySize = itemCount+1;
		// Create a temporary List array
		aPtr = new Item[arraySize];
		// Copy values from the current List to the new List
		for (int index = 0; index < arraySize-1; index++)
		{
			aPtr[index] = utilityBelt[index];
		}
		// Delete the original List
		delete[] utilityBelt;
		// Assign the new larger array to the old parameter
		utilityBelt = aPtr;
	}

    // If there were no Items in the List with the same name,
	// add the item to the List
    if (!itemExist){
        utilityBelt[itemCount] = tempItem;
        itemCount++;
    }   
    return;
}


/** Removes an Item from the List
 @param a is the Item to be removed from the List */
void UtilityBelt::removeItems(){
//    bool match = false;
    int listItem = 0;
    
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

void UtilityBelt::removeQty(std::string iName)
{
	for (int i = 0; i < itemCount; ++i) {
		if (utilityBelt[i].get_itemName() == iName) {
			utilityBelt[i].removeQty();
		}
		if (utilityBelt[i].get_Quantity() == 0) {
			for (int j = i; j < itemCount - 1; j++)
			utilityBelt[i] = utilityBelt[i + 1];

			itemCount--;
		}
	}
}


/** Prints out the List */
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
		std::cout << std::setw(30) << "Utility Belt Total:";
		std::cout << std::setw(25) << totalItems << "\n\n";
	}
	else
		std::cout << "The Utility Belt is empty. Please add items list before printing.\n";
    return;
}

void UtilityBelt::printItems()
{
	for (int i = 0; i < itemCount; ++i) {
		std::cout << utilityBelt[i].get_itemName() << "(" << utilityBelt[i].get_Quantity() << ")  ,";
	}
}

Item UtilityBelt::returnItem(std::string iName)
{
	for (int i = 0; i < itemCount; ++i) {
		if (utilityBelt[i].get_itemName() == iName)
			return utilityBelt[i];
	}
	return utilityBelt[0];
}

bool UtilityBelt::searchItems(std::string iName)
{
	for (int i = 0; i < itemCount; ++i) {
		if (utilityBelt[i].get_itemName() == iName)
			return true;
	}
	return false;
}

/** Calculate the total price of all Items in List */
int UtilityBelt::total_items(){
    int total = 0;
    
    for (int i=0; i < itemCount; ++i)
        total += utilityBelt[i].get_Quantity();
    
    return total;
}

/** Frees memory used by dynamic array */
UtilityBelt::~UtilityBelt(){
    delete[] utilityBelt;
}
