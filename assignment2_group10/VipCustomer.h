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

	void copy(Customer* C) {
		id = C->getId();
		name = C->getName();
		phone = C->getPhone();
		address = C->getAddress();
		rank = "Vip";
		rewardPoint = 0;
	}
};
