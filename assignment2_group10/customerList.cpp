#include "customerList.h"
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