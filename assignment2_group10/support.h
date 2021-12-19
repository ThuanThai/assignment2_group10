#pragma once
#include "Item.h"
#include "RVItem.h"
#include "itemList.h"
#include "customerList.h"
using namespace std;

bool ItemFlag(string tmp);
void listReadItemfile(itemList& itemList);
void menu(itemList& iList);
bool isValidItemId(string);
void inputStockSize(int* stock);
void inputFee(float* fee);



