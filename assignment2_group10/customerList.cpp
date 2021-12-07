#include "customerList.h"
void customerList::appendCustomerBack(Customer newCustomer) {
	customerNode* newCustomerNode = new customerNode(newCustomer);
	customerNode* current = this->head;
	if (current == NULL) {
		this->head = newCustomerNode;
		return;
	}
	while (current->getNext() != NULL) {
		current = current->getNext();
	}
	current->setNext(newCustomerNode);
}

void customerList::printCustomerList() {
	customerNode* current = this->head;
	int i = 1;
	while (current != NULL) {
		cout << "\t\t ===== Customer " << i << " =====\n";
		cout << "ID: " << current->getCustomer().id << endl;
		cout << "Name: " << current->getCustomer().name << endl;
		cout << "Address: " << current->getCustomer().address << endl;
		cout << "Phone: " << current->getCustomer().phone << endl;
		cout << "Number of rentals: " << current->getCustomer().numOfRentals << endl;
		cout << "Type: " << current->getCustomer().customerType << endl;
		cout << "List of items' IDs\n";
		for (int j = 0; j < current->getCustomer().listItemId.count; j++) {
			cout << current->getCustomer().listItemId.list[j] << endl;
		}
		current = current->getNext();
		i++;
	}
}