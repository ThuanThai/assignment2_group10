#pragma once
#include "Customer.h"
#include "string"
#define MAX_BORROW 2
class GuestCustomer :public Customer
{
public:
	GuestCustomer();
	GuestCustomer(string id, string name, string address, string phone, string rank = "Guest") :Customer(id, name, address, phone, rank) { ; }
	~GuestCustomer();
	bool borrowing(Item* item);
	bool returning(Item* item);
};
