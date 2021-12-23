#pragma once
#include "support.h"

bool ItemFlag(string tmp) {
	if (tmp.find("Game") != -1) {
		return true;
	}
	return false;
}

void listReadItemfile(itemList& itemList) {
	fstream fileIn;
	string tmp;
	int len;
	int byte;
	fileIn.open("item.txt", ios_base::in);
	if (!fileIn) {
		cerr << "Cannot open file\n";
	}
	while (getline(fileIn, tmp, '\n')) {
		Item* newItem = NULL;
		bool flag = ItemFlag(tmp);
		if (flag) {
			len = tmp.length();
			byte = (len * (-1)) - 2;
			fileIn.seekg(byte, 1);
			newItem = new Item;
			newItem->readItemFile(fileIn);
			if (isValidItem(*newItem, itemList)) {
				itemList.appendItemBack(newItem);
			}
		}
		else if (!flag) {
			len = tmp.length();
			byte = (len * (-1)) - 2;
			fileIn.seekg(byte, 1);
			newItem = new RVItem;
			newItem->readItemFile(fileIn);
			if (isValidItem(*newItem, itemList)) {
				itemList.appendItemBack(newItem);
			}
		}
	}
	fileIn.close();
}

void listReadCustomerFile(customerList& cList) {
	ifstream fileIn("customers.txt", ios_base::in);
	if (!fileIn) {
		cerr << "Cannot Open File\n";
	}
	while (!fileIn.eof())
	{
		Customer* customer = new Customer;
		Customer* newCustomer = NULL;
		customer->readCustomerFile(fileIn);
		if (customer->getRank().compare("Guest") == 0) {
			newCustomer = new GuestCustomer;
			newCustomer->setCustomerType(customer);
		}
		else if (customer->getRank().compare("Regular") == 0) {
			newCustomer = new RegularCustomer;
			newCustomer->setCustomerType(customer);
		}
		else if (customer->getRank().compare("VIP") == 0) {
			newCustomer = new VipCustomer;
			newCustomer->setCustomerType(customer);
		}
		cList.appendCustomerBack(newCustomer);
	}
	fileIn.close();
}

//
//void listReadCustomerFile(customerList& customerList) {
//	ifstream fileIn;
//	fileIn.open("customers.txt", ios_base::in);
//	if (!fileIn) {
//		cerr << "Cannot open file\n";
//	}
//	while (!fileIn.eof()) {
//		Customer newCustomer;
//		readCustomerFile(fileIn, newCustomer);
//		customerList.appendCustomerBack(newCustomer);
//	}
//	fileIn.close();
//}
//
//void addItem(itemList& itemList) {
//	StreamingItem newStreamingItem;
//	// initialize storing elements
//	string id, title, type, loanType, genre = "";
//	int stock;
//	float fee;
//	cout << "\t\t===== Input Item's Information =====\n";
//	cout << "ID: ";
//	cin >> id;
//	cout << "Title: ";
//	cin >> title;
//	cout << "Type: ";
//	string tmp;
//	getline(cin, tmp);
//	cin >> type;
//	cout << "Loan Type: ";
//	cin >> loanType;
//	cout << "Num of copies: ";
//	cin >> stock;
//	cout << "Fee: ";
//	cin >> fee;
//	if (type._Equal("Record") || type._Equal("DVD")) {
//		cout << "Gerne: ";
//		cin >> genre;
//		// set attributes
//		newStreamingItem.setId(id);
//		newStreamingItem.setTitle(title);
//		newStreamingItem.setType(type);
//		newStreamingItem.setLoanType(loanType);
//		newStreamingItem.setStock(stock);
//		newStreamingItem.setFee(fee);
//		newStreamingItem.setGenre(genre);
//		itemList.appendItemBack(newStreamingItem);
//	}
//	else {
//		// upcast to normal item
//		Item* newItem = &newStreamingItem;
//		// set attributes
//		newItem->setId(id);
//		newItem->setTitle(title);
//		newItem->setType(type);
//		newItem->setLoanType(loanType);
//		newItem->setStock(stock);
//		newItem->setFee(fee);
//		itemList.appendItemBack(*newItem);
//	}
//}

