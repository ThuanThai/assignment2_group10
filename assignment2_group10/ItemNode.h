#pragma once
#include "Item.h"
class ItemNode {
private:
	Item* item;
	ItemNode* next;
public:
	ItemNode() {
		this->item = NULL;
		this->next = NULL;
	}
	ItemNode(Item* newItem) {
		this->item = newItem;
		next = NULL;
	}

	ItemNode* getNext() {
		return this->next;
	}
	Item* getItem() {
		return this->item;
	}

	void setNext(ItemNode* nextNode) {
		this->next = nextNode;
	}
	void setItem(Item* newItem) {
		this->item = newItem;
	}
};