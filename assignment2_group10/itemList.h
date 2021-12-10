#pragma once
#include "Item.h"

class itemList {
private:
	Item* head;
public:
	itemList() {
		head = NULL;
	}
	itemList(Item newItem) {
		head = new Item(newItem);
	}
	Item* getHead() {
		return this->head;
	}
	void appendItemBack(Item newItem);
	void deleteItem(string ID);
	void printItemList();
};