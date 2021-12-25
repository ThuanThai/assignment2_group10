#pragma once
#include "RVItem.h"

void RVItem::Output() {
	Item::Output();
	cout << "7.Genre: " << this->genre << endl;
}

void RVItem::readItemFile(fstream& fileIn) {
	Item::readItemFile(fileIn);
	getline(fileIn, genre);
}

ostream& operator << (ostream& stream, const RVItem* item) {
	stream << "Id: " << item->id << endl;
	stream << "Title: " << item->title << endl;
	stream << "Type: " << item->type << endl;
	stream << "Loan type: " << item->loanType << endl;
	stream << "Num of copies: " << item->stock << endl;
	stream << "Fee: " << item->fee << endl;
	stream << "Genre: " << item->genre << endl;
	return stream;
}

void RVItem::updateType(Item* item, string newType) {
	this->id = item->getId();
	this->title = item->getTitle();
	this->type = newType;
	this->loanType = item->getLoanType();
	this->stock = item->getStock();
	this->fee = item->getFee();
	cout << "update Genre: ";
	getline(cin, genre);
}