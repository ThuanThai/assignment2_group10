#pragma once
#include "customerNode.h"

//Default constructor
CustomerNode::CustomerNode() {
	this->customer = NULL;
	this->next = NULL;
}
//constructor
CustomerNode::CustomerNode(Customer* newCustomer) {
	this->customer = newCustomer;
	this->next = NULL;
}
//copy contructor
CustomerNode::CustomerNode(CustomerNode& customerNode) {
	this->customer = customerNode.customer;
	this->next = customerNode.next;
}

//destructor
CustomerNode::~CustomerNode() {
	this->customer = NULL;
	this->next = NULL;
}
//setter
void CustomerNode::setCustomer(Customer* newCustomer) {
	this->customer = newCustomer;
}
void CustomerNode::setNext(CustomerNode* nextNode) {
	this->next = nextNode;
}
//getter
Customer* CustomerNode::getCustomer() { return this->customer; }
CustomerNode* CustomerNode::getNext() { return this->next; }

bool CustomerNode::promoteCustomer()
{
	//if the customer has highest rank
	if (customer->getRank() == "VIP") {
		cout << "==========This customer is already a VIP==========" << endl;
		return false;
	}
	else {
		//if customer is a Guest and have returned 3 items
		if (customer->getRank() == "Guest" && customer->getItemReturned() >= 3) {
			Customer* tmp = new RegularCustomer;
			//copy all information from old account to new account
			((RegularCustomer*)tmp)->copy(this->customer);
			//delete old account
			delete this->customer;
			//set new account
			this->setCustomer(tmp);
			cout << "==========Finish promoting from Guest to Regular==========" << endl;
			return true;
		}
		//if customer is a Regular and have returned 3 items
		if (customer->getRank() == "Regular" && customer->getItemReturned() >= 3) {
			Customer* tmp = new VipCustomer;
			//copy all information from old account to new account
			((VipCustomer*)tmp)->copy(this->customer);
			//delete old account
			delete this->customer;
			//set new account
			this->setCustomer(tmp);
			cout << "==========Finish promoting from Regular to VIP==========" << endl;
			return true;
		}
	}
}