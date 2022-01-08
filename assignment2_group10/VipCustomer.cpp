#pragma once
#include "VipCustomer.h"

// constructor
VipCustomer::VipCustomer()
{
	this->id = "";
	this->name = "";
	this->address = "";
	this->phone = "";
	this->itemRented = 0;
	this->itemReturned = 0;
	this->rank = "Vip";
	this->rewardPoint = 0;
}

VipCustomer::VipCustomer(string id, string name, string address, string phone, string rank) :Customer(id, name, address, phone, rank) {
	rewardPoint = 0 ;
}

//destructor
VipCustomer::~VipCustomer() { ; }

//setter
void VipCustomer::setRewardPoint(unsigned int num) { this->rewardPoint = num; }
// getter
int VipCustomer::getRewardPoint() { return this->rewardPoint; }

// borrow function
bool VipCustomer::borrowing(Item* item) {
	string choice;
	if (item->borrowing()) {
		cout << "Current reward point: " << rewardPoint << endl;
		if (this->rewardPoint >= 100) {
			cout << "Do you want to exchange 100 reward points to borrow the item for free?" << endl;
			cout << "1.YES" << endl;
			cout << "2.NO" << endl;
			cout << "Enter here: ";
			cin >> choice;
			cout << endl;
			while (choice != "1" && choice != "2" && choice != "YES" && choice != "NO") {
				cout << "Please only enter: 1 or 2 or YES or NO" << endl;
				cout << "1.YES" << endl;
				cout << "2.NO" << endl;
				cout << "Enter here: ";
				cin >> choice;
				cout << endl;
			}
			if (choice == "1" || choice == "YES") {
				this->rewardPoint -= 100;
				cout <<  "\t\t========== Your item is now FREE!!! ==========" << endl;
				cout << "Updated reward point: " << rewardPoint << endl;
				cout << endl;
			}
		}
		this->rList.push_back(item->getId());
		this->itemRented++;
		return true;
	}
	else {
		cout << "The item is out of stock\n";
		return false;
	}
	return false;
}

// return function
bool VipCustomer::returning(Item* item) {
	for (int i = 0; i < rList.size(); i++) {
		if (item->getId()._Equal(this->rList[i]) && item->returning()) {
			this->rList.erase(this->rList.begin() + i);
			this->itemRented--;
			this->itemReturned++;
			this->rewardPoint += 10;
			return true;
		}
	}
	return false;
}

/*
function supporting the customer promoting
copy all information from old account to new account
except (int)itemReturned and (string)rank
*/
void VipCustomer::copy(Customer* C)
{
	id = C->getId();
	name = C->getName();
	phone = C->getPhone();
	address = C->getAddress();
	itemRented = C->getItemRented();
	rList = C->getItemRentedList();
	rank = "VIP";
	itemReturned = 0;
	rewardPoint = 0;
}