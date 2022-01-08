#pragma once
#include "support.h"

bool search(string source, string find) {
	return (source.find(find) != string::npos);
}

// check for valid item's ID
bool isValidItemId(string id) {
	if (id.length() != 9) return false;
	if (id.at(0) != 'I') return false;
	if (id.at(4) != '-') return false;
	for (int i = 1; i < id.length(); i++) {
		if (i != 4) {
			if (!isdigit(id[i])) return false;
		}
	}
	if (stoi(id.substr(5, 4)) > 2022) return false;
	return true;
}

// check for valid item's stock size
void inputStockSize(int* stock) {
	string stockStr;
	cout << "Num of copies: "; cin >> stockStr;
	try {
		*stock = stoi(stockStr);
		if (*stock < 0) {
			cerr << "========== Enter positive number only ==========\n";
			inputStockSize(stock);
		}
	}
	catch (const std::exception& ex) {
		cerr << "========== Enter number only ==========\n";
		inputStockSize(stock);
	}
}

// check for valid item's fee
void inputFee(float* fee) {
	string feeStr;
	cout << "Fee: "; cin >> feeStr;
	try {
		*fee = stof(feeStr);
		if (*fee < 0) {
			cerr << "========== Enter positive number only ==========\n";
			inputFee(fee);
		}
	}
	catch (const std::exception& ex) {
		cerr << "========== Enter number only ==========\n";
		inputFee(fee);
	}
}

// function print team information
void printGroupInfor() {
	cout << "\n\t\tASSIGNMENT 2 GROUP 10" << endl;
	cout << "s3877819, s3877819@rmit.edu.vn, Phong, Le" << endl;
	cout << "s3877798, s3877798@rmit.edu.vn, Anh, Nguyen" << endl;
	cout << "s3877024, s3877024@rmit.edu.vn, Thuan, Thai" << endl;
	cout << "s3761910, s3761910@rmit.edu.vn, Dat, Phan" << endl;
}

