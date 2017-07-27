/*************************************************************************************
** Item.cpp is the Item class function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/23
** Description: CS162 Week4 Project 2
** The Item class represents a Grocery List Item. It allows the user to create an Item
** with a name, unit, qty, and price. Item also contains methods to print the update 
** an Item with a tempItem values and a method to print the current Item parameters.
** It also contains a method called get_total that returns the extended price of an Item.
** It contains an Operator Overload to update the == option for itemName comparison.
***************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include "Item.hpp"

 /*********************************************************************
 ** Function: Item::Item
 ** Description: Default constructor for Item. Sets all private members
 **				to default values.
 ** Parameters:	N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Item members set to default.
 *********************************************************************/
Item::Item() {
	itemName = " ";
	unitName = " ";
	quantityOfUnit = 0;
	unitPrice = 0.0;
}

/*********************************************************************
** Function:		Item::Item
** Description:		User defined constructor for Item. Sets all Item members
**					to values provided by the user.
** Parameters:		name		Item Name
**					unit		Unit Name
**					qty			Qty of units
**					price		Price per unit
** Pre-Conditions:	N/A
** Post-Conditions: Item members values set by user.
*********************************************************************/
Item::Item(std::string name, std::string unit, int qty, double price) {
	this->itemName = name;
	this->unitName = unit;
	this->quantityOfUnit = qty;
	this->unitPrice = price;
}

/*********************************************************************
** Function:		Item::updateItem()
** Description:		Update Item with tempItem variable values
** Parameters:		Item 		Item object
** Pre-Conditions:	Two Items must be initialized.
** Post-Conditions: Item members values updated with tempItem values.
*********************************************************************/
void Item::updateItem(const Item& tempItem){
	unitName = tempItem.unitName;
	quantityOfUnit = tempItem.quantityOfUnit;
	unitPrice = tempItem.unitPrice;
//    quantityOfUnit += tempItem.quantityOfUnit;
    return;
}

/*********************************************************************
** Function:		Item::print()
** Description:		Print the current item parameters.
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Prints the Item parameters to the command prompt.
*********************************************************************/
void Item::print() {
	std::string str = std::to_string(quantityOfUnit);
	std::string tempString;

	tempString = str + " " + unitName;
	std::cout << std::setw(30) << itemName
		<< std::setw(25) << std::left << tempString
		<< std::left << "$" << std::setw(14) << unitPrice
		<< "$" << std::setw(14) << get_total() << "\n";
    
    return;
}

/*********************************************************************
** Function:		Item::get_itemName()
** Description:		Get the Item name
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a string of the itemName
*********************************************************************/
std::string Item::get_itemName(){
    return itemName;
}

/*********************************************************************
** Function:		Item::get_unitName()
** Description:		Get the Unit name
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a string of the unitName
*********************************************************************/
std::string Item::get_unitName() {
	return unitName;
}

/*********************************************************************
** Function:		Item::get_Quantity()
** Description:		Get the number of units for the Item
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns an int of the quantityOfUnit
*********************************************************************/
int Item::get_Quantity() {
	return quantityOfUnit;
}

/*********************************************************************
** Function:		Item::get_unitPrice()
** Description:		Get the price per unit
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a double of the unitPrice
*********************************************************************/
double Item::get_unitPrice() {
	return unitPrice;
}

/*********************************************************************
** Function:		Item::get_total()
** Description:		Get the Item extended price
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a double of the Qty * unitPrice
*********************************************************************/
double Item::get_total() {
	return quantityOfUnit * unitPrice;
}

/*********************************************************************
** Function:		Item::operator==()
** Description:		Overloaded comparison operator (==) to compare two
**					Item names
** Parameters:		Item		Item Object
** Pre-Conditions:	Two Items must be initialized
** Post-Conditions: Returns a boolean (T/F) if Item names are equal
*********************************************************************/
bool Item::operator==(const Item& rhs) const{
	if (this->itemName == rhs.itemName)
		return true;
	else    
		return false;
}
