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
	if (item->getLoanType()._Equal("2-day")) {
		cout << "Your account need to be upgraded to rent this item\n";
		return false;
	}
	if (item->borrowing() && itemRented < MAX_BORROW) {
		this->rList.push_back(item->getId());
		this->itemRented++;
		return true;
	}
	else if (!item->borrowing()) {
		cout << "The item is out of stock\n";
		return false;
	}
	else if (itemRented >= MAX_BORROW) {
		cout << "Your account need to be upgraded to rent more item\n";
		return false;
	}
	return false;
}

bool GuestCustomer::returning(Item* item) {
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