// main function
void menu() {
	//create two lists
	itemList iList;
	customerList cList;

	// menu flag for loop
	bool flag = true;

	string choice;
	string searchElement;
	
	//read item and customer file
	// and print error message on missing infomation
	iList.readItemFile("item.txt");
	cList.readCustomerFile("customers.txt", iList);
	system("pause");

	while (flag) {
		system("cls");
		cout << " 1. Add a new item, update or delete an existing item\n";
		cout << " 2. Add new customer or update an existing customer\n";
		cout << " 3. Promote an existing customer\n";
		cout << " 4. Rent an item\n";
		cout << " 5. Return an item\n";
		cout << " 6. Display all items\n";
		cout << " 7. Display out-of-stock items\n";
		cout << " 8. Display all customers\n";
		cout << " 9. Print customer by groups\n";
		cout << "10. Search items or customers\n";
		cout << "Type \"Exit\" to save the file and exit the program\n\n";
		cout << "Enter your command here: ";
		cin >> choice;
		cin.ignore();

		// Option 1. add, update, delete item
		if (choice == "1") {
			system("cls");
			// sub menu
			cout << "1. Add a new item\n";
			cout << "2. Update an item\n";
			cout << "3. Delete\n";
			cout << "Enter your command here: ";
			cin >> choice;
			cin.ignore();
			if (choice._Equal("1")) {
				string type;
				cout << "1. Game\n";
				cout << "2. Record\n";
				cout << "3. DVD\n";
				do {
					cout << "What type of item you want to add: ";
					getline(cin, choice);
					if (choice < "1" || choice > "3") {
						cout << "========== Invalid choice ==========\n";
						cout << "Please enter a digit from 1 to 3! (ex: enter 1 if you want to add a game.)\n";
					}
				} while (choice < "1" || choice > "3");

				// Add a game
				if (choice._Equal("1")) {
					type = "Game";
					iList.addNewItem(type);
				}

				// or add a record
				else if (choice._Equal("2")) {
					type = "Record";
					iList.addNewItem(type);
				}
				// or add a DVD
				else {
					type = "DVD";
					iList.addNewItem(type);
				}
			}
			
			// update an item searched by Id/Title
			else if (choice == "2") {
				cout << "Enter ID/Title: ";
				cin >> searchElement;
				iList.updateItem(searchElement);
			}

			// Delete an item 
			else if (choice == "3") {
				iList.printItemList();
				cout << "\t\t ===== delete =====\n";
				cout << "Enter ID/Title: ";
				cin >> searchElement;
				
				// check if item is rented or not
				if (cList.isItemRented(searchElement))
				{
					cout << "========== Item is already rented! ==========\n";
					system("pause");
				}
				else 
				{
					iList.deleteItem(searchElement);
				}
			}
		}
		// Option 2. add, update, customer
		else if (choice == "2") {
			system("cls");
			cout << "1. add a new customer\n";
			cout << "2. update a customer\n";
			cout << "Enter your command: ";
			do {
				getline(cin, choice);
				if (choice < "1" || choice > "2") {
					cout << "========== Invalid choice ==========\n";
					cout << "Please enter a digit from 1 to 3! (ex: enter 1 if you want to add a customer)\n";
					cout << "Enter your command: ";
				}
			} while (choice < "1" || choice > "2");

			// add a customer
			if (choice == "1") {
				cList.addNewCustomer();
			}

			// update customer
			else if (choice == "2") {
				cout << "Enter ID/Name: ";
				cin >> searchElement;
				cList.updateCustomer(searchElement);
			}
		}

		// Option 3. Promote customer type
		else if (choice == "3") {
			//ask for customer id
			cout << "Input customer's ID/Name: "; getline(cin, searchElement);
			if (cList.findCustomer(searchElement) == NULL) {
				// if id is invalid
				cout << "========== Invalid customer's ID/Name ==========\n";
				system("pause");
				continue;
			}
			//display the account to be promoted
			cout << cList.findCustomer(searchElement)->getCustomer();
			if (cList.findCustomer(searchElement)->promoteCustomer())
				// if the promotion succeeds
				// display new account
				cout << cList.findCustomer(searchElement)->getCustomer();
			else cout << "This customer account does not meet the requirement to be promoted!" << endl;
			system("pause");
		}

		// Option 4. Rent an item
		else if (choice == "4") {
			cList.borrowing(iList);
			system("pause");
		}

		// Option 5. Return an item
		else if (choice == "5") {
			cList.returning(iList);
			system("pause");
		}
		// Option 6. Print item list sorted by 
		// 1. Id
		// 2. Title
		else if (choice == "6") {
			//ask for sorting type
			cout << "Sort the list by: " << endl;
			cout << "1. Id" << endl;
			cout << "2. Title" << endl;
			do {
				cout << "Enter your command here (1 or 2): ";
				cin >> choice;
				cin.ignore();
			} while (choice != "1" && choice != "2");

			//check sorting type
			if (choice == "1") iList.sort_by_id();
			else if (choice == "2") iList.sort_by_title();

			//print the customer list
			iList.printItemList();
			system("pause");
		}

		// Option 7. Display out of stock  
		else if (choice._Equal("7")) {
			iList.displayOutOfStock();
			system("pause");
		}

		// Option 8. Display customer list sorted by
		// 1. Id
		// 2. Name
		else if (choice._Equal("8")) {
			//ask for sorting type
			cout << "Sort the list by: " << endl;
			cout << "1. Id" << endl;
			cout << "2. Name" << endl;
			do {
				cout << "Enter your command here (1 or 2): ";
				cin >> choice;
				cin.ignore();
			} while (choice != "1" && choice != "2");

			//check sorting type
			if (choice == "1") cList.sort_by_id();
			else if (choice == "2") cList.sort_by_name();

			//print the customer list
			cList.printCustomerList();
			system("pause");
		}
		// Option 9. Print customers by group
		else if (choice == "9") {
			//ask for which group
			cout << "Display:  " << endl;
			cout << "1. Guest customers" << endl;
			cout << "2. Regular customers" << endl;
			cout << "3. VIP customers" << endl;
			do {
				cout << "Enter your command here (1 or 2): ";
				cin >> choice;
				cin.ignore();
			} while (choice != "1" && choice != "2" && choice != "3");
			//sort by id before displaying
			cList.sort_by_id();

			//start print out customer by group
			if (choice == "1") cList.printGuest(); //print the guest
			else if (choice == "2") cList.printRegular(); //print the regular
			else cList.printVIP(); // print the vip pro
			system("pause");
		}
		// Option 10. Search for item or customer 
		else if (choice._Equal("10")) {
			cout << "1. Item" << endl;
			cout << "2. Customer" << endl;
			do {
				cout << "Enter your command here (1 or 2): ";
				getline(cin, choice);
			} while (choice != "1" && choice != "2");
			// if choice is item
			if (choice._Equal("1")) {
				cout << "Input item's ID/Title: "; getline(cin, searchElement);
				iList.search_for(searchElement);
				system("pause");
			}
			// if choice is customer
			else {
				cout << "Input customer's ID/Full Name: "; getline(cin, searchElement);
				cList.search_for(searchElement);
				system("pause");
			}
		}

		// Save the file and exit the program
		else if (choice == "Exit" || choice == "exit") {
			iList.saveItemFile("item.txt");
			cList.saveFileCustomer("customers.txt");
			printGroupInfor();
			flag = false;
			break;
		}
	}
}

