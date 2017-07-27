#include "BankAccount.hpp"
#include <iostream>
#include <string>

int main()
{
	std::string CustomerName;
	std::string CustomerID;
	double Balance;
	double theWithdraw;
	double theDeposit;

	BankAccount account1("Harry Potter", "K4637", 8032.78);
	account1.withdraw(244.0);
	account1.withdraw(3012.58);
	account1.deposit(37.54);
	account1.withdraw(1807.12);
	account1.deposit(500.00);
	double finalBalance = account1.getCustomerBalance();

	std::cout << "Final Balance: " << finalBalance << std::endl;
}