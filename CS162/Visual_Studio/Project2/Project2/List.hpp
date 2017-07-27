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

#ifndef List_hpp
#define List_hpp

#include "Item.hpp"

class List{
public:
	//Default constructor for List. Sets all private members to default values.
    List();
    
    //Get the Item parameters from the user and returns an Item object.
    Item get_Item();

    //Runs List::get_Item() and checks to ensure the Item name does not exist in the array.
    // If it does, the user can update/not update the Item in the List. The function also
    // increases the size of the List array and populates the List array with Items
    void add_Items();

    //Allows the user to select an Item from the List object for deletion. Function
    // re-sequences the array if the user deletes the Item
    void remove_Items();

    //Prints the entire List for all of the Items. Also provides the Cart total for all Items
    void print();
    
    //List Destructor
    ~List();
    
private:
    Item* groceryList;		// Grocery List Item pointer
	Item* aPtr;				// Temp Item pointer
    int itemCount;			// Total items in the List
    int arraySize;      	// Size of array

    //Calculate the total price for all of the List Items
	double total_price();
};

#endif /* List_hpp */


