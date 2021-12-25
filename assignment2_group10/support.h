#pragma once
#include <sstream>
#include "itemList.h"
#include "customerList.h"
#include <string.h>
#include <string>

using namespace std;


bool search(string source, string find);
void listReadItemfile(itemList& itemList);
void listReadCustomerFile(customerList& cList);
void menu();
void updateCustomer(string id, customerList& cList);
void borrowing(customerList& cList, itemList& iList);
void returning(customerList& cList, itemList& iList);


//for customer
//check file/user input
bool isValidCustomerId(string id);
bool isValidRank(string rank);
// sort
void swap(CustomerNode* C1, CustomerNode* C2);
void sort_by_id(customerList& List);
void sort_by_name(customerList& List);

//for item
//check file/user input
bool isValidItemId(string);
bool isValidItem(Item item, itemList list);
void inputStockSize(int* stock);
void inputFee(float* fee);
//sort
void swap(ItemNode* I1, ItemNode* I2);
void sort_by_id(itemList& List);
void sort_by_title(itemList& List);

// function compare two string
// return 1 if x > y
// else return 0
int compare_string(string x, string y);

//function transform string to lowercase
string toLower(string s);
