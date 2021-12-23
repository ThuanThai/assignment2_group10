#pragma once
#include "Customer.h"
//constructor
Customer::Customer()
{
	this->id = -1;
	this->name = "";
	this->address = "";
	this->phone = "";
	this->itemRented = -1;
	this->itemReturned = -1;
	this->rank = "";
	this->rList = {};
}
//constructor
Customer::Customer(string id, string name, string address, string phone, int itemRented, int itemReturned, string rank)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->itemRented = itemRented;
	this->itemReturned = itemReturned;
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
string Customer::getRank() { return this->rank; }
int Customer::getRewardPoint() { return -1; }

ostream& operator << (ostream& stream, const Customer* customer) {
	stream << "ID: " << customer->id << endl;
	stream << "Name: " << customer->name << endl;
	stream << "Address " << customer->address << endl;
	stream << "Phone: " << customer->phone << endl;
	stream << "Rank: " << customer->rank << endl;
	stream << "Lis of Rentals: " << endl;
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
	cout << "Address " << address << endl;
	cout << "Phone: " << phone << endl;
	cout << "Rank: " << rank << endl;
	cout << "List of Rentals: " << endl;
	for (auto x : rList)
	{
		cout << x << endl;
	}
}

void Customer::readCustomerFile(ifstream& fileIn)
{
	string tmp;
	getline(fileIn, this->id, ',');
	getline(fileIn, this->name, ',');
	getline(fileIn, this->address, ',');
	getline(fileIn, this->phone, ',');
	fileIn >> itemRented;
	fileIn.ignore();
	getline(fileIn, this->rank);
	while (getline(fileIn, tmp, '\n')) {
		if (tmp[0] == 'I') {
			this->rList.push_back(tmp);
		}
		else {
			int byte = (tmp.length() + 2) * (-1);
			fileIn.seekg(byte, 1);
			break;
		}
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