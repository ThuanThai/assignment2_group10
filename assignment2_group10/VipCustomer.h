#pragma once
#include "Customer.h"
class VipCustomer:public Customer
{
private:
	int rewardPoint;
public:
	VipCustomer();
	~VipCustomer();

	void setRewardPoint(unsigned int num);
	int getRewardPoint();
	bool borrowing(Item* item);
	bool returning(Item* item);
};


