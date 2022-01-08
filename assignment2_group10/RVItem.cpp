#pragma once
#include "RVItem.h"

// Constructor 
RVItem::RVItem() : Item() {
	this->genre = "";
}
RVItem::RVItem(string id, string title, string type, string loanType, int stock, float fee, string genre) : Item(id, title, type, loanType, stock, fee) {
	this->genre = genre;
}

// print RV Item info
void RVItem::Output() {
	Item::Output();
	cout << "7.Genre: " << this->genre << endl;
}

// read item file
int RVItem::readItemFile(fstream& fileIn) {
	string id, title, type, loanType, stock, fee, genre;
	getline(fileIn, id, ',');
	if (id == "") {
		return 1;
	}
	getline(fileIn, title, ',');
	if (title == "") {
		return 2;
	}
	getline(fileIn, type, ',');
	if (type == "") {
		return 3;
	}
	getline(fileIn, loanType, ',');
	if (loanType == "") {
		return 4;
	}
	getline(fileIn, stock, ',');
	if (stock == "") {
		return 5;
	}
	getline(fileIn, fee, ',');
	if (fee == "") {
		return 6;
	}
	getline(fileIn, genre);
	if (fee == "") {
		return 7;
	}
	this->id = id;
	this->title = title;
	this->type = type;
	this->loanType = loanType;
	this->stock = stoi(stock);
	this->fee = (double)atof(fee.c_str());
	this->genre = genre;
	return 0;
}

// save item file
void RVItem::saveItemFile(fstream& fileOut) {
	fileOut << id << "," << title << "," << type << ","
		<< loanType << "," << stock << "," << fee << "," << genre << endl;
}

//overload ostream
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

// update type of customer
void RVItem::updateType(Item* item, string newType) {
	this->id = item->getId();
	this->title = item->getTitle();
	this->type = newType;
	this->loanType = item->getLoanType();
	this->stock = item->getStock();
	this->fee = item->getFee();
	cout << "update Genre: ";
	getline(cin, genre);
	while (!genre._Equal("Action") && !genre._Equal("Horror") && !genre._Equal("Drama") && !genre._Equal("Comedy")) {
		cout << "Only enter valid genre: Action || Horror || Drama || Comedy" << endl;
		cout << "Enter updated genre: ";
		getline(cin, genre);
		cout << endl;
	}
}

//getter
string RVItem::getGenre() { return genre; }

//setter
void RVItem::setGenre(string genre) { this->genre = genre; }