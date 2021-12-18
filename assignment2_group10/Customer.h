#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Customer
{
protected:
	string id;
	string name;
	string address;
	string phone;
	int itemRented;
	int itemReturned;
	vector<string> rList;
	string rank;
public:
	Customer();
	~Customer();
	void setId(string id);
	void setName(string name);
	void setAddress(string address);
	void setPhone(string phone);
	void setItemRented(int num);
	void setItemreturned(int num);
	void setRank(string rank);

	string getId();
	string getName();
	string getAddress();
	string getPhone();
	int getItemRented();
	int getItemReturned();
	string getRank();

	friend ostream& operator << (ostream& stream, const Customer* customer);
	friend istream& operator >> (istream& stream, Customer*& customer);
	void Output();
};

