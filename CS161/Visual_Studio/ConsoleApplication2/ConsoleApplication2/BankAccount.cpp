/*************************************************************************************
** BankAccount.cpp is the BankAccount class function implementation file. 
** Author:  Byron Kooima
** Date: 2017/02/07
** Description: The BankAccount class has a string data member called customerName, 
** a string data member called customerID, and a double data member called 
** customerBalance.  The class has a constructor that takes two strings and a 
** double (name, ID, balance) and uses them to initialize the data members.  The data 
** members of this class do not need to be set after they are initialized, so this 
** class doesn't need any set methods - therefore the constructor will directly assign 
** values to the data members instead of calling set methods to do it.  The class has 
** a get method for each data member.  It has a method called withdraw that takes a 
** double parameter and deducts it from the customer balance (the balance is allowed 
** to be negative). It has a method called deposit that takes a double parameter and 
** adds it to the current balance. 
***************************************************************************************/

#include <iostream>
#include <string>
#include "BankAccount.hpp"

// BankAccount constructor
BankAccount::BankAccount(std::string name, std::string ID, double balance)
{
	customerName = name;
	customerID = ID;
	customerBalance = balance;
}

// Bank Account destructor
BankAccount::~BankAccount()
{}

/************************************************************************************
*                             BankAccount::getCustomerName
* This function returns the current customer Name.
*************************************************************************************/
std::string BankAccount::getCustomerName()
{
	return customerName;
}

/************************************************************************************
*                             BankAccount::getCustomerID
* This function returns the current customer ID.
*************************************************************************************/
std::string BankAccount::getCustomerID()
{
	return customerID;
}

/************************************************************************************
*                             BankAccount::getCustomerBalance
* This function returns the current account balance for the customer.
*************************************************************************************/
double BankAccount::getCustomerBalance()
{
	return customerBalance;
}

/************************************************************************************
*                             BankAccount::withdraw
* This function calculates and returns the balance after an ammount is withdrawn.
*************************************************************************************/
double BankAccount::withdraw(double wdAmount)
{
	return customerBalance -= wdAmount;
}

/************************************************************************************
*                             BankAccount::deposit
* This function calculates and returns the balance after an ammount is deposited.
*************************************************************************************/
double BankAccount::deposit(double dpAmount)
{
	return customerBalance += dpAmount;
}

