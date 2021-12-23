#pragma once
#include "Item.h"
#include "RVItem.h"
#include "itemList.h"
#include "customerList.h"
#include <string.h>
#include <string>

using namespace std;

bool ItemFlag(string tmp);
void listReadItemfile(itemList& itemList);
void menu(itemList& iList, customerList& cList);
bool isValidItemId(string);
void inputStockSize(int* stock);
void inputFee(float* fee);
bool isValidItem(Item item, itemList list);
bool isValidRVItem(RVItem item, itemList list);

//sort fuctions
//for customer
void swap(CustomerNode* C1, CustomerNode* C2);
void sort(customerList& List, int type);

//for item
void swap(ItemNode* I1, ItemNode* I2);
void sort(itemList& List, int type);

// function compare two string
// return 1 if x > y
// else return 0
int compare_string(string x, string y);

//function transform string to lowercase
string toLower(string s);