// ** For customer **
// sort function
void swap(CustomerNode* C1, CustomerNode* C2) {
	Customer* tmp = C1->getCustomer();
	C1->setCustomer(C2->getCustomer());
	C2->setCustomer(tmp);
}

// ** For item **
// sort function
void swap(ItemNode* I1, ItemNode* I2) {
	Item* tmp = I1->getItem();
	I1->setItem(I2->getItem());
	I2->setItem(tmp);
}

// function compare two string
// return 1 if x > y
// else return 0
int compare_string(string prev, string tmp)
{
	string prev_lower = toLower(prev);
	string tmp_lower = toLower(tmp);
	if (prev_lower > tmp_lower) return 1; // if the previous > the temp
	if (prev_lower < tmp_lower) return -1; // if the previous < the temp
	return 0; // if the previous = the temp
}

//function transform string to lowercase
string toLower(string s)
{
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 'a' - 'A';
		}
	}
	return s;
}

// check customer id
bool isValidCustomerId(string id) {
	if (id.length() != 4) return false;
	if (id.at(0) != 'C') return false;
	return true;
}

//check customer rank
bool isValidRank(string rank)
{
	if (!rank._Equal("Guest") && !rank._Equal("Regular") && !rank._Equal("VIP")) return false;
	return true;
}

//check missing info when reading item file
void checkItemMissing(int status) {
	switch (status) {
	case 1:
		cout << "Miss item id ";
		break;
	case 2:
		cout << "Miss title";
		break;
	case 3:
		cout << "Miss rental type ";
		break;
	case 4:
		cout << "Miss loan type ";
		break;
	case 5:
		cout << "Miss number_of_copies ";
		break;
	case 6:
		cout << "Miss rental fee ";
		break;
	case 7:
		cout << "Miss genre ";
		break;
	}
}

//check missing info when reading customer file
void checkCustomerMissing(int status) {
	switch (status) {
	case 1:
		cout << "Miss customer id ";
		break;
	case 2:
		cout << "Miss customer name ";
		break;
	case 3:
		cout << "Miss customer address ";
		break;
	case 4:
		cout << "Miss customer phone number ";
		break;
	case 5:
		cout << "Miss customer rentals ";
		break;
	case 6:
		cout << "Miss customer type ";
		break;
	case 7:
		cout << "the quantity of the rental item does not match the quantity on the listing ";
		break;
	}
}

bool isValidPhoneNumber(string phoneNum) {
	for (int i = 0; i < phoneNum.length(); i++) {
		if (phoneNum[i] < '0' || phoneNum[i] > '9') return false;
	}
}