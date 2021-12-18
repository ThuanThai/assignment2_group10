#pragma once
#include "Item.h"
#include "RVItem.h"
#include "ItemNode.h"

class itemList {
private:
	ItemNode* head;
public:
	itemList() {
		head = NULL;
	}
	itemList(Item* newItem) {
		head = new ItemNode(newItem);
	}
	ItemNode* getHead() {
		return this->head;
	}
	void appendItemBack(Item* newItem);
	ItemNode* findItem(string id);
	void deleteItem(string ID);
	void printItemList();
};