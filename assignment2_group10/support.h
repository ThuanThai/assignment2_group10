#pragma once
#include <sstream>
#include "itemList.h"
#include "customerList.h"
#include <string.h>
#include <string>

using namespace std;
bool search(string source, string find);
void menu();
void updateCustomer(string id, customerList& cList);

//for customer
//check file/user input
bool isValidCustomerId(string id);
bool isValidRank(string rank);
bool isValidPhoneNumber(string phoneNum);
// sort
void swap(CustomerNode* C1, CustomerNode* C2);
void sort_by_id(customerList& List);
void sort_by_name(customerList& List);

//for item
//check file/user input
bool isValidItemId(string);
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
