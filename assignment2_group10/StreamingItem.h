#pragma once
#include "Item.h"

class StreamingItem : public Item
{
protected:
	string genre;
public:
	StreamingItem() {};
	StreamingItem(string id, string title, string loanType, int stock, float fee, string genre) {
		this->id = id;
		this->title = title;
		this->loanType = loanType;
		this->stock = stock;
		this->fee = fee;
		this->genre = genre;
	}
	string getGenre() {
		return this->genre;
	}
	void setGenre(string genre) {
		this->genre = genre;
	}
};
