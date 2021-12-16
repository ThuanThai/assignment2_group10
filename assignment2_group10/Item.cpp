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

void Item::Input(string type) {
	cout << "ID: "; cin >> id;
	cout << "Title: "; cin >> title;
	cout << "Loan Type: "; cin >> loanType;
	cout << "Num of copies: "; cin >> stock;
	cout << "Fee: "; cin >> fee;
	this->type = type;
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

