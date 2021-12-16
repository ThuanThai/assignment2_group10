#include "RVItem.h"

void RVItem::Output() {
	Item::Output();
	cout << "Genre: " << this->genre << endl;
}

void RVItem::readItemFile(fstream& fileIn) {
	Item::readItemFile(fileIn);
	getline(fileIn, genre);
}

void RVItem::Input(string type) {
	Item::Input(type);
	cout << "Genre: "; cin >> genre;
}

ostream& operator << (ostream& stream, const RVItem* item) {
	stream << "1.Id: " << item->id << endl;
	stream << "2.Title: " << item->title << endl;
	stream << "3.Type: " << item->type << endl;
	stream << "4.Loan type: " << item->loanType << endl;
	stream << "5.Num of copies: " << item->stock << endl;
	stream << "6.Fee: " << item->fee << endl;
	stream << "7.Genre: " << item->genre << endl;
	return stream;
}

void RVItem::updateType(Item* item, string newType) {
	this->id = item->getId();
	this->title = item->getTitle();
	this->type = newType;
	this->loanType = item->getLoanType();
	this->stock = item->getStock();
	this->fee = item->getFee();
	cout << "update Genre: \n";
	getline(cin, genre);
}