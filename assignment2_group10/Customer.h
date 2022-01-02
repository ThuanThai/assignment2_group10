#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Item.h"
#include "itemList.h"
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
	//constructor
	Customer();
	Customer(string id, string name, string address, string phone, string rank = "Guest");
	//copy constructor
	Customer(Customer& C);

	void setId(string id);
	void setName(string name);
	void setAddress(string address);
	void setPhone(string phone);
	void setItemRented(int num);
	void setItemreturned(int num);
	void setRank(string rank);
	virtual void setRewardPoint(int num);

	string getId();
	string getName();
	string getAddress();
	string getPhone();
	int getItemRented();
	int getItemReturned();
	string getRank();
	int getRentalListLength();
	bool hasViableRentalList(itemList stock);
	virtual int getRewardPoint();
	virtual bool borrowing(Item* item);
	virtual bool returning(Item* item);
	friend ostream& operator << (ostream& stream, const Customer* customer);
	friend istream& operator >> (istream& stream, Customer*& customer);
	void Output();
	int readCustomerFile(ifstream&);
	void saveCustomerFile(fstream&);
	void setCustomerType(Customer* customer);
	vector<string> getItemList();
};
