#pragma once
#include "customerNode.h"
#include <iostream>
using namespace std;
class customerList {
private:
	customerNode* head;
public:
	customerList() {
		head = NULL;
	}
	customerList(Customer newCustomer) {
		head = new customerNode(newCustomer);
	}
	//getter
	customerNode* getHead() {
		return this->head;
	}
	void appendCustomerBack(Customer newCustomer);
	void deleteCustomer(string id);
	void printCustomerList();
};
