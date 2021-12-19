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
		cout << "Cannot find valid information!\n";
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
	int stock;
	float fee;
	do {
		cout << "Valid Item Id syntax: Ixxx-yyyy | yyyy < 2022 | ID is unique in list." << endl;
		cout << "ID: "; cin >> id;
	} while (!isValidItemId(id) || this->findItem(id) != NULL);
	cout << "Title: "; cin >> title;
	cout << "Loan Type: "; cin >> loanType;
	cout << "Num of copies: "; cin >> stock;
	cout << "Fee: "; cin >> fee;
	if (type._Equal("DVD") || type._Equal("Record")) {
		newItem = new RVItem;
		cout << "Genre: "; cin >> genre;
		newItem->setGenre(genre);
	}
	newItem->setId(id);
	newItem->setTitle(title);
	newItem->setType(type);
	newItem->setLoanType(loanType);
	newItem->setStock(stock);
	newItem->setFee(fee);
	this->appendItemBack(newItem);
};