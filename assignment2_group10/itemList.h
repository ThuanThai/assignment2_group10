#pragma once
#include "Item.h"
#include "RVItem.h"
#include "ItemNode.h"

class itemList {
private:
	ItemNode* head;
public:
	//constructor
	itemList();
	itemList(Item* newItem);

	//destructor
	~itemList() { ; }

	//getter
	ItemNode* getHead();

	// add item to list
	void appendItemBack(Item* newItem);

	//read item file
	void readItemFile(string fileName);
	//save item file
	void saveItemFile(string fileName);

	// search itemNode
	ItemNode* findItem(string searchEl);

	// update item
	void updateItem(string searchEl);

	// delete item
	void deleteItem(string searchEl);

	// print item list
	void printItemList();
	
	// print out of stock item
	void displayOutOfStock();

	// add new item 
	void addNewItem(string type);

	bool isValidItem(Item item);
	bool isValidItem(RVItem item);
	//sort funtions 
	void sort_by_id();
	void sort_by_title();
	//function print items by searching for Id or title
	void search_for(string keyword);
};
