#pragma once
#include "Item.h"


class RVItem : public Item {
private:
	string genre;
public:
	RVItem() : Item() {
		this->genre = "";
	}
	RVItem(string genre) : Item(id, title, type, loanType, stock, fee) {
		this->genre = genre;
	}
	~RVItem() { ; }

	void Output();
	void Input(string type);
	void readItemFile(fstream&);
	void updateType(Item* item, string newType);
	friend ostream& operator << (ostream& stream, const RVItem* item);

	//getter
	string getGenre() { return genre; }
	
	//setter
	void setGenre(string genre) { this->genre = genre; }
	
};
