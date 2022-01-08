#include "Item.h"
#include "support.h"

//constructor
Item::Item() {
	this->id = "";
	this->title = "";
	this->type = "";
	this->loanType = "";
	this->stock = 0;
	this->fee = 0.0f;
}
Item::Item(string id, string title, string type, string loanType, int stock, float fee) {
	this->id = id;
	this->title = title;
	this->type = type;
	this->loanType = loanType;
	this->stock = stock;
	this->fee = fee;
}

// print an item info
void Item::Output() {
	cout << "1.ID: " << id << endl;
	cout << "2.Title: " << title << endl;
	cout << "3.Type: " << type << endl;
	cout << "4.Loan Type: " << loanType << endl;
	cout << "5.Num of copies: " << stock << endl;
	cout << "6.Fee: " << fee << endl;
}

// read file items.txt
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

// save information to file
void Item::saveItemFile(fstream& fileOut) {
	fileOut << id << "," << title << "," << type << ","
		<< loanType << "," << stock << "," << fee << endl;
}

//overload ostream
ostream& operator << (ostream& stream, const Item* item) {
	stream << "Id: " << item->id << endl;
	stream << "Title: " << item->title << endl;
	stream << "Type: " << item->type << endl;
	stream << "Loan type: " << item->loanType << endl;
	stream << "Num of copies: " << item->stock << endl;
	stream << "Fee: " << item->fee << endl;
	return stream;
}

// update type of item
void Item::updateType(Item* item, string newType) {
	this->id = item->getId();
	this->title = item->getTitle();
	this->type = newType;
	this->loanType = item->getLoanType();
	this->stock = item->getStock();
	this->fee = item->getFee();
}

// borrow function
bool Item::borrowing() {
	if(stock == 0)
		return false;
	else
	{
		stock--;
		return true;
	}
}

// return function
bool Item::returning() {
	stock++;
	return true;
}

//getter
string Item::getId() {
	return this->id;
}
string Item::getTitle() {
	return this->title;
}
string Item::getType() {
	return this->type;
}
string Item::getLoanType() {
	return this->loanType;
}
int Item::getStock() {
	return this->stock;
}
float Item::getFee() {
	return this->fee;
}

// setter
void Item::setId(string id) {
	this->id = id;
}
void Item::setTitle(string title) {
	this->title = title;
}
void Item::setLoanType(string loanType) {
	this->loanType = loanType;
}
void Item::setStock(int stock) {
	this->stock = stock;
}
void Item::setFee(float fee) {
	this->fee = fee;
}
void Item::setType(string type) {
	this->type = type;
}
