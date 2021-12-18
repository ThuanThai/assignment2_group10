#pragma once
#include "Customer.h"
class VipCustomer:public Customer
{
private:
	unsigned int rewardPoint;
public:
	VipCustomer() :Customer() { this->rewardPoint = 0; }
	~VipCustomer();

	void setRewardPoint(unsigned int num);
	unsigned int getRewardPoint();
};


