#pragma once
#include "itemList.h"
#include "StreamingItem.h"
#include "support.h"
#include <iostream>
int main() {
	itemList item_List;
	/*
	Item dvd;
	dvd.setTitle("hehe");
	StreamingItem record("123", "hug anh","DVD", "1 day", 5, 5, "horror");
	item_List.appendItemBack(dvd);
	item_List.appendItemBack(record);
	item_List.printItemList();
	*/
	//customerList customer_List;
	listReadItemfile(item_List);
	item_List.printItemList();
	addItem(item_List);
	item_List.printItemList();
	//listReadCustomerFile(customer_List);
	//menu(item_List, customer_List);
	return 0;
}