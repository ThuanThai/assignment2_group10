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
	Customer C1, C2,C3,C4,C5;
	C1.setId("C100");
	C2.setId("C200");
	C3.setId("C600");
	C4.setId("C300");
	C5.setId("C400");

	customerList List(&C1);
	List.appendCustomerBack(&C2);
	List.appendCustomerBack(&C3);
	List.appendCustomerBack(&C4);
	List.appendCustomerBack(&C5);

	List.printCustomerList();
	
	cout << endl << "Sorting..." << endl;

	sort(List);

	List.printCustomerList();
	

	
	

	
	return 0;
}