#include "RegularCustomer.h"

RegularCustomer::RegularCustomer()
{
	this->id = "";
	this->name = "";
	this->address = "";
	this->phone = "";
	this->itemRented = 0;
	this->itemReturned = 0;
	this->rank = "Regular";
}

RegularCustomer::~RegularCustomer() { ; }

bool RegularCustomer::borrowing(Item* item) {
	if (item->borrowing()) {
		this->rList.push_back(item->getId());
		this->itemRented++;
		return true;
	}
	return false;
}

bool RegularCustomer::returning(Item* item) {
	if (this->rList.size() == 0)
		return false;
	for (int i = 0; i < rList.size(); i++) {
		if (item->getId()._Equal(this->rList[i]) && item->returning()) {
			this->rList.erase(this->rList.begin() + i);
			this->itemRented--;
			this->itemReturned++;
			return true;
		}
	}
	return false;
}
