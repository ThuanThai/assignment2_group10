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
	Item();
	Item(string id, string title, string type, string loanType, int stock, float fee);
	//destructor
	~Item() {};

	// print an item info
	virtual void Output();
	// read file items.txt
	virtual int readItemFile(fstream&);
	// save information to file
	virtual void saveItemFile(fstream&);

	// set/get Genre
	virtual void setGenre(string genre) { ; } // Not do anything if item is not belong to RVItem;
	virtual string getGenre() { return ""; }
	
	// update type of item
	virtual void updateType(Item* item, string newType);

	// borrow function
	bool borrowing();
	// return function
	bool returning();

	//overload ostream
	friend ostream& operator << (ostream& stream, const Item* item);

	//getter
	string getId();
	string getTitle();
	string getType();
	string getLoanType();
	int getStock();
	float getFee();

	//setter
	void setId(string id);
	void setTitle(string title);
	void setLoanType(string loanType);
	void setStock(int stock);
	void setFee(float fee);
	void setType(string type);
};
