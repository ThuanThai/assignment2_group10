#pragma once
#include <iostream>
#include <string>
using namespace std;
typedef struct Item {
	string id;
	string title;
	string type;
	string loanType;
	int numOfcopies;
	float fee;
	string genre;
};

class node {
private:
	Item item;
	node* next;
public:
	//constructor
	node(Item newItem) {
		this->item = newItem;
		this->next = NULL;
	}
	//getter
	node* getNext() {
		return this->next;
	}
	Item getItem() {
		return this->item;
	}
	//setter
	void setNext(node* nextNode) {
		this->next = nextNode;
	}
	void setItem(Item newItem) {
		this->item = newItem;
	}
};