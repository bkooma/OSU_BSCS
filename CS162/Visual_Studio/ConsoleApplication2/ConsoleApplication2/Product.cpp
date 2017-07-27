/*************************************************************************************
** Product.cpp is the Product class function implementation file.
** Author:  Byron Kooima
** Date: 2017/03/10
** Description: CS161 Week10 Assignment 10 Project
** The Product class has five fields - a product id string, a product title string, a
** product description string, a product price double, and a product quantity int. It
** has get methods to return corresponding data member. It contains a method that 
** decreases the current product quantity by one.
***************************************************************************************/

#include <string>
#include "Product.hpp"

// Product constructor 
Product::Product(std::string id, std::string t, std::string d, double p, int qa)
{
	idCode = id;
	title = t;
	description = d;
	price = p;
	quantityAvailable = qa;
}

/************************************************************************************
*                             Product::getIdCode
* This function returns the current product idCode.
*************************************************************************************/
std::string Product::getIdCode()
{
	return idCode;
}

/************************************************************************************
*                             Product::getTitle
* This function returns the current product title.
*************************************************************************************/
std::string Product::getTitle()
{
	return title;
}

/************************************************************************************
*                             Product::getDescription
* This function returns the current product description.
*************************************************************************************/
std::string Product::getDescription()
{
	return description;
}

/************************************************************************************
*                             Product::getPrice
* This function returns the current product price.
*************************************************************************************/
double Product::getPrice()
{
	return price;
}

/************************************************************************************
*                             Product::getQuantityAvailable
* This function returns the current product availability.
*************************************************************************************/
int Product::getQuantityAvailable()
{
	return quantityAvailable;
}

/************************************************************************************
*                             Product::decreaseQuantity
* This function returns the decremented product quantity.
*************************************************************************************/
void Product::decreaseQuantity()
{
	quantityAvailable = quantityAvailable - 1;
}
