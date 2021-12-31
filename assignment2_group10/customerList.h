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
	void readCustomerFile(string fileName, itemList iList);
	void saveFileCustomer(string fileName);
	CustomerNode* findCustomer(string id);
	void updateCustomer(string id);
	void printCustomerList();
	void addNewCustomer();
	void borrowing(itemList& iList);
	void returning(itemList& iList);
	bool isValidCustomer(Customer* customer, itemList iList);
	//functions print group of customer
	void printGuest();
	void printRegular();
	void printVIP();
	//sort functions
	void sort_by_id();
	void sort_by_name();
};


