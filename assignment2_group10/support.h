#pragma once
#include "node.h"
#include "itemList.h"
#include "customerNode.h"
#include "customerList.h"
#include <fstream>
#include <sstream>
using namespace std;

void readItemFile(ifstream& fileIn, Item& newItem) {
	getline(fileIn, newItem.id, ',');
	getline(fileIn, newItem.title, ',');
	getline(fileIn, newItem.type, ',');
	getline(fileIn, newItem.loanType, ',');
	fileIn >> newItem.numOfcopies;
	fileIn.ignore();
	fileIn >> newItem.fee;
	fileIn.ignore();
	if (newItem.type._Equal("Record") || newItem.type._Equal("DVD")) {
		getline(fileIn, newItem.genre, '\n');
	}
}

void readCustomerFile(ifstream& fileIn, Customer& newCustomer) {
	string tmp;
	getline(fileIn, newCustomer.id, ',');
	getline(fileIn, newCustomer.name, ',');
	getline(fileIn, newCustomer.address, ',');
	getline(fileIn, newCustomer.phone, ',');
	fileIn >> newCustomer.numOfRentals;
	fileIn.ignore();
	getline(fileIn, newCustomer.customerType);
	while (getline(fileIn, tmp, '\n')) {
		if (tmp[0] == 'I') {
			stringstream ss(tmp);
			ss >> newCustomer.listItemId.list[newCustomer.listItemId.count];
			newCustomer.listItemId.count++;
		}
		else {
			int byte = (tmp.length() + 2) * (-1);
			fileIn.seekg(byte, 1);
			break;
		}
	}
}

void listReadItemfile(itemList& itemList) {
	ifstream fileIn;
	fileIn.open("item.txt", ios_base::in);
	if (!fileIn) {
		cerr << "Cannot open file\n";
	}
	while (!fileIn.eof()) {
		Item newItem;
		readItemFile(fileIn, newItem);
		itemList.appendItemBack(newItem);
	}
	fileIn.close();
}

void listReadCustomerFile(customerList& customerList) {
	ifstream fileIn;
	fileIn.open("customers.txt", ios_base::in);
	if (!fileIn) {
		cerr << "Cannot open file\n";
	}
	while (!fileIn.eof()) {
		Customer newCustomer;
		readCustomerFile(fileIn, newCustomer);
		customerList.appendCustomerBack(newCustomer);
	}
	fileIn.close();
}

void addItem(itemList& itemList) {
	Item newItem;
	cout << "\t\t===== Input Item's Information =====\n";
	cout << "ID: ";
	cin >> newItem.id;
	cout << "Title: ";
	cin >> newItem.title;
	cout << "Type: ";
	string tmp;
	getline(cin, tmp);
	cin >> newItem.type;
	cout << "Loan Type: ";
	cin >> newItem.loanType;
	cout << "Num of copies: ";
	cin >> newItem.numOfcopies;
	cout << "Fee: ";
	cin >> newItem.fee;
	if (newItem.type._Equal("Record") || newItem.type._Equal("DVD")) {
		cout << "Gerne: ";
		cin >> newItem.genre;
	}
	itemList.appendItemBack(newItem);
}

void uppdateItem(string id, itemList& itemList) {
	node* current = itemList.getHead();
	int choice;
	bool flag = true;
	while (current != NULL && current->getItem().id != id) {
		current = current->getNext();
	}
	if (current == NULL) {
		cout << "Cannot found!\n";
		return;
	}
	Item newItem = current->getItem();
	while (flag) {
		system("cls");
		cout << "1.ID: " << current->getItem().id << endl;
		cout << "2.Title: " << current->getItem().title << endl;
		cout << "3.Type: " << current->getItem().type << endl;
		cout << "4.Loan Type: " << current->getItem().loanType << endl;
		cout << "5.Num of copies: " << current->getItem().numOfcopies << endl;
		cout << "6.Fee: " << current->getItem().fee << endl;
		if (current->getItem().genre != "") {
			cout << "7. Genre: " << current->getItem().genre << endl;
		}
		cout << "0. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice) {
		case 1:{
			cin >> newItem.id;
			current->setItem(newItem);
			break;
		}
		case 2:{
			cin >> newItem.title;
			current->setItem(newItem);
			break;
		}
		case 3: {
			cin >> newItem.type;
			current->setItem(newItem);
			break;
		}
		case 4: {
			cin >> newItem.loanType;
			current->setItem(newItem);
			break;
		}
		case 5: {
			cin >> newItem.numOfcopies;
			current->setItem(newItem);
			break;
		}
		case 6: {
			cin >> newItem.fee;
			current->setItem(newItem);
			break;
		}
		case 7: {
			cin >> newItem.genre;
			current->setItem(newItem);
			break;
		}
		case 0:
			flag = false;
			break;
		default:
			cout << "Wrong chocie";
			continue;
		}
	}
}

void menu(itemList& itemList, customerList& customerList) {
	bool flag = true;
	string choice;
	string id;
	while (flag) {
		system("cls");
		cout << "1. Add a new item, update or delete an existing item\n";
		cout << "2. Print Item list\n";
		cout << "3. Add new customer or update an existing customer\n";
		cout << "4. Print Customer List\n";
		cin >> choice;
		if (choice == "1") {
			system("cls");
			cout << "1. Add a new item\n";
			cout << "2. Update a new item\n";
			cout << "3. Delete\n";
			cin >> choice;
			if (choice == "1") {
				addItem(itemList);
			}
			else if (choice == "2") {
				cout << "Enter ID: ";
				cin >> id;
				uppdateItem(id, itemList);
			}
			else if (choice == "3") {
				itemList.printItemList();
				cout << "\t\t ===== Delete =====\n";
				cout << "Enter ID: ";
				cin >> id;
				itemList.deleteItem(id);
			}
		}
		else if (choice == "3") {
			itemList.printItemList();
			system("pause");
		}
		else if (choice == "3") {
			system("cls");
			cout << "1. Add a new item\n";
			cout << "2. Update a new item\n";
			cout << "3. Delete\n";
			cin >> choice;
			if (choice == "1") {
				addItem(itemList);
			}
			else if (choice == "2") {
				cout << "Enter ID: ";
				cin >> id;
				uppdateItem(id, itemList);
			}
			else if (choice == "3") {
				itemList.printItemList();
				cout << "\t\t ===== Delete =====\n";
				cout << "Enter ID: ";
				cin >> id;
				itemList.deleteItem(id);
			}
		}
		else if (choice == "4") {
			customerList.printCustomerList();
			system("pause");
		}
		else if (choice == "exit" || choice == "Exit") {
			flag = false;
			break;
		}
	}
}