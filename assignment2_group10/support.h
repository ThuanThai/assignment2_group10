#pragma once
#include"node.h"
#include "itemList.h"
#include <fstream>
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
	string temp;
	bool flag = true;

	while (current != NULL && current->getItem().id != id) {
		current = current->getNext();
	}
	if (current == NULL) {
		cout << "Cannot found!\n";
		return;
	}

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
			cin >> temp;
			current->getItem().id = temp;
			break;
		}
		case 2:{
			cin >> temp;
			current->getItem().title = temp;
			break;
		}
		case 3: {
			cin >> temp;
			current->getItem().type = temp;
			break;
		}
		case 4: {
			cin >> temp;
			current->getItem().loanType = temp;
			break;
		}
		/*case 5: {
			int newCopy;
			cin >> newCopy;
			current->getItem().numOfcopies = newCopy;
			break;
		}
		case 6: {
			float newFee;
			cin >> newFee;
			current->getItem().fee = newFee;
			break;
		}*/
		case 7: {
			cin >> temp;
			current->getItem().genre = temp;
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

void menu(itemList& itemList) {
	bool flag = true;
	string choice;
	string id;
	while (flag) {
		system("cls");
		cout << "1. Add a new item, update or delete an existing item\n";
		cout << "2. Print Item list\n";
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
		else if (choice == "2") {
			itemList.printItemList();
			system("pause");
		}
		else if (choice == "exit" || choice == "Exit") {
			flag = false;
			break;
		}
	}
}