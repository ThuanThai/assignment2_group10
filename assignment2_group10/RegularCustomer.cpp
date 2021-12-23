#pragma once
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
