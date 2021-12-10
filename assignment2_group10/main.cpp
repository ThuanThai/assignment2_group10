#pragma once
#include "itemList.h"
#include "support.h"
#include <iostream>
int main() {
	itemList item_List;
	Item dvd;
	dvd.setTitle("hehe");
	item_List.appendItemBack(dvd);
	item_List.printItemList();
	//customerList customer_List;
	//listReadItemfile(item_List);
	//listReadCustomerFile(customer_List);
	//menu(item_List, customer_List);
	return 0;
}