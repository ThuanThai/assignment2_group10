#pragma once
#include "RegularCustomer.h"

//constructor
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

// borrow function
bool RegularCustomer::borrowing(Item* item) {
	if (item->borrowing()) {
		this->rList.push_back(item->getId());
		this->itemRented++;
		return true;
	}
	else {
		cout << "The item is out of stock\n";
		return false;
	}
	return false;
}

// return function
bool RegularCustomer::returning(Item* item) {
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

void RegularCustomer::copy(Customer* C)
{
	id = C->getId();
	name = C->getName();
	phone = C->getPhone();
	address = C->getAddress();
	itemRented = C->getItemRented();
	rList = C->getItemRentedList();
	rank = "Regular";
	itemReturned = 0;
}