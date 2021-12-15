#pragma once
#include "itemList.h"
#include "StreamingItem.h"
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
//void itemList::appendItemBack(StreamingItem newItem) {
//	Item* newNode = new StreamingItem(newItem);
//	Item* current = this->head;
//	if (current == NULL) {
//		head = newNode;
//		return;
//	}
//	while (current->getNext() != NULL) {
//		current = current->getNext();
//	}
//	current->setNext(newNode);
//}


//void itemList::deleteItem(string ID) {
//	Item* current = this->head;
//	Item* prev = NULL;
//	if (current->getId() == ID && current->getNext() != NULL) {
//		this->head = this->head->getNext();
//		delete current;
//		return;
//	}
//	while (current != NULL && current->getId() != ID) {
//		prev = current;
//		current = current->getNext();
//	}
//	if (current == NULL) {
//		cout << "Cannot found valid information!\n";
//		return;
//	}
//	prev->setNext(current->getNext());
//	delete current;
//	cout << "Delete Successfully!\n";
//	system("pause");
//}
//
void itemList::printItemList() {
	ItemNode* current = this->head;
	int i = 1;
	while (current != NULL) {
		cout << "\t\t===== Item " << i << "=====\n";
		current->getItem()->Output();
		current = current->getNext();
		i++;
	}
}