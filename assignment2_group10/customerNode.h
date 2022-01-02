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
	//Default constructor
	CustomerNode();
	//constructor
	CustomerNode(Customer* newCustomer);
	//copy contructor
	CustomerNode(CustomerNode& customerNode);
	//destructor
	~CustomerNode();
	//setter
	void setCustomer(Customer* newCustomer);
	void setNext(CustomerNode* nextNode);
	//getter
	Customer* getCustomer();
	CustomerNode* getNext();

	//promote customer
	bool promoteCustomer();
};