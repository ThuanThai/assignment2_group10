#pragma once
#include <string>
using namespace std;
#define SIZE 100

typedef struct Customer {
	string id;
	string name;
	string address;
	string phone;
	int numOfRentals;
	string customerType;
	string listItemId[SIZE];
};

class customerNode {
private:
	Customer customer;
	customerNode* next;
public:
	//constructor
	customerNode(Customer newCustomer) {
		this->customer = newCustomer;
		next = NULL;
	}
	//setter
	void setCustomer(Customer newCustomer) {
		this->customer = newCustomer;
	}
	void setNext(customerNode* nextNode) {
		this->next = nextNode;
	}
	//getter
	Customer getCustomer() {
		return this->customer;
	}
	customerNode* getNext() {
		return this->next;
	}
};