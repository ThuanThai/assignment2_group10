#pragma once
#include "support.h"

bool search(string source, string find) {
	return (source.find(find) != string::npos);
}

//void updateItem(string id, itemList& iList) {
//	string update;
//	int choice;
//	bool flag = true;
//	ItemNode* current = iList.findItem(id);
//	if (current == NULL) {
//		cout << "Can not found\n";
//		system("pause");
//		return;
//	}
//	while (flag) {
//		system("cls");
//		current->getItem()->Output();
//		cout << "0.Exit" << endl;
//		cout << "enter choice: ";
//		cin >> choice;
//		cin.ignore();
//		switch (choice) {
//		case 1: {
//			cout << "Enter new ID: ";
//			getline(cin, update);
//			current->getItem()->setId(id);
//			break;
//		}
//		case 2: {
//			cout << "Enter new title: ";
//			getline(cin, update);
//			current->getItem()->setTitle(update);
//			break;
//		}
//		case 3: {
//			cout << "Enter new type: ";
//			Item* updateItem;
//			string currentType = current->getItem()->getType();
//			getline(cin, update);
//			current->getItem()->setType(update);
//			if (currentType._Equal("Game") && (update._Equal("DVD") || update._Equal("Record"))) {
//				updateItem = new RVItem;
//				updateItem->updateType(current->getItem(), update);
//				current->setItem(updateItem);
//			}
//			else if (currentType._Equal("DVD") || currentType._Equal("Record") && update._Equal("Game")) {
//				updateItem = new Item;
//				updateItem->updateType(current->getItem(), update);
//				current->setItem(updateItem);
//			}
//			break;
//		}
//		case 4: {
//			cout << "Enter new loan type: ";
//			getline(cin, update);
//			current->getItem()->setLoanType(update);
//			break;
//		}
//		case 5: {
//			cout << "Enter new stock: ";
//			int newStock;
//			cin >> newStock;
//			current->getItem()->setStock(newStock);
//			break;
//		}
//		case 6: {
//			cout << "Enter new fee: ";
//			float newFee;
//			cin >> newFee;
//			current->getItem()->setFee(newFee);
//			break;
//		}
//		case 7: {
//			if (current->getItem()->getType()._Equal("Game")) {
//				cout << "wrong chocie";
//				system("pause");
//				continue;
//			}
//			cout << "Enter new genre: ";
//			getline(cin, update);
//			current->getItem()->setGenre(update);
//			break;
//		}
//		case 0:
//			flag = false;
//			break;
//		default:
//			cout << "wrong chocie";
//			system("pause");
//			continue;
//		}
//	}
//}

bool isValidItemId(string id) {
	if (id.length() != 9) return false;
	if (id.at(0) != 'I') return false;
	if (id.at(4) != '-') return false;
	if (stoi(id.substr(5, 4)) > 2022) return false;
	return true;
}
void inputStockSize(int* stock) {
	string stockStr;
	cout << "Num of copies: "; cin >> stockStr;
	try {
		*(stock) = stoi(stockStr);
	}
	catch (const std::exception& ex) {
		inputStockSize(stock);
	}
}
void inputFee(float* fee) {
	string feeStr;
	cout << "Fee: "; cin >> feeStr;
	try {
		*(fee) = stof(feeStr);
	}
	catch (const std::exception& ex) {
		inputFee(fee);
	}
}



void menu() {
	itemList iList; 
	customerList cList;
	bool flag = true;
	string choice;
	string id;
	iList.readItemFile("item.txt");
	cList.readCustomerFile("customers.txt", iList);
	system("pause");
	while (flag) {
		system("cls");
		cout << "1. add a new item, update or delete an existing item\n";
		cout << "2. print item list\n";
		cout << "3. add new customer or update an existing customer\n";
		cout << "4. print customer list\n";
		cout << "5. Rent an item\n";
		cout << "6. Return an item\n";
		cout << "9. Print customer by groups\n";
		cout << "Enter your command here: ";
		cin >> choice;
		cin.ignore();
		if (choice == "1") {
			system("cls");
			cout << "1. add a new item\n";
			cout << "2. update a new item\n";
			cout << "3. delete\n";
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
						cout << "Invalid choice\n";
						cout << "Please enter a digit from 1 to 3!!! ex: enter 1 if you want to add a game.\n";
					}
				} while (choice < "1" || choice > "3");

				if (choice._Equal("1")) {
					type = "Game";
					iList.addNewItem(type);
				}
				else if (choice._Equal("2")) {
					type = "Record";
					iList.addNewItem(type);
				}
				else {
					type == "DVD";
					iList.addNewItem(type);
				}
			}
			else if (choice == "2") {
				cout << "Enter id: ";
				cin >> id;
				iList.updateItem(id);
			}
			else if (choice == "3") {
				iList.printItemList();
				cout << "\t\t ===== delete =====\n";
				cout << "Enter id: ";
				cin >> id;
				iList.deleteItem(id);
			}
		}
		// 2. Print item list
		else if (choice == "2") {
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
		// add, update, delete customer.
		else if (choice == "3") {
			system("cls");
			cout << "1. add a new customer\n";
			cout << "2. update a customer\n";
			cout << "3. delete a customer\n";
			cout << "Enter your command: ";
			cin >> choice;
			if (choice == "1") {
				cList.addNewCustomer();
			}
			else if (choice == "2") {
				cout << "enter id: ";
				cin >> id;
				cList.updateCustomer(id);
			}
			else if (choice == "3") {
				cout << "\t\t ===== delete =====\n";
				cout << "enter id: ";
				cin >> id;
				cList.deleteCustomer(id);
			}
		}
		// 4. Print customer list
		else if (choice == "4") {
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
		
		//5. Rent an item
		else if (choice == "5") {
			cList.borrowing(iList);
			system("pause");
		}

		//6. Return an item
		else if (choice == "6") {
			cList.returning(iList);
			system("pause");
		}

		//9. Print group of customer
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
		else if (choice == "Exit" || choice == "exit") {
			flag = false;
			break;
		}
	}
}

