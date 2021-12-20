#include "VipCustomer.h"
VipCustomer::VipCustomer()
{
	this->id = "";
	this->name = "";
	this->address = "";
	this->phone = "";
	this->itemRented = 0;
	this->itemReturned = 0;
	this->rank = "Vip";
	this->rewardPoint = 0;
}
VipCustomer::~VipCustomer() { ; }
void VipCustomer::setRewardPoint(unsigned int num) { this->rewardPoint = num; }
int VipCustomer::getRewardPoint() { return this->rewardPoint; }

