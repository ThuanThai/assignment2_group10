#pragma once
#include <iostream>
using namespace std;

class Item {
protected:
	string id;
	string title;
	string type;
	string loanType;
	int stock;
	float fee;
	string genre;
	Item* next;
public:
	//constructor
	Item() {
		this->id = "";
		this->title = "";
		this->loanType = "";
		this->stock = NULL;
		this->fee = NULL;
		this->next = NULL;
	}
	Item(string id, string title, string type, string loanType, int stock, float fee, Item* next) {
		this->id = id;
		this->title = title;
		this->loanType = loanType;
		this->stock = stock;
		this->fee = fee;
		this->type = type;
	}
	//getter
	string getId() {
		return this->id;
	}
	string getTitle() {
		return this->title;
	}
	string getType() {
		return this->type;
	}
	string getLoanType() {
		return this->loanType;
	}
	int getStock() {
		return this->stock;
	}
	float getFee() {
		return this->fee;
	}
	Item* getNext() {
		return this->next;
	}

	//setter
	void setId(string id) {
		this->id = id;
	}
	void setTitle(string title) {
		this->title = title;
	}
	void setLoanType(string loanType) {
		this->loanType = loanType;
	}
	void setStock(int stock) {
		this->stock = stock;
	}
	void setFee(float fee) {
		this->fee = fee;
	}
	void setNext(Item* nextItem) {
		this->next = nextItem;
	}
	void setType(string type) {
		this->type = type;
	}
	
};