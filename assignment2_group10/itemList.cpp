#pragma once
#include "itemList.h"
#include <iostream>
using namespace std;

void itemList::appendItemBack(Item newItem) {
	node* newNode = new node(newItem);
	node* current = this->head;
	if (current == NULL) {
		head = newNode;
		return;
	}
	while (current->getNext() != NULL) {
		current = current->getNext();
	}
	current->setNext(newNode);
}

void itemList::deleteItem(string ID) {
	node* current = this->head;
	node* prev = NULL;
	if (current->getItem().id == ID && current->getNext() != NULL) {
		this->head = this->head->getNext();
		delete current;
		return;
	}
	while (current != NULL && current->getItem().id != ID) {
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
	node* current = this->head;
	int i = 1;
	while (current != NULL) {
		cout << "\t\t===== Item " << i << "=====\n";
		cout << "ID: " << current->getItem().id << endl;
		cout << "Title: " << current->getItem().title << endl;
		cout << "Type: " << current->getItem().type << endl;
		cout << "Loan Type: " << current->getItem().loanType << endl;
		cout << "Num of copies: " << current->getItem().numOfcopies << endl;
		cout << "Fee: " << current->getItem().fee << endl;
		if(current->getItem().genre != "") {
			cout << "Genre: " << current->getItem().genre << endl;
		}
		current = current->getNext();
		i++;
	}
}