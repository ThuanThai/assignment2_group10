#pragma once
#include <sstream>
#include "itemList.h"
#include "customerList.h"

using namespace std;

bool search(string source, string find);
void listReadItemfile(itemList& itemList);
void listReadCustomerFile(customerList& cList);
void menu();
bool isValidItemId(string);
void inputStockSize(int* stock);
void inputFee(float* fee);
void borrowing(customerList& cList, itemList& iList);
void returning(customerList& cList, itemList& iList);



