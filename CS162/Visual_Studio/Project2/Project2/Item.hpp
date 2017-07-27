/*************************************************************************************
** Item.hpp is the Item class specification file.
** Author:  Byron Kooima
** Date: 2017/07/14
** Description: CS162 Week4 Project 2
** The Item class represents a Grocery List Item. It allows the user to create an Item
** with a name, unit, qty, and price. Item also contains methods to print the update
** an Item with a tempItem values and a method to print the current Item parameters.
** It also contains a method called get_total that returns the extended price of an Item.
** It contains an Operator Overload to update the == option for itemName comparison.
***************************************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <string>

class Item{
    
public:
    // Description: Default constructor for Item. Sets all private members to default values.
	Item();

	//User defined constructor for Item. Sets all Item members to values provided by the user.
	Item(std::string iName, std::string uName, int qty, double uPrice = 0);

	// Getters:
	//Get the Item name
	std::string get_itemName();
	//Get the Unit name
	std::string get_unitName();
	//Get the number of units for the Item
	int get_Quantity();
	//Get the price per unit
	double get_unitPrice();

	// Class functions:
	//Update Item with tempItem variable values
	void updateItem(const Item& em);
	//Print the current item parameters.
	void print();
	//Get the Item extended price
	double get_total();
	//Overloaded comparison operator (==) to compare two Item names
	bool operator==(const Item &rhs) const;

private:
	// Variables for the Item
    std::string itemName;
    std::string unitName;
    int quantityOfUnit;
    double unitPrice;
};

#endif /* Item_hpp */
