#pragma once
#include "itemList.h"
#include "RVItem.h"
#include "support.h"
#include "VipCustomer.h"
#include <iostream>

int main() {
	/*
	itemList iList;
	customerList cList;
	menu(iList, cList);
	
	*/
	// testing 
	Customer C1, C2, C3, C4, C5;
	C1.setId("C100");
	C1.setName("AB");
	C2.setId("C200");
	C2.setName("ac");
	C3.setId("C402");
	C3.setName("aa");
	C4.setId("C400");
	C4.setName("A");
	C5.setId("C102");
	C5.setName("a");

	customerList List(&C1);
	List.appendCustomerBack(&C2);
	List.appendCustomerBack(&C3);
	List.appendCustomerBack(&C4);
	List.appendCustomerBack(&C5);

	List.printCustomerList();

	cout << endl << "Sorting..." << endl;

	sort(List,0);

	List.printCustomerList();

	return 0;
}