#pragma once
#include "VipCustomer.h"
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
VipCustomer::~VipCustomer() { ; }
void VipCustomer::setRewardPoint(unsigned int num) { this->rewardPoint = num; }
int VipCustomer::getRewardPoint() { return this->rewardPoint; }

bool VipCustomer::borrowing(Item* item) {
	string choice;
	if (item->borrowing()) {
		cout << "Current reward point: " << rewardPoint << endl;
		if (this->rewardPoint >= 100) {
			cout << "Do you want to exhange 100 reward point to borrow the item for free?" << endl;
			cout << "1.YES" << endl;
			cout << "2.NO" << endl;
			cout << "Enter here: ";
			cin >> choice;
			cout << endl;
			while (choice != "1" && choice != "2" && choice != "YES" && choice != "NO") {
				cout << "Please only enter: 1 || 2 || YES || NO" << endl;
				cout << "1.YES" << endl;
				cout << "2.NO" << endl;
				cout << "Enter here: ";
				cin >> choice;
				cout << endl;
			}
			if (choice == "1" || choice == "YES") {
				this->rewardPoint -= 100;
				cout << "Your item is now FREE!!!" << endl;
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

