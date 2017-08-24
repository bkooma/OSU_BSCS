/*************************************************************************************
** UtilityBelt.hpp is the Utility Belt class specification file.
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

#ifndef UTILITYBELT_HPP
#define UTILITYBELT_HPP

#include "Item.hpp"

class UtilityBelt{
public:
	//Default constructor for UtilityBelt. Sets all private members to default values.
    UtilityBelt();
    
	//Adds Item to Belt and checks to ensure the Item name does not exist in the array.
    bool addItems(std::string iName, std::string uName, int qInput, bool special);
	// Remove Items from the Utility Belt
    void removeItems();
	// Remove Quantity of an Item
	void removeQty(std::string iName);
	// Prints the entire contents of the Utility Belt
    void print();
	// Prints just the Item name and quantity for displaying in the Game
	void printItems();
	// Returns an Item based on a passed-in search string
	Item returnItem(std::string iName);
	// Returns true/false if an Item exists in the Utility Belt
	bool searchItems(std::string iName);
    
	// Virtual Destructor
    virtual ~UtilityBelt();

private:
    Item* utilityBelt;
	Item* aPtr;
    int itemCount;     // next empty slot
    int arraySize;         // current size of array
	int total_items();   // calculate stuff using Item information
};

#endif /* UTILITYBELT_HPP */


