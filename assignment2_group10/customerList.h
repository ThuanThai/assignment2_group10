#pragma once
#include "CustomerNode.h"
#include <iostream>
using namespace std;
class customerList {
private:
	CustomerNode* head;
public:
	//default constructor
	customerList();
	//constructor
	customerList(Customer* newCustomer);
	//destructor
	~customerList();

	//getter
	CustomerNode* getHead();

	// add a customer
	void appendCustomerBack(Customer* newCustomer);
	
	// delete a customer
	void deleteCustomer(string id);
	
	// read customer file
	void readCustomerFile(string fileName, itemList iList);
	
	// save customer file
	void saveFileCustomer(string fileName);
	
	// find customer
	CustomerNode* findCustomer(string searchEl);
	
	// update a customer searched by id
	void updateCustomer(string id);
	
	// print customer list
	void printCustomerList();
	
	// add new customer
	void addNewCustomer();\
	
	// borrow function
	void borrowing(itemList& iList);
	
	// return function
	void returning(itemList& iList);

	//check for valid customer
	bool isValidCustomer(Customer* customer, itemList iList);
	
	//functions print group of customer
	void printGuest();
	void printRegular();
	void printVIP();

	//sort functions
	void sort_by_id();
	void sort_by_name();

	//check if customer rent an item  
	bool isItemRented(string id);
	
	//function print customers by searching for Id or name
	void search_for(string keyword);
};


