#pragma once
#include "customerList.h"
#include "support.h"
void customerList::appendCustomerBack(Customer* newCustomer) {
	CustomerNode* newCustomerNode = new CustomerNode(newCustomer);
	CustomerNode* current = this->head;
	if (current == NULL) {
		this->head = newCustomerNode;
		return;
	}
	while (current->getNext() != NULL) {
		current = current->getNext();
	}
	current->setNext(newCustomerNode);
}

void customerList::deleteCustomer(string id) {
	CustomerNode* current = head;
	CustomerNode* prev = NULL;
	if (current->getCustomer()->getId() == id && current->getNext() != NULL) {
		head = head->getNext();
		delete current;
		return;
	}
	while (current != NULL && current->getCustomer()->getId() != id) {
		prev = current;
		current = current->getNext();
	}
	if (current == NULL) {
		cout << "Cannot find the required infor\n";
		return;
	}
	cout << "Delete Successfully\n";
	system("pause");
	prev->setNext(current->getNext());
	delete current;
}

CustomerNode* customerList::findCustomer(string id) {
	CustomerNode* current = this->head;
	while (current != NULL && current->getCustomer()->getId() != id) {
		current = current->getNext();
	}
	if (current == NULL) {
		return NULL;
	}
	return current;
}

void customerList::printCustomerList() {
	CustomerNode* current = this->head;
	int i = 1;
	while (current != NULL) {
		cout << "\t\t ===== Customer " << i << " =====\n";
		current->getCustomer()->Output();
		current = current->getNext();
		i++;
	}
}

void customerList::addNewCustomer()
{
	Customer* newCustomer;
	string newId;
	string newName;
	string newAddress;
	string newPhone;
	string newRank;
	do {
		cin.ignore();
		cout << "Valid id syntax: Cxxx | ID must be unique" << endl;
		cout << "Enter customer ID: ";
		getline(cin, newId);
		
	} while (!isValidCustomerId(newId) || this->findCustomer(newId) != NULL);

	cout << "Enter customer name: ";
	getline(cin, newName);

	cout << "Enter customer address: ";
	getline(cin, newAddress);

	cout << "Enter customer phone number: ";
	getline(cin, newPhone);

	do {
		cout << "Valid customer rank: Guest | Regular | VIP" << endl;
		cout << "Enter customer rank: ";
		getline(cin, newRank);
	} while (!isValidRank(newRank));
	if (newRank._Equal("Guest")) {
		newCustomer = new GuestCustomer(newId, newName, newAddress, newPhone);
	}
	else if(newRank._Equal("Regualar"))
	{
		newCustomer = new RegularCustomer(newId, newName, newAddress, newPhone);
	}
	else {
		newCustomer = new VipCustomer(newId, newName, newAddress, newPhone);
	}
	this->appendCustomerBack(newCustomer);
}
