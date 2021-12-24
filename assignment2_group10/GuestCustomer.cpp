#pragma once
#include "GuestCustomer.h"
GuestCustomer::GuestCustomer() {
	this->id = "";
	this->name = "";
	this->address = "";
	this->phone = "";
	this->itemRented = 0;
	this->itemReturned = 0;
	this->rank = "Guest";
}

GuestCustomer::~GuestCustomer() { ; }

bool GuestCustomer::borrowing(Item* item) {
	if (item->borrowing() && itemRented <= MAX_BORROW) {
		this->rList.push_back(item->getId());
		this->itemRented++;
		return true;
	}
	return false;
}

bool GuestCustomer::returning(Item* item) {
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