void updateItem(string id, itemList& iList) {
	string update;
	int choice;
	bool flag = true;
	ItemNode* current = iList.findItem(id);
	if (current == NULL) {
		cout << "Can not found\n";
		system("pause");
		return;
	}
	while (flag) {
		system("cls");
		current->getItem()->Output();
		cout << "0.Exit" << endl;
		cout << "enter choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1: {
			getline(cin, update);
			current->getItem()->setId(id);
			break;
		}
		case 2: {
			getline(cin, update);
			current->getItem()->setTitle(update);
			break;
		}
		case 3: {
			Item* updateItem;
			string currentType = current->getItem()->getType();
			getline(cin, update);
			current->getItem()->setType(update);
			if (currentType._Equal("Game") && (update._Equal("DVD") || update._Equal("Record"))) {
				updateItem = new RVItem;
				updateItem->updateType(current->getItem(), update);
				current->setItem(updateItem);
			}
			else if (currentType._Equal("DVD") || currentType._Equal("Record") && update._Equal("Game")) {
				updateItem = new Item;
				updateItem->updateType(current->getItem(), update);
				current->setItem(updateItem);
			}
			break;
		}
		case 4: {
			getline(cin, update);
			current->getItem()->setLoanType(update);
			break;
		}
		case 5: {
			int newStock;
			cin >> newStock;
			current->getItem()->setStock(newStock);
			break;
		}
		case 6: {
			float newFee;
			cin >> newFee;
			current->getItem()->setFee(newFee);
			break;
		}
		case 7: {
			if (current->getItem()->getType()._Equal("Game")) {
				cout << "wrong chocie";
				system("pause");
				continue;
			}
			getline(cin, update);
			current->getItem()->setGenre(update);
			break;
		}
		case 0:
			flag = false;
			break;
		default:
			cout << "wrong chocie";
			system("pause");
			continue;
		}
	}
}

void menu(itemList& iList, customerList& cList) {
	bool flag = true;
	string choice;
	string id;
	listReadItemfile(iList);
	listReadCustomerFile(cList);
	while (flag) {
		system("cls");
		cout << "1. add a new item, update or delete an existing item\n";
		cout << "2. print item list\n";
		cout << "3. add new customer or update an existing customer\n";
		cout << "4. print customer list\n";
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
						cout << "Please enter a digit from 1 to 3!!! ex: enter 1 if you wsnt to add a game.\n";
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
				updateItem(id, iList);
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
			int sorting_type = 1; // variable stores the sorting type
			//ask for sorting type
			cout << "Sort the list by: " << endl;
			cout << "1. Id" << endl;
			cout << "2. Title" << endl;
			do {
				cout << "Enter your command here (1 or 2): ";
				cin >> sorting_type;
				cin.ignore();
			} while (sorting_type != 1 && sorting_type != 2);
			//start sorting
			sort(iList, sorting_type);
			//print the customer list
			iList.printItemList();
			system("pause");
		}
		/*else if (choice == "3") {
			system("cls");
			cout << "1. add a new item\n";
			cout << "2. update a new item\n";
			cout << "3. delete\n";
			cin >> choice;
			if (choice == "1") {
				additem(itemlist);
			}
			else if (choice == "2") {
				cout << "enter id: ";
				cin >> id;
				uppdateitem(id, itemlist);
			}
			else if (choice == "3") {
				itemlist.printitemlist();
				cout << "\t\t ===== delete =====\n";
				cout << "enter id: ";
				cin >> id;
				itemlist.deleteitem(id);
			}
		}*/
		// 4. Print item list
		else if (choice == "4") {
			int sorting_type = 1; // variable stores the sorting type
			//ask for sorting type
			cout << "Sort the list by: " << endl;
			cout << "1. Id" << endl;
			cout << "2. Name" << endl;
			do {
				cout << "Enter your command here (1 or 2): ";
				cin >> sorting_type;
				cin.ignore();
			} while (sorting_type != 1 && sorting_type != 2);

			//start sorting
			sort(cList, sorting_type);
			//print the customer list
			cList.printCustomerList();
			system("pause");
		}
		else if (choice == "exit" || choice == "Exit") {
			flag = false;
			break;
		}
	}
}
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

