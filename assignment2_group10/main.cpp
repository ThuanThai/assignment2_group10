#pragma once
#include "itemList.h"
#include "support.h"
#include <iostream>

int main() {
	itemList iList;
	listReadItemfile(iList);
	iList.printItemList();
	return 0;
}