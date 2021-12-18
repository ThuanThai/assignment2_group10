#include "Customer.h"

Customer::Customer() {
	this->id = "";
	this->name = "";
	this->address = "";
	this->phone = "";
	this->itemRented = 0;
	this->itemReturned = 0;
	this->rank = "";
}

Customer::~Customer() { ; }

void Customer::setId(string id) { this->id = id; }
void Customer::setName(string name) { this->name = name; }
void Customer::setAddress(string address) { this->address = address; }
void Customer::setPhone(string phone) { this->phone = phone; }
void Customer::setItemRented(int num) { this->itemRented = num; }
void Customer::setItemreturned(int num) { this->itemRented = num; }
void Customer::setRank(string rank) { this->rank = rank; }

string Customer::getId() { return this->id; }
string Customer::getName() { return this->name; }
string Customer::getAddress() { return this->address; }
string Customer::getPhone() { return this->phone; }
int Customer::getItemRented() { return this->itemRented; }
int Customer::getItemReturned() { return this->itemReturned; }
string Customer::getRank() { return this->rank; }

ostream& operator << (ostream& stream, const Customer* customer) {
	stream << "ID: " << customer->id << endl;
	stream << "Name: " << customer->name << endl;
	stream << "Address " << customer->address << endl;
	stream << "Phone: " << customer->phone << endl;
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
	cout << "Lis of Rentals: " << endl;
	for (auto x : rList)
	{
		cout << x << endl;
	}
}

