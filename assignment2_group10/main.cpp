#pragma once
#include "itemList.h"
#include "support.h"
#include <iostream>
int main() {
	itemList item_List;
	listReadItemfile(item_List);
	menu(item_List);
	return 0;
}