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
	if (customer->getRank() == "Vip") {
		cout << "This customer is already a VIP" << endl;
		return false;
	}
	else {
		if (customer->getRank() == "Guest") {
			Customer* tmp = new RegularCustomer;
			((RegularCustomer*)tmp)->copy(this->customer);
			delete this->customer;
			this->setCustomer(tmp);
			cout << "Finish promoting from Guest to Regular" << endl;
			return true;
		}
		if (customer->getRank() == "Regular") {
			Customer* tmp = new VipCustomer;
			((VipCustomer*)tmp)->copy(this->customer);
			delete this->customer;
			this->setCustomer(tmp);
			cout << "Finish promoting from Regular to VIP" << endl;
			return true;
		}
	}
}
