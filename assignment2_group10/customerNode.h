#pragma once
#include <string>
#include "Customer.h"
#include "GuestCustomer.h"
#include "RegularCustomer.h"
#include "VipCustomer.h"
using namespace std;


class CustomerNode {
private:
	Customer* customer;
	CustomerNode* next;
public:
	//constructor
	CustomerNode(Customer* newCustomer) {
		this->customer = newCustomer;
		next = NULL;
	}
	//setter
	void setCustomer(Customer* newCustomer) {
		this->customer = newCustomer;
	}
	void setNext(CustomerNode* nextNode) {
		this->next = nextNode;
	}
	//getter
	Customer* getCustomer() { return this->customer; }
	CustomerNode* getNext() { return this->next; }
};