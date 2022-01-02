#pragma once
#include "Customer.h"
class RegularCustomer :public Customer
{
public:
	RegularCustomer();
	RegularCustomer(string id, string name, string address, string phone, string rank = "Regular") :Customer(id, name, address, phone, rank) { ; }
	~RegularCustomer();
	bool borrowing(Item* item);
	bool returning(Item* item);

	/*
	function supporting the customer promoting
	copy all information from old account to new account
	except (int)itemReturned and (string)rank
	*/
	void copy(Customer* C);
};
