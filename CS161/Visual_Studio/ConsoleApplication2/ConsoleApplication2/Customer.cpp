/*************************************************************************************
** Customer.cpp is the Customer class function implementation file.
** Author:  Byron Kooima
** Date: 2017/03/10
** Description: CS161 Week10 Assignment 10 Project
** The Customer class has a field - a string vector for cart. It has a constructor that
** takes a name string, account ID string and a premium member boolean. It has get 
** methods to return corresponding data member. It contains a method that adds products
** to a customer cart, a method to check if a member is premium, and a method to empty
** the cart.
***************************************************************************************/

#include <string>
#include <vector>
#include "Customer.hpp"

// Customer constructor
Customer::Customer(std::string n, std::string a, bool pm)
{
	name = n;
	accountID = a;
	premiumMember = pm;
}

/************************************************************************************
*                             Customer::getAccountID
* This function returns the current customer account ID.
*************************************************************************************/
std::string Customer::getAccountID()
{
	return accountID;
}

/************************************************************************************
*                             Customer::getCart
* This function returns the current customer cart as a vector.
*************************************************************************************/
std::vector<std::string> Customer::getCart()
{
	return cart;
}

/************************************************************************************
*                             Customer::addProductToCart
* This function adds a product ID string to the customer cart vector.
*************************************************************************************/
void Customer::addProductToCart(std::string pID)
{
	cart.push_back(pID);
}

/************************************************************************************
*                             Customer::isPremiumMember
* This function returns the current customer premium status as a boolean.
*************************************************************************************/
bool Customer::isPremiumMember()
{
	return premiumMember;
}

/************************************************************************************
*                             Customer::emptyCart
* This function emptys the current customer cart vector.
*************************************************************************************/
void Customer::emptyCart()
{
	while (!cart.empty()) {
		cart.pop_back();
	}
}
