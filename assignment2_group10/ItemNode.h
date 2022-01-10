#pragma once
#include "Item.h"
class ItemNode {
private:
	Item* item;
	ItemNode* next;
public:
	//constructor
	ItemNode() {
		this->item = NULL;
		this->next = NULL;
	}
	ItemNode(Item* newItem) {
		this->item = newItem;
		next = NULL;
	}

	//destructor
	~ItemNode() {
		this->item = NULL;
		this->next = NULL;
	};

	//getter
	ItemNode* getNext() {
		return this->next;
	}
	Item* getItem() {
		return this->item;
	}

	//setter
	void setNext(ItemNode* nextNode) {
		this->next = nextNode;
	}
	void setItem(Item* newItem) {
		this->item = newItem;
	}
};