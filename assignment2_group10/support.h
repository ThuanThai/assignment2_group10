#pragma once
#include <sstream>
#include "itemList.h"
#include "customerList.h"
#include <string.h>
#include <string>

using namespace std;
// main function
void menu();

bool search(string source, string find);

//check missing info when reading item file
void checkItemMissing(int status);
//check missing info when reading customer file
void checkCustomerMissing(int status);

// ** For customer **
//check file/user input
bool isValidCustomerId(string id);
bool isValidRank(string rank);
bool isValidPhoneNumber(string phoneNum);
// sort function
void swap(CustomerNode* C1, CustomerNode* C2);


// ** For item **
//check file/user input
bool isValidItemId(string);
void inputStockSize(int* stock);
void inputFee(float* fee);
// sort function
void swap(ItemNode* I1, ItemNode* I2);

// Function compares two strings
// return 1 if x > y
// else return 0
int compare_string(string x, string y);

//function transform string to lowercase
string toLower(string s);

// function print team information
void printGroupInfor();
