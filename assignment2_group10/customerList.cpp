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

void customerList::readCustomerFile(string fileName, itemList iList) {
	ifstream fileIn(fileName, ios_base::in);
	if (!fileIn) {
		cerr << "Cannot Open File\n";
	}
	while (!fileIn.eof())
	{
		Customer* customer = new Customer;
		Customer* newCustomer = NULL;
		customer->readCustomerFile(fileIn);
		if (customer->getRank().compare("Guest") == 0) {
			newCustomer = new GuestCustomer;
			newCustomer->setCustomerType(customer);
		}
		else if (customer->getRank().compare("Regular") == 0) {
			newCustomer = new RegularCustomer;
			newCustomer->setCustomerType(customer);
		}
		else if (customer->getRank().compare("VIP") == 0) {
			newCustomer = new VipCustomer;
			newCustomer->setCustomerType(customer);
		}
		if (isValidCustomer(newCustomer, iList)) {
			appendCustomerBack(newCustomer);
		}
		else {
			cout << "Cannot add " << newCustomer->getId() << " into the list!!!" << endl;
		}
	}
	fileIn.close();
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

void customerList::borrowing(itemList& iList) {
	string id;
	cout << "Input customer's ID: "; getline(cin, id);
	if (findCustomer(id) == NULL) {
		cout << "Invalid customer'sID\n";
		return;
	}
	Customer* customer = findCustomer(id)->getCustomer();
	cout << "\t\t====== Customer's Information =====\n";
	cout << customer;
	cout << "Input item's ID: "; getline(cin, id);
	if (iList.findItem(id) == NULL) {
		cout << "Invalid item's ID\n";
		return;
	}
	Item* item = iList.findItem(id)->getItem();
	if (customer->borrowing(item)) cout << "Successfully borrowing \n" << item;
	else cout << "Item out of stock\n";
}

void customerList::returning(itemList& iList) {
	string id;
	cout << "Input customer's ID: "; getline(cin, id);
	if (findCustomer(id) == NULL) {
		cout << "Invalid customer'sID\n";
		return;
	}
	Customer* customer = findCustomer(id)->getCustomer();
	if (customer->getItemRented() == 0) {
		cout << "Your account has not yet made a loan\n";
		return;
	}
	cout << "\t\t====== Customer's Information =====\n";
	cout << customer;
	cout << "Input item's ID: "; getline(cin, id);
	if (iList.findItem(id) == NULL) {
		cout << "Invalid item's ID\n";
		return;
	}
	Item* item = iList.findItem(id)->getItem();
	if (customer->returning(item)) cout << "Successfully returning \n" << item;
	else cout << "The item is not borrowed by this account\n";
}

void customerList::printGuest()
{
	// check if the list is empty
	if (head == NULL) {
		cout << "No customer in the list" << endl;
		return;
	}
	int count = 0; //variable counting the needed customer
	CustomerNode* tmp = head;
	while (tmp != NULL) {
		if (compare_string(tmp->getCustomer()->getRank(), "Guest") == 0) {
			count++;
			cout << "\t\t ===== Customer " << count << " =====\n";
			tmp->getCustomer()->Output();
		}
		tmp = tmp->getNext();
	}
	if (count == 0) cout << "No guest customer in the list" << endl;
}

void customerList::printRegular()
{
	// check if the list is empty
	if (head == NULL) {
		cout << "No customer in the list" << endl;
		return;
	}
	int count = 0; //variable counting the needed customer
	CustomerNode* tmp = head;
	while (tmp != NULL) {
		if (compare_string(tmp->getCustomer()->getRank(), "Regular") == 0) {
			count++;
			cout << "\t\t ===== Customer " << count << " =====\n";
			tmp->getCustomer()->Output();
		}
		tmp = tmp->getNext();
	}
	if (count == 0) cout << "No regular customer in the list" << endl;
}

void customerList::printVIP()
{
	// check if the list is empty
	if (head == NULL) {
		cout << "No customer in the list" << endl;
		return;
	}
	int count = 0; //variable counting the needed customer
	CustomerNode* tmp = head;
	while (tmp != NULL) {
		if (compare_string(tmp->getCustomer()->getRank(), "VIP") == 0) {
			count++;
			cout << "\t\t ===== Customer " << count << " =====\n";
			tmp->getCustomer()->Output();
		}
		tmp = tmp->getNext();
	}
	if (count == 0) cout << "No VIP customer in the list" << endl;
}

bool customerList::isValidCustomer(Customer* customer, itemList iList) {
	// invalid id syntax
	if (!isValidCustomerId(customer->getId())) return false;
	// invalid rank syntax
	if (!isValidRank(customer->getRank())) return false;
	// false data on rental system
	if (customer->getItemRented() != customer->getRentalListLength()) return false;
	//id is not unique
	if (this->findCustomer(customer->getId()) != NULL) return false;
	// wrong phone number
	if (!isValidPhoneNumber(customer->getPhone())) return false;
	// item in rental list is not from the store
	if (!customer->hasViableRentalList(iList)) return false;
	return true;
}