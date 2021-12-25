#pragma once
#include "Customer.h"
class RegularCustomer:public Customer
{
public:
	RegularCustomer();
	RegularCustomer(string id, string name, string address, string phone, string rank = "Regular") :Customer(id, name, address, phone, rank) { ; }
	~RegularCustomer();
	bool borrowing(Item* item);
	bool returning(Item* item);
};

