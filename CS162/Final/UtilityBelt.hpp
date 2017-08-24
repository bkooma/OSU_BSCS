/*************************************************************************************
** List.cpp is the List class specification file.
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

#ifndef UTILITYBELT_HPP
#define UTILITYBELT_HPP

#include "Item.hpp"

class UtilityBelt{
public:
    UtilityBelt();
    
//    Item get_Item(); // menu options
    void addItems(std::string iName, std::string uName, int qInput, bool special);
    void removeItems();
	void removeQty(std::string iName);
    void print();
	void printItems();
	Item returnItem(std::string iName);
	bool searchItems(std::string iName);
    
    virtual ~UtilityBelt();
    
private:
    Item* utilityBelt;
	Item* aPtr;
    int itemCount;     // next empty slot
    int arraySize;         // current size of array
	int total_items();   // calculate stuff using Item information
};

#endif /* UTILITYBELT_HPP */


