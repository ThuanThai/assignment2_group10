#pragma once
#include "Customer.h"
class VipCustomer :public Customer
{
private:
	int rewardPoint;
public:
	VipCustomer();
	~VipCustomer();

	void setRewardPoint(unsigned int num);
	int getRewardPoint();
};
