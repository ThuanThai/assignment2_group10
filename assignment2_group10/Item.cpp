#include "Item.h"
#include "support.h"
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
	do {
		cout << "Valid Item Id syntax: Ixxx-yyyy" << endl;
		cout << "ID: "; cin >> id;
	} while (!isValidItemId(id));
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

ostream& operator << (ostream& stream, const Item* item) {
	stream << "1.Id: " << item->id << endl;
	stream << "2.Title: " << item->title << endl;
	stream << "3.Type: " << item->type << endl;
	stream << "4.Loan type: " << item->loanType << endl;
	stream << "5.Num of copies: " << item->stock << endl;
	stream << "6.Fee: " << item->fee << endl;
	return stream;
}

void Item::updateType(Item* item, string newType) {
	this->id = item->getId();
	this->title = item->getTitle();
	this->type = newType;
	this->loanType = item->getLoanType();
	this->stock = item->getStock();
	this->fee = item->getFee();
}

