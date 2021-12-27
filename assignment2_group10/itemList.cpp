#pragma once
#include "itemList.h"
#include "StreamingItem.h"
#include "support.h"
#include <iostream>
using namespace std;

void itemList::appendItemBack(Item* newItem) {
	ItemNode* newNode = new ItemNode(newItem);
	ItemNode* current = head;
	if (current == NULL) {
		head = newNode;
		return;
	}
	while (current->getNext() != NULL) {
		current = current->getNext();
	}
	current->setNext(newNode);
}

ItemNode* itemList::findItem(string id) {
	ItemNode* current = head;
	while (current != NULL && current->getItem()->getId() != id) {
		current = current->getNext();
	}
	if (current == NULL) {
		return NULL;
	}
	return current;
}

void itemList::deleteItem(string ID) {
	ItemNode* current = this->head;
	ItemNode* prev = NULL;
	if (current->getItem()->getId() == ID && current->getNext() != NULL) {
		this->head = this->head->getNext();
		delete current;
		return;
	}
	while (current != NULL && current->getItem()->getId() != ID) {
		prev = current;
		current = current->getNext();
	}
	if (current == NULL) {
		cout << "Cannot found valid information!\n";
		return;
	}
	prev->setNext(current->getNext());
	delete current;
	cout << "Delete Successfully!\n";
	system("pause");
}

void itemList::printItemList() {
	ItemNode* current = this->head;
	int i = 1;
	while (current != NULL) {
		cout << "\t\t===== Item " << i << "=====\n";
		if (current->getItem()->getType()._Equal("Game")) {
			cout << current->getItem();
		}
		else {
			cout << (RVItem*)current->getItem();
		}
		current = current->getNext();
		i++;
	}
}
void itemList::addNewItem(string type) {
	Item* newItem = new Item;
	string id, title, loanType, genre;
	int stock = 0;
	float fee = 0.0f;
	// get id
	do {
		cout << "Valid Item Id syntax: Ixxx-yyyy | yyyy < 2022 | ID is unique in list." << endl;
		cout << "ID: "; getline(cin, id);
	} while (!isValidItemId(id) || this->findItem(id) != NULL);

	// get title
	cout << endl;
	cout << "Title: "; getline(cin, title);

	// get loanType
	cout << endl;
	do {
		cout << "Valid loan type: 2-day | 1-week" << endl;
		cout << "Loan Type: "; getline(cin, loanType);
	} while (!loanType._Equal("2-day") && !loanType._Equal("1-week"));

	// get stock size
	cout << endl;
	inputStockSize(&stock);

	// get fee
	cout << endl;
	inputFee(&fee);

	// get genre
	if (type._Equal("DVD") || type._Equal("Record")) {
		cout << endl;
		newItem = new RVItem;
		do {
			cout << "Valid genre: Action | Horror | Drama | Comedy" << endl;
			cout << "Genre: "; cin >> genre;
		} while (!genre._Equal("Action") && !genre._Equal("Horror") && !genre._Equal("Drama") && !genre._Equal("Comedy"));

		newItem->setGenre(genre);
	}
	newItem->setId(id);
	newItem->setTitle(title);
	newItem->setType(type);
	newItem->setLoanType(loanType);
	newItem->setStock(stock);
	newItem->setFee(fee);
	this->appendItemBack(newItem);
}
void itemList::readItemFile(string fileName) {
	fstream fileIn;
	string tmp;
	int len;
	int byte;
	fileIn.open(fileName, ios_base::in);
	if (!fileIn) {
		cerr << "Cannot open file\n";
	}
	while (getline(fileIn, tmp, '\n')) {
		Item* item = new Item;
		Item* newItem = NULL;
		if (search(tmp, "Game")) {
			len = tmp.length();
			byte = (len * (-1)) - 2;
			fileIn.seekg(byte, 1);
			newItem = new Item;
			newItem->readItemFile(fileIn);
			appendItemBack(newItem);
		}
		else if (search(tmp, "DVD") || search(tmp, "Record")) {
			len = tmp.length();
			byte = (len * (-1)) - 2;
			fileIn.seekg(byte, 1);
			newItem = new RVItem;
			newItem->readItemFile(fileIn);
			appendItemBack(newItem);
		}
	}
	fileIn.close();
}