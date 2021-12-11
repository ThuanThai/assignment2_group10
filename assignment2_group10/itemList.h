#pragma once
#include "Item.h"
#include "StreamingItem.h"

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
	void appendItemBack(StreamingItem newItem);
	void deleteItem(string ID);
	void printItemList();
};