bool isValidItem(Item item, itemList list) {
	if (!isValidItemId(item.getId())) return false;
	if (!item.getType()._Equal("Game") && !item.getType()._Equal("DVD") && !item.getType()._Equal("Record")) return false;
	if ((!item.getLoanType()._Equal("2-day") && !item.getLoanType()._Equal("1-week"))) return false;
	if (!item.getGenre()._Equal("Action") && !item.getGenre()._Equal("Horror") && !item.getGenre()._Equal("Drama") && !item.getGenre()._Equal("Comedy") && !item.getGenre()._Equal("")) return false;
	if (list.findItem(item.getId()) != NULL) {
		ItemNode* existedItem = list.findItem(item.getId());
		// if new item is an existed item in the list - add up the stock
		if (existedItem->getItem()->getTitle() == item.getTitle() && existedItem->getItem()->getType() == item.getType()
			&& existedItem->getItem()->getLoanType() == item.getLoanType() && existedItem->getItem()->getFee() == item.getFee()
			&& existedItem->getItem()->getGenre() == item.getGenre()) {
			existedItem->getItem()->setStock(existedItem->getItem()->getStock() + item.getStock());
		}
		return false;
	}
	return true;
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

void sort(itemList& List, int type)
{
	//check if list has "something"
	if (List.getHead() == NULL) {
		cout << "Nothing in the list" << endl;
		return;
	}
	/*
		type = 1 -> sort by Id
		type = 2 -> sort by title
	*/
	bool sorted = 0;
	ItemNode* tmp;
	ItemNode* prev;
	while (!sorted) {
		tmp = List.getHead();
		while (tmp->getNext() != NULL) {
			prev = tmp;
			tmp = tmp->getNext();
			//sorting by Id
			if (type == 1) {
				if (tmp->getItem()->getId() < prev->getItem()->getId()) {
					// if customer after have id < previous customer's
					//swap two customers
					swap(prev, tmp);
					sorted = 1;
				}
			}
			// sorting by name
			else {
				if (compare_string(prev->getItem()->getTitle(), tmp->getItem()->getTitle())) {
					swap(prev, tmp);
					sorted = 1;
				}

			}
		}
		sorted = !sorted;
	}
	if (type == 1) cout << "Finish sorting the list by Id..." << endl;
	else cout << "Finish sorting the list by Title..." << endl;
}

//sort customer
void sort(customerList& List, int type)
{
	//check if list has "something"
	if (List.getHead() == NULL) {
		cout << "Nothing in the list" << endl;
		return;
	}
	/*
		type = 1 -> sort by Id
		type = 2 -> sort by name
	*/
	bool sorted = 0;
	CustomerNode* tmp;
	CustomerNode* prev;
	while (!sorted) {
		tmp = List.getHead();
		while (tmp->getNext() != NULL) {
			prev = tmp;
			tmp = tmp->getNext();
			//sorting by Id
			if (type == 1) {
				if (tmp->getCustomer()->getId() < prev->getCustomer()->getId()) {
					// if customer after have id < previous customer's
					//swap two customers
					swap(prev, tmp);
					sorted = 1;
				}
			}
			// sorting by name
			else {
				if (compare_string(prev->getCustomer()->getName(), tmp->getCustomer()->getName())){
					swap(prev,tmp);
					sorted = 1;
				}

			}
		}
		sorted = !sorted;
	}
	if (type == 1) cout << "Finish sorting the list by Id..." << endl;
	else cout << "Finish sorting the list by name..." << endl;
}

// function compare two string
// return 1 if x > y
// else return 0
int compare_string(string prev, string tmp)
{
	string prev_lower = toLower(prev);
	string tmp_lower = toLower(tmp);
	if (prev_lower > tmp_lower) return 1; // if the previous > the temp
	return 0;
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
