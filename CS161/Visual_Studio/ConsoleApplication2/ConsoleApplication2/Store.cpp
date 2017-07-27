/*************************************************************************************
** Store.cpp is the Store class function implementation file.
** Author:  Byron Kooima
** Date: 2017/03/10
** Description: CS161 Week10 Assignment 10 Project
** The Store class has two fields - a Product object vector and a Customer object 
** vector. It has a method to add a product to the inventory and a method to add a 
** customer to the members. It has a method to return a pointer to product with 
** a matching ID and a method to return a pointer to customer with a matching ID. 
** It also has a method to search the inventory for a given string and a method to add
** selected products to a customer's cart. Finally, it has a method to checkout the 
** customer's cart and provide a total bill.
***************************************************************************************/
#include <iostream>
#include <vector>
#include "Store.hpp"

/************************************************************************************
*                             Store::addProduct
* This function adds a product to the inventory vector.
*************************************************************************************/
void Store::addProduct(Product * p)
{
	Store::inventory.push_back(p);
}

/************************************************************************************
*                             Store::addMember
* This function adds a customer to the members vector.
*************************************************************************************/
void Store::addMember(Customer * c)
{
	Store::members.push_back(c);
}

/************************************************************************************
*                             Store::getProductFromID
* This function returns a Product object from the inventory vector.
*************************************************************************************/
Product * Store::getProductFromID(std::string pID)
{
	Product * prod;
	// default NULL
	prod = NULL;
	// loop through the inventory vector to find the matching product ID
	for (int i = 0; i < (inventory.size()); i++) {
		if ((inventory[i]->getIdCode()) == pID) {
			prod = inventory[i];
		}
	}
	// return Product object
	return prod;
}

/************************************************************************************
*                             Store::getMemberFromID
* This function returns a Customer object from the members vector.
*************************************************************************************/
Customer * Store::getMemberFromID(std::string cID)
{
	Customer * cust;
	// default to NULL
	cust = NULL;
	// loop through the members vector to find the matching customer ID
	for (int i = 0; i < (members.size()); i++) {
		if ((members[i]->getAccountID()) == cID) {
			cust = members[i];
		}
	}
	// return Customer object
	return cust;
}

/************************************************************************************
*                             Store::productSearch
* This function takes a search string and prints out inventory product information 
* based on that search.
*************************************************************************************/
void Store::productSearch(std::string str)
{
	Product* p;
	std::string prodTitle;
	std::string prodDesc;
	std::string insenseStr;
	insenseStr = str;
	
	// First create a case-insensitive (first letter) string
	if (isupper(str[0])) {
		insenseStr[0] = tolower(str[0]);
	}

	// loop through the inventory vector 
	for (int i = 0; i < (inventory.size()); i++) {
		// set Product object to current inventory object
		p = inventory[i];
		// get the Title and Description of the current Product
		prodTitle = p->getTitle();
		prodDesc = p->getDescription();

		// Check if search string is in the product title or the product description 
		// or the case-insensitive search string is in the product title or the
		// product description
		if ((prodTitle.find(str) != std::string::npos) || \
			(prodDesc.find(str) != std::string::npos) || \
			(prodTitle.find(insenseStr) != std::string::npos) \
			|| (prodDesc.find(insenseStr) != std::string::npos)){
			// Output the matching product information
			std::cout << p->getTitle() << std::endl;
			std::cout << "ID code: " << p->getIdCode() << std::endl;
			std::cout << "price: $" << p->getPrice() << std::endl;
			std::cout << p->getDescription() << std::endl << std::endl;
		}
	}
}

/************************************************************************************
*                             Store::addProductToMemberCart
* This function takes a customer and product ID as strings and adds the found product
* to the customers cart .
*************************************************************************************/
void Store::addProductToMemberCart(std::string pID, std::string mID)
{
	Product* p;
	Customer* c;

	// Get Product and Customer objects
	p = Store::getProductFromID(pID);
	c = Store::getMemberFromID(mID);

	// Check first to see if the product is not found
	if (p == NULL) {
		std::cout << "Product " << pID << " not found." << std::endl;
	}

	// Then check to see if the customer is not found
	else if (c == NULL) {
			std::cout << "Member " << mID << " not found." << std::endl;
	}

	// Finally check to see if there is quantity left
	else if (p->getQuantityAvailable() > 0) {
		// Add product to cart vector
		c->addProductToCart(pID);
		}
	else {
		// If no quantity is left
		std::cout << "Sorry, product " << pID << " is currently out of stock." << std::endl;
	}
}

