#pragma once
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

bool VipCustomer::borrowing(Item* item) {
	if (item->borrowing()) {
		this->rList.push_back(item->getId());
		this->itemRented++;
		return true;
	}
	return false;
}

bool VipCustomer::returning(Item* item) {
	for (int i = 0; i < rList.size(); i++) {
		if (item->getId()._Equal(this->rList[i]) && item->returning()) {
			this->rList.erase(this->rList.begin() + i);
			this->itemRented--;
			this->itemReturned++;
			this->rewardPoint += 10;
			return true;
		}
	}
	return false;
}

