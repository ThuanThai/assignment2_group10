#pragma once
#include "Customer.h"

class VipCustomer :public Customer
{
private:
	int rewardPoint;
public:
	VipCustomer();
	VipCustomer(string id, string name, string address, string phone, string rank = "VIP") :Customer(id, name, address, phone, rank) { ; }
	~VipCustomer();

	void setRewardPoint(unsigned int num);
	int getRewardPoint();
	bool borrowing(Item* item);
	bool returning(Item* item);

	/*
	function supporting the customer promoting
	copy all information from old account to new account
	except (int)itemReturned and (string)rank
	*/
	void copy(Customer* C);
};
