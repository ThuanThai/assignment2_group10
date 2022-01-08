#pragma once
#include "Customer.h"

class VipCustomer :public Customer
{
private:
	int rewardPoint;
public:
	// constructor
	VipCustomer();
	VipCustomer(string id, string name, string address, string phone, string rank = "VIP");
	//destructor
	~VipCustomer();

	//setter
	void setRewardPoint(unsigned int num);
	// getter
	int getRewardPoint();
	// borrow function
	bool borrowing(Item* item);
	// return function
	bool returning(Item* item);

	/*
	function supporting the customer promoting
	copy all information from old account to new account
	except (int)itemReturned and (string)rank
	*/
	void copy(Customer* C);
};
