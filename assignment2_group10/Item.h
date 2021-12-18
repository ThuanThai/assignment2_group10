#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Item {
protected:
	string id;
	string title;
	string type;
	string loanType;
	int stock;
	float fee;
public:
	//constructor
	Item() {
		this->id = "";
		this->title = "";
		this->type = "";
		this->loanType = "";
		this->stock = 0;
		this->fee = 0.0f;
	}
	Item(string id, string title, string type, string loanType, int stock, float fee) {
		this->id = id;
		this->title = title;
		this->loanType = loanType;
		this->stock = stock;
		this->fee = fee;
	}
	~Item();

	virtual void Output();
	virtual void Input(string type);
	virtual void readItemFile(fstream&);
	virtual void setGenre(string genre) { ; } // Not do anything if item is not belong to RVItem;
	virtual void updateType(Item* item, string newType);
	
	friend ostream& operator << (ostream& stream, const Item* item);
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
	void setType(string type) {
		this->type = type;
	}
};