/************************************************************************************
*                             Store::checkOutMember
* This function takes a customer ID as a string and calculates the value of the 
* products in the customers cart.
*************************************************************************************/
void Store::checkOutMember(std::string mID)
{
	Customer* c;
	Product* p;
	std::vector<std::string> mCart;
	double subTotal = 0.0;
	double totalPrice = 0.0;
	double shipping = 0.0;

	// Get customer object
	c = Store::getMemberFromID(mID);

	// check to see if the customer exists
	if (c != NULL) {
		// Get the customer's cart
		mCart = c->getCart();
	}

	// if the customer does not exist
	if (c == NULL) {
		std::cout << "Member " << mID << " not found." << std::endl;
	}
	// check if the customer's cart is empty
	else if (mCart.size() == 0) {
		std::cout << "There are no items in the cart." << std::endl;
	}
	// check out the customer's cart
	else {
		// loop through the cart vector
		for (int i = 0; i < mCart.size(); i++) {
			// set Product object to current cart object
			p = Store::getProductFromID(mCart[i]);
			// check if there is enough quantity left
			if ((p->getQuantityAvailable()) > 0) {
				// print the product title and price
				std::cout << p->getTitle() << " - $" << p->getPrice() << std::endl;
				// sum up the products to create subtotal
				subTotal += p->getPrice();
				// decrease the amount of products available
				p->decreaseQuantity();
			}
			// if the quantity is 0, let the user know
			else {
				std::cout << "Sorry, product #" << p->getIdCode() << ", \"" << p->getTitle() << "\", is no longer available." << std::endl;
			}
		}

		// print the cart subTotal
		std::cout << "Subtotal: $" << subTotal << std::endl;
		// check to see if the customer has premium status
		if (!(c->isPremiumMember())) {
			// if not premium set shipping rate
			shipping = 0.07;
		}
		// print the shipping costs
		std::cout << "Shipping Cost: $" << (subTotal*shipping) << std::endl;
		// print the total price of the cart
		totalPrice = subTotal + (subTotal * shipping);
		std::cout << "Total: $" << totalPrice << std::endl << std::endl;
	}
	// clear out the customer's cart after everything has been purchased
	c->emptyCart();
}

int main()
{
	Store store;
//	Product* product, *product2, *product3;
	Product* product = new Product("001", "Widget", "Awesome widget", 3.88, 5);
	store.addProduct(product);
	Product* product2 = new Product("123", "red blender", "sturdy blender perfect for making smoothies and sauces", 350, 2);
	store.addProduct(product2);
	Product* product3 = new Product("345", "hot air balloon", "fly into the sky in your own balloon - comes in red, blue, or chartreuse", 700, 10);
	store.addProduct(product3);
	Product* product4 = new Product("456", "oak and glass coffee table", "enjoy your coffee without setting it on the floor", 250, 10);
	store.addProduct(product4);
	Product* product5 = new Product("111", "giant robot", "everything you need to take over the world", 7000, 1);
	store.addProduct(product5);

	Customer* customer, *customer2, *customer3;
	customer = new Customer("Byron", "34534", true);
	store.addMember(customer);
	customer2 = new Customer("Heather", "12345", true);
	store.addMember(customer2);
	customer3 = new Customer("Isabelle", "34234", false);
	store.addMember(customer3);


	store.addProductToMemberCart("123", "34234");
	store.addProductToMemberCart("001", "34234");
	store.addProductToMemberCart("123", "34234");
	store.addProductToMemberCart("111", "34234");
	store.addProductToMemberCart("111", "12345");
	store.addProductToMemberCart("456", "12345");
	store.addProductToMemberCart("123", "12345");
	store.checkOutMember("12345");
	store.checkOutMember("34234");
	store.checkOutMember("34534");
//	store.productSearch("you");
	store.checkOutMember("34234");
	return 0;
}
