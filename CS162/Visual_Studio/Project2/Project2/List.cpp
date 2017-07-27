/*************************************************************************************
** List.cpp is the List class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Project 2
** The List class represents a Grocery List. It allows the user to store Item
** objects in a List object. When a user adds a new item, the Item object is created
** and added to the List object. The Items are stored in a dynamic array[4]. The array
** resizes when additional Item objects are added above the inital four. 
** There are List functions to Add Items, Remove Items, and Display the shopping list.
** There is also a function to calculate the total price of all the Items in the list
***************************************************************************************/

#include <string>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include "inputVerification.cpp"
#include "List.hpp"

 /*********************************************************************
 ** Function: List::List
 ** Description: Default constructor for List. Sets all private members
 **				to default values.
 ** Parameters:	N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: List members set to default.
 *********************************************************************/
List::List(){
    itemCount = 0;
    arraySize = 4;
	groceryList = new Item[4];
	aPtr = NULL;
}

/*********************************************************************
** Function:		List::get_Item()
** Description:		Get the Item parameters from the user and returns
** 					an Item object.
** Parameters:		N/A
** Pre-Conditions:	Runs from List::add_Item()
** Post-Conditions: Returns an Item object with iName,uName,qInput,uPrice
*********************************************************************/
Item List::get_Item(){
    std::string iName;
    std::string uName;
    int qInput;
    double uPrice;
    
    std::cin.ignore();     // clear buffer
    
    std::cout << "Please enter the new item name: \n";
    std::getline(std::cin, iName);
    std::cout << "Please enter the units of measure for the item (i.e. can, box, pound, or ounce)\n";
    getline(std::cin, uName);
    
    // Ask for the quantity
   	char varString[100] = { "Please enter the quantity of units for the item\n" };
	std::cout << varString;
	// Input validation function to make sure the quantity variable entered by user is valid
	SafeInput <int>(qInput,
		[=](int Input) -> bool {
		return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input < std::numeric_limits<int>::max()));
	}, varString);
        
    // Ask for the price
	char varString2[100] = { "Please enter item price per unit ($)\n" };
	std::cout << varString2;
	// Input validation function to make sure the price variable entered by user is valid
	SafeInput <double>(uPrice,
		[=](double Input) -> bool {
		return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0.0 && std::numeric_limits<double>::max()));
	}, varString2);
   
    return Item(iName, uName, qInput, uPrice);
}


/*********************************************************************
** Function:		List::add_Items()
** Description:		Runs List::get_Item() and checks to ensure the Item
** 					name does not exist in the array. If it does, the
** 					user can update/not update the Item in the List.
** 					The function also increases the size of the List
** 					array and populates the List array with Items
** Parameters:		N/A
** Pre-Conditions:	List object is initialized
** Post-Conditions: List array is updated with user Items
*********************************************************************/
void List::add_Items(){
    Item tempItem = get_Item();
    bool itemExist = false;
	std::string updatePrompt{};
    
    // If the new Item matches an existing Item in the List object, 
	// prompt the user to overwrite the current Item of the same name.
    for (int i=0; i < itemCount; ++i)
        if (groceryList[i] == tempItem){
			itemExist = true;
			std::cout << "The item name entered matches an item in the list.\n Do you want to update the item in inventory (Y/N)?" << std::endl;
			char varString[100] = { "Please enter Y/N\n" };

			SafeInput <std::string>(updatePrompt,
				[=](std::string Input) -> bool {
				std::transform(Input.begin(), Input.end(),
					Input.begin(), ::toupper);
				return (Input.compare ("Y") == 0 || Input.compare ("N") == 0);
			}, varString);

			if (updatePrompt == "y" || updatePrompt == "Y") {
				groceryList[i].updateItem(tempItem);
			}
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
			aPtr[index] = groceryList[index];
		}
		// Delete the original List
		delete[] groceryList;
		// Assign the new larger array to the old parameter
		groceryList = aPtr;
	}

    // If there were no Items in the List with the same name,
	// add the item to the List
    if (!itemExist){
        groceryList[itemCount] = tempItem;
        itemCount++;
    }   
    return;
}


/*********************************************************************
** Function:		List::remove_Item()
** Description:		Allows the user to select an Item from the List
** 					object for deletion. Function re-sequences the array
** 					if the user deletes the Item
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Removes Item from List and re-allocates the array
*********************************************************************/
void List::remove_Items(){

	int listItem = 0;
    
	if (itemCount > 0) {
		print();

		char verString[100] = { "Please select an item number from the list to remove (0 to exit)\n" };
		std::cout << verString;

		SafeInput <int>(listItem,
			[=](int Input) -> bool {
			return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input >= 0 && Input < itemCount + 1));
		}, verString);

		// If the user doesn't exit, delete the item number from the list
		if (listItem != 0) {
			std::cout << "You have deleted ";
			std::cout << groceryList[listItem - 1].get_itemName();
			std::cout << " from the Shopping List. \n";

			for (int i = listItem - 1; i < itemCount - 1; i++)
				groceryList[i] = groceryList[i + 1];

			itemCount--;
		}
	}
	else
		std::cout << "The shopping list is empty. Nothing to delete.\n";
    return;
}


/*********************************************************************
** Function:		List::print()
** Description:		Prints the entire List for all of the Items. Also
** 					provides the Cart total for all Items
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Prints the full List
*********************************************************************/
void List::print(){

	if (itemCount > 0) {
		std::cout << std::string(95, '-') << std::endl;
		std::cout << std::setw(10) << std::left << "Item #";
		std::cout << std::setw(30) << "Item Name";
		std::cout << std::setw(25) << "# of Units";
		std::cout << std::setw(15) << "$ per Unit";
		std::cout << std::setw(15) << "Ext Price";
		std::cout << std::endl << std::string(95, '-') << std::endl;

		for (int i = 0; i < itemCount; ++i) {
			std::cout << "#" << std::left << std::setw(9) << i + 1;
			groceryList[i].print();
		}
		std::cout << std::string(95, '=') << std::endl;
		std::cout << std::setw(35) << "Shopping List Total:";
		std::cout << "$" << std::setw(25) << total_price() << "\n\n";
	}
	else
		std::cout << "The shopping list is empty. Please add items list before printing.\n";
    return;
}

/*********************************************************************
** Function:		List::total_price()
** Description:		Calculate the total price for all of the List Items
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a double for the $Total
*********************************************************************/
double List::total_price(){
    double total = 0;
    
    for (int i=0; i < itemCount; ++i)
        total += groceryList[i].get_total();
    
    return total;
}

/*********************************************************************
** Function:		List::~List()
** Description:		List Destructor
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Removes dynamic array memory allocated for the List
*********************************************************************/
List::~List(){
    delete[] groceryList;
}
