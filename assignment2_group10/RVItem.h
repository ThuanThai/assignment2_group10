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
	string getGenre() { return genre; }
	void setGenre(string genre) { this->genre = genre; }
};
