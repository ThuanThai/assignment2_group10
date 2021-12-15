#include "Item.h"
Item::~Item() {}

void Item::Output() {
	cout << "ID: " << id << endl;
	cout << "Title: " << title << endl;
	cout << "Type: " << type << endl;
	cout << "Loan Type: " << loanType << endl;
	cout << "Num of copies: " << stock << endl;
	cout << "Fee: " << fee << endl;
}

void Item::readItemFile(fstream& fileIn) {
	getline(fileIn, id, ',');
	getline(fileIn, title, ',');
	getline(fileIn, type, ',');
	getline(fileIn, loanType, ',');
	fileIn >> stock;
	fileIn.ignore();
	fileIn >> fee;
	fileIn.ignore();
}