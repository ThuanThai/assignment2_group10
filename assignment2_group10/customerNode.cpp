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