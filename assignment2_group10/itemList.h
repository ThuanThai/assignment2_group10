#pragma once
#include "node.h"

class itemList {
private:
	node* head;
public:
	itemList() {
		head = NULL;
	}
	itemList(Item newItem) {
		head = new node(newItem);
	}
	node* getHead() {
		return this->head;
	}
	void appendItemBack(Item newItem);
	void deleteItem(string ID);
	void printItemList();
};