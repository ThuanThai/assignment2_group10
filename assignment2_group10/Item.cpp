#include "Item.h"
#include "support.h"
Item::~Item() {}

void Item::Output() {
	cout << "1.ID: " << id << endl;
	cout << "2.Title: " << title << endl;
	cout << "3.Type: " << type << endl;
	cout << "4.Loan Type: " << loanType << endl;
	cout << "5.Num of copies: " << stock << endl;
	cout << "6.Fee: " << fee << endl;
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
	stream << "Id: " << item->id << endl;
	stream << "Title: " << item->title << endl;
	stream << "Type: " << item->type << endl;
	stream << "Loan type: " << item->loanType << endl;
	stream << "Num of copies: " << item->stock << endl;
	stream << "Fee: " << item->fee << endl;
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

