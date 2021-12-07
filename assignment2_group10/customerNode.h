#pragma once
#include <string>
using namespace std;
#define SIZE 100

typedef struct myString {
	string list[SIZE];
	int count = 0;
};

typedef struct Customer {
	string id;
	string name;
	string address;
	string phone;
	int numOfRentals;
	string customerType;
	myString listItemId;
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