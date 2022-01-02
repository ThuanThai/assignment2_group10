#pragma once
#include "itemList.h"
#include "RVItem.h"
#include "support.h"
#include "VipCustomer.h"
#include <iostream>

int main() { 
	//menu();
	
	Customer* C1 = new Customer;
	Customer* C2 = new RegularCustomer;
	Customer* C3 = new VipCustomer;
	C1->setName("Phong");
	C2->setName("HA");
	C3->setName("Thuan");

	CustomerNode* CN1 = new CustomerNode(C1);
	CustomerNode* CN2 = new CustomerNode(C2);
	CustomerNode* CN3 = new CustomerNode(C3);

	cout << C1 << endl;
	cout << C2 << endl;
	cout << C3 << endl;

	CN1->promoteCustomer();
	CN2->promoteCustomer();
	CN3->promoteCustomer();
	
	cout << "c1: " << CN1->getCustomer()->getName() << endl;
	cout << "c2: " << CN2->getCustomer()->getName() << endl;
	CN2->getCustomer()->setRewardPoint(10);
	cout << "c2: " << CN2->getCustomer()->getRewardPoint() << endl;
	cout << "c3: " << CN3->getCustomer()->getName() << endl;
	return 0;
}