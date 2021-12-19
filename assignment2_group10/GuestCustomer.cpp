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