//Sorting functions

//for customer
void swap(CustomerNode* C1, CustomerNode* C2) {
	Customer* tmp = C1->getCustomer();
	C1->setCustomer(C2->getCustomer());
	C2->setCustomer(tmp);
}

//for item
void swap(ItemNode* I1, ItemNode* I2) {
	Item* tmp = I1->getItem();
	I1->setItem(I2->getItem());
	I2->setItem(tmp);
}

// sorting item by id
/*
void sort_by_id(itemList& List)
{
	//check if list has "something"
	if (List.getHead() == NULL) {
		cout << "Nothing in the list" << endl;
		return;
	}
	bool sorted = 0;
	ItemNode* tmp;
	ItemNode* prev;
	//start sorting
	while (!sorted) {
		tmp = List.getHead();
		while (tmp->getNext() != NULL) {
			prev = tmp;
			tmp = tmp->getNext();

			//sorting by Id
			if (tmp->getItem()->getId() < prev->getItem()->getId()) {
				// if after item has id < previous item's
				//swap two items
				swap(prev, tmp);
				sorted = 1;
			}
		}
		sorted = !sorted; //flag to make the sorting continues until no swap function is called
	}
	cout << "Finish sorting the list by Id..." << endl;
}
*/
// sorting item by title
/*
void sort_by_title(itemList& List)
{
	//check if list has "something"
	if (List.getHead() == NULL) {
		cout << "Nothing in the list" << endl;
		return;
	}
	bool sorted = 0;
	ItemNode* tmp;
	ItemNode* prev;
	//start sorting
	while (!sorted) {
		tmp = List.getHead();
		while (tmp->getNext() != NULL) {
			prev = tmp;
			tmp = tmp->getNext();

			//sorting by title
			if (compare_string(prev->getItem()->getTitle(), tmp->getItem()->getTitle())==1) {
				// if after item has title < previous item's
				//swap two items
				swap(prev, tmp);
				sorted = 1;
			}
		}
		sorted = !sorted; //flag to make the sorting continues until no swap function is called
	}
	cout << "Finish sorting the list by Title..." << endl;
}
*/
//sort customer by id
/*
void sort_by_id(customerList& List)
{
	//check if list has "something"
	if (List.getHead() == NULL) {
		cout << "Nothing in the list" << endl;
		return;
	}
	bool sorted = 0;
	CustomerNode* tmp;
	CustomerNode* prev;
	//start sorting
	while (!sorted) {
		tmp = List.getHead();
		while (tmp->getNext() != NULL) {
			prev = tmp;
			tmp = tmp->getNext();

			//sorting by Id
			if (tmp->getCustomer()->getId() < prev->getCustomer()->getId()) {
				// if after customer has id < previous customer's
				//swap two customers
				swap(prev, tmp);
				sorted = 1;
			}
		}
		sorted = !sorted; //flag to make the sorting continues until no swap function is called
	}
	cout << "Finish sorting the list by Id..." << endl;
}
*/
//sort customer by name
/*
void sort_by_name(customerList& List)
{
	//check if list has "something"
	if (List.getHead() == NULL) {
		cout << "Nothing in the list" << endl;
		return;
	}
	bool sorted = 0;
	CustomerNode* tmp;
	CustomerNode* prev;
	//start sorting
	while (!sorted) {
		tmp = List.getHead();
		while (tmp->getNext() != NULL) {
			prev = tmp;
			tmp = tmp->getNext();

			//sorting by name
			if(compare_string(prev->getCustomer()->getName(),tmp->getCustomer()->getName())==1){
				// if the after customer have name < previous customer's
				//swap two customers
				swap(prev, tmp);
				sorted = 1;
			}
		}
		sorted = !sorted; //flag to make the sorting continues until no swap function is called
	}
	cout << "Finish sorting the list by Name..." << endl;
}
*/

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

//void updateCustomer(string id, customerList& cList) {
//	string update;
//	int choice;
//	bool flag = true;
//	CustomerNode* current = cList.findCustomer(id);
//	if (current == NULL) {
//		cout << "Can not found\n";
//		system("pause");
//		return;
//	}
//	while (flag) {
//		system("cls");
//		current->getCustomer();
//		cout << "1.Name: " << current->getCustomer()->getName() << endl;
//		cout << "2.Address: " << current->getCustomer()->getAddress() << endl;
//		cout << "3.Phone: " << current->getCustomer()->getPhone() << endl;
//		cout << "0.Exit" << endl;
//		cout << "Enter attribute you want to change: ";
//		cin >> choice;
//		cin.ignore();
//		switch (choice) {
//		case 1: {
//			cout << "Enter new name: ";
//			getline(cin, update);
//			current->getCustomer()->setName(update);
//			break;
//		}
//		case 2: {
//			cout << "Enter new address: ";
//			getline(cin, update);
//			current->getCustomer()->setAddress(update);
//			break;
//		}
//		case 3: {
//			cout << "Enter new phone number: ";
//			getline(cin, update);
//			while (!isValidPhoneNumber(update)) {
//				cout << "Please enter digits only!!!" << endl;
//				cout << "Enter new phone number: ";
//				getline(cin, update);
//			}
//			current->getCustomer()->setPhone(update);
//			break;
//		}
//		case 0:
//			flag = false;
//			break;
//		default:
//			cout << "wrong chocie";
//			system("pause");
//			continue;
//		}
//	}
//}

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
