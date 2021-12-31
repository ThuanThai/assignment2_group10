#include "Item.h"
#include "support.h"

Item::~Item() {;}

void Item::Output() {
	cout << "1.ID: " << id << endl;
	cout << "2.Title: " << title << endl;
	cout << "3.Type: " << type << endl;
	cout << "4.Loan Type: " << loanType << endl;
	cout << "5.Num of copies: " << stock << endl;
	cout << "6.Fee: " << fee << endl;
}

int Item::readItemFile(fstream& fileIn) {
	string id, title, type, loanType, stock, fee;
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
	getline(fileIn, fee);
	if (fee == "") {
		return 6;
	}
	this->id = id;
	this->title = title;
	this->type = type;
	this->loanType = loanType;
	try {
		this->stock = stoi(stock);
	}
	catch (...) {
		return 5;
	}
	try {
		this->fee = atof(fee.c_str());
	}
	catch (...) {
		return 6;
	}
	
	return 0;
}

void Item::saveItemFile(fstream& fileOut) {
	fileOut << id << "," << title << "," << type << ","
		<< loanType << "," << stock << "," << fee << endl;
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

bool Item::borrowing() {
	if(stock == 0)
		return false;
	else
	{
		stock--;
		return true;
	}
}

bool Item::returning() {
	stock++;
	return true;
}

