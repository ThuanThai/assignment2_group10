#pragma once
#include "Customer.h"
#include "string"

#define MAX_BORROW 2

class GuestCustomer :public Customer
{
public:
	//constructor
	GuestCustomer();
	GuestCustomer(string id, string name, string address, string phone, string rank = "Guest") :Customer(id, name, address, phone, rank) { ; }
	
	//destructor
	~GuestCustomer();

	// borrow function
	bool borrowing(Item* item);
	// return function
	bool returning(Item* item);
};
