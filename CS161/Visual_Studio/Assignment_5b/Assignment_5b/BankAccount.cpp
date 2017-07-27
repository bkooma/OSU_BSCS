// BankAccount.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "BankAccount.hpp"

BankAccount::BankAccount(std::string name, std::string ID, double balance)
{
	customerName = name;
	customerID = ID;
	customerBalance = balance;
}

// destructor
BankAccount::~BankAccount()
{}

std::string BankAccount::getCustomerName()
{
	return customerName;
}

std::string BankAccount::getCustomerID()
{
	return customerID;
}

double BankAccount::getCustomerBalance()
{
	return customerBalance;
}

double BankAccount::withdraw(double wdAmount)
{
	return customerBalance -= wdAmount;
}

double BankAccount::deposit(double dpAmount)
{
	return customerBalance += dpAmount;
}

