#pragma once
#include "CustomerNode.h"
#include <iostream>
using namespace std;
class customerList {
private:
	CustomerNode* head;
public:
	//default constructor
	customerList() {
		head = NULL;
	}
	//constructor
	customerList(Customer* newCustomer) {
		head = new CustomerNode(newCustomer);
	}
	//destructor
	~customerList() {
		if (head == NULL) {
			return;
		}
		CustomerNode* temp = head;
		while (temp != NULL) {
			head = head->getNext();
			delete temp;
			temp = head;
		}
	}
	//getter
	CustomerNode* getHead() {
		return this->head;
	}
	void appendCustomerBack(Customer* newCustomer);
	void deleteCustomer(string id);
	CustomerNode* findCustomer(string id);
	void printCustomerList();
	void addNewCustomer();
	//functions print group of customer
	void printGuest();
	void printRegular();
	void printVIP();
};


