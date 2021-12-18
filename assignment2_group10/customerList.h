#pragma once
#include "CustomerNode.h"
#include <iostream>
using namespace std;
class customerList {
private:
	CustomerNode* head;
public:
	customerList() {
		head = NULL;
	}
	customerList(Customer* newCustomer) {
		head = new CustomerNode(newCustomer);
	}
	//getter
	CustomerNode* getHead() {
		return this->head;
	}
	void appendCustomerBack(Customer* newCustomer);
	void printCustomerList();
};