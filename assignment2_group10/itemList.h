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
	void readItemFile(string fileName);
	void saveItemFile(string fileName);
	ItemNode* findItem(string searchEl);
	void updateItem(string searchEl);
	void deleteItem(string searchEl);
	void printItemList();
	void displayOutOfStock();
	void addNewItem(string type);
	bool isValidItem(Item item);
	bool isValidItem(RVItem item);
	//sort funtions 
	void sort_by_id();
	void sort_by_title();
	//function print items by searching for Id or title
	void search_for(string keyword);
};
