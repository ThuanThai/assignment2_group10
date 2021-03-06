#pragma once
#include "Customer.h"
//constructor
Customer::Customer()
{
	this->id = "";
	this->name = "";
	this->address = "";
	this->phone = "";
	this->itemRented = 0;
	this->itemReturned = 0;
	this->rank = "Guest";
	this->rList = {};
}
//constructor
Customer::Customer(string id, string name, string address, string phone, string rank)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->itemRented = 0;
	this->itemReturned = 0;
	this->rank = rank;
	this->rList = {};
}
//copy constructor
Customer::Customer(Customer& C)
{
	this->id = C.id;
	this->name = C.name;
	this->address = C.address;
	this->phone = C.phone;
	this->itemRented = C.itemRented;
	this->itemReturned = C.itemReturned;
	this->rank = C.rank;
	this->rList = C.rList;
}

void Customer::setId(string id) { this->id = id; }
void Customer::setName(string name) { this->name = name; }
void Customer::setAddress(string address) { this->address = address; }
void Customer::setPhone(string phone) { this->phone = phone; }
void Customer::setItemRented(int num) { this->itemRented = num; }
void Customer::setItemreturned(int num) { this->itemRented = num; }
void Customer::setRank(string rank) { this->rank = rank; }
void Customer::setRewardPoint(int num) { ; }

string Customer::getId() { return this->id; }
string Customer::getName() { return this->name; }
string Customer::getAddress() { return this->address; }
string Customer::getPhone() { return this->phone; }
int Customer::getItemRented() { return this->itemRented; }
int Customer::getItemReturned() { return this->itemReturned; }
vector<string> Customer::getItemRentedList()
{
	return rList;
}
string Customer::getRank() { return this->rank; }
int Customer::getRentalListLength() { return this->rList.size(); }
bool Customer::hasViableRentalList(itemList stock)
{
	for (auto x : this->rList) {
		// an item in customer rental list cannot be found in stock database
		if (stock.findItem(x) == NULL) return false;
	}
	return true;
}
int Customer::getRewardPoint() { return -1; }
bool Customer::borrowing(Item* item) { return false; }
bool Customer::returning(Item* item) { return false; }

ostream& operator << (ostream& stream, const Customer* customer) {
	stream << "ID: " << customer->id << endl;
	stream << "Name: " << customer->name << endl;
	stream << "Address " << customer->address << endl;
	stream << "Phone: " << customer->phone << endl;
	stream << "Rank: " << customer->rank << endl;
	stream << "List of Rentals: " << endl;
	for (auto x : customer->rList)
	{
		stream << x << endl;
	}
	return stream;
}
istream& operator >> (istream& stream, Customer*& customer) {
	cout << "ID: "; getline(stream, customer->id);
	cout << "Name: "; getline(stream, customer->name);
	cout << "Address: "; getline(stream, customer->id);
	cout << "Phone: "; getline(stream, customer->name);
	cout << "List of Rentals: ";
	for (int i = 0; i < customer->itemRented; i++) {
		getline(stream, customer->rList[i]);
	}
	return stream;
}

void Customer::Output() {
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Phone: " << phone << endl;
	cout << "Customer Type: " << rank << endl;
	cout << "List of Rentals: " << endl;
	for (auto x : rList)
	{
		cout << x << endl;
	}
}

int Customer::readCustomerFile(ifstream& fileIn)
{
	string tmp, itemRented;
	int byte;
	getline(fileIn, this->id, ',');
	if (this->id == "") return 1;
	getline(fileIn, this->name, ',');
	if (this->name == "") return 2;
	getline(fileIn, this->address, ',');
	if (this->address == "") return 3;
	getline(fileIn, this->phone, ',');
	if (this->phone == "") return 4;
	getline(fileIn, itemRented, ',');
	if (itemRented == "") return 5;
	try {
		this->itemRented = stoi(itemRented);
	}
	catch (...) {
		return 5;
	}
	getline(fileIn, this->rank);
	while (getline(fileIn, tmp, '\n')) {
		if (tmp == "") continue;
		if (tmp[0] == 'I') {
			this->rList.push_back(tmp);
		}
		else {
			byte = (tmp.length() + 2) * (-1);
			fileIn.seekg(byte, 1);
			break;
		}
	}
	if (rank == "") return 6;
	if (this->rList.size() != this->itemRented) return 7;
	return 0;
}

void Customer::saveCustomerFile(fstream& fileOut) {
	fileOut << id << "," << name << "," << address << ","
		<< phone << "," << itemRented << "," << rank << endl;
	for (auto x : rList) {
		fileOut << x << endl;
	}
}

void Customer::setCustomerType(Customer* customer)
{
	this->id = customer->id;
	this->name = customer->name;
	this->address = customer->address;
	this->phone = customer->phone;
	this->itemRented = customer->itemRented;
	this->rList = customer->rList;
	this->rank = customer->rank;
}

vector<string> Customer::getItemList() {
	return this->rList;
}
