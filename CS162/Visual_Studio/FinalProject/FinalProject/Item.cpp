/*************************************************************************************
** Item.cpp is the Item class function implementation file.
** Author:  Byron Kooima
** Date: 2017/08/16
** Description: CS162 Week8 Final Project
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
	itemDescription = " ";
	quantityOfUnit = 0;
	special = false;
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
Item::Item(std::string name, std::string unit, int qty, bool spcl) {
	this->itemName = name;
	this->itemDescription = unit;
	this->quantityOfUnit = qty;
	this->special = spcl;
}

/*********************************************************************
** Function:		Item::updateItem()
** Description:		Update Item with tempItem variable values
** Parameters:		Item 		Item object
** Pre-Conditions:	Two Items must be initialized.
** Post-Conditions: Item members values updated with tempItem values.
*********************************************************************/
void Item::updateItem(const Item& tempItem){
//	unitName = tempItem.unitName;
//	quantityOfUnit = tempItem.quantityOfUnit;
//	unitPrice = tempItem.unitPrice;
	quantityOfUnit += tempItem.quantityOfUnit;
    return;
}

void Item::removeQty()
{
	quantityOfUnit--;
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
	std::string isSpecial = "";

	if (get_special())
		isSpecial = "*";

	isSpecial = isSpecial + itemName;
	std::cout << std::setw(15) << isSpecial
		<< std::setw(5) << std::left << str
		<< std::setw(70) << std::left << itemDescription << std::endl;
    
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
** Function:		Item::get_itemDesc()
** Description:		Get the Item's Description
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a string of the itemDescription
*********************************************************************/
std::string Item::get_itemDesc() {
	return itemDescription;
}

/*********************************************************************
** Function:		Item::get_Quantity()
** Description:		Get the number of units for the Item
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a string of the quantityOfUnit
*********************************************************************/
int Item::get_Quantity() {
	return quantityOfUnit;
}

/*********************************************************************
** Function:		Item::get_special()
** Description:		Get the price per unit
** Parameters:		N/A
** Pre-Conditions:	N/A
** Post-Conditions: Returns a bool for special items
*********************************************************************/
bool Item::get_special() {
	return special;
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
