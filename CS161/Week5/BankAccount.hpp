//BankAccount.hpp
#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <string>

class BankAccount
{
private:
	std::string customerName;
	std::string customerID;
	double customerBalance;

public:
	// constructor with parameters
	BankAccount(std::string, std::string, double);

	// Methods for withdrawal and deposits
	double withdraw(double);
	double deposit(double);

	// getters
	std::string getCustomerName();
	std::string getCustomerID();
	double getCustomerBalance();

	//destructor
	~BankAccount();
};

#endif // !BANKACCOUNT_HPP

