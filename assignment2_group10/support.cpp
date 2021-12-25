#pragma once
#include "support.h"

bool search(string source, string find) {
	return (source.find(find) != string::npos);
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
		Item* item = new Item;
		Item* newItem = NULL;
		if (search(tmp, "Game")) {
			len = tmp.length();
			byte = (len * (-1)) - 2;
			fileIn.seekg(byte, 1);
			newItem = new Item;
			newItem->readItemFile(fileIn);
			if (isValidItem(*newItem, itemList)) {
				itemList.appendItemBack(newItem);
			}
		}
		else if (search(tmp, "DVD") || search(tmp, "Record")) {
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
			cout << "Enter new ID: ";
			getline(cin, update);
			current->getItem()->setId(id);
			break;
		}
		case 2: {
			cout << "Enter new title: ";
			getline(cin, update);
			current->getItem()->setTitle(update);
			break;
		}
		case 3: {
			cout << "Enter new type: ";
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
			cout << "Enter new loan type: ";
			getline(cin, update);
			current->getItem()->setLoanType(update);
			break;
		}
		case 5: {
			cout << "Enter new stock: ";
			int newStock;
			cin >> newStock;
			current->getItem()->setStock(newStock);
			break;
		}
		case 6: {
			cout << "Enter new fee: ";
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
			cout << "Enter new genre: ";
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

void borrowing(customerList& cList, itemList& iList) {
	string id;
	cout << "Input customer's ID: "; getline(cin, id);
	if (cList.findCustomer(id) == NULL) {
		cout << "Invalid customer'sID\n";
		return;
	}
	Customer* customer = cList.findCustomer(id)->getCustomer();
	cout << "\t\t====== Customer's Information =====\n";
	cout << customer;
	cout << "Input item's ID: "; getline(cin, id);
	if (iList.findItem(id) == NULL) {
		cout << "Invalid item's ID\n";
		return;
	}
	Item* item = iList.findItem(id)->getItem();
	if (customer->borrowing(item)) cout << "Successfully borrowing \n" << item;
	else cout << "Item out of stock\n";
}

void returning(customerList& cList, itemList& iList) {
	string id;
	cout << "Input customer's ID: "; getline(cin, id);
	if (cList.findCustomer(id) == NULL) {
		cout << "Invalid customer'sID\n";
		return;
	}
	Customer* customer = cList.findCustomer(id)->getCustomer();
	if (customer->getItemRented() == 0) {
		cout << "Your account has not yet made a loan\n";
		return;
	}
	cout << "\t\t====== Customer's Information =====\n";
	cout << customer;
	cout << "Input item's ID: "; getline(cin, id);
	if (iList.findItem(id) == NULL) {
		cout << "Invalid item's ID\n";
		return;
	}
	Item* item = iList.findItem(id)->getItem();
	if (customer->returning(item)) cout << "Successfully returning \n" << item;
	else cout << "The item is not borrowed by this account\n";
}

void menu() {
	itemList iList; 
	customerList cList;
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
		cout << "5. Rent an item\n";
		cout << "6. Return an item\n";
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
			if (choice == "1") sort_by_id(iList);
			else if (choice == "2") sort_by_title(iList);
			
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
				updateCustomer(id, cList);
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
			if (choice == "1") sort_by_id(cList);
			else if (choice == "2") sort_by_name(cList);
		
			//print the customer list
			cList.printCustomerList();
			system("pause");
		}
		else if (choice == "5") {
			borrowing(cList, iList);
			system("pause");
		}
		else if (choice == "6") {
			returning(cList, iList);
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

// sorting item by title
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

//sort customer by id
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

//sort customer by name
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

// check if the valid item
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

void updateCustomer(string id, customerList& cList) {
	string update;
	int choice;
	bool flag = true;
	CustomerNode* current = cList.findCustomer(id);
	if (current == NULL) {
		cout << "Can not found\n";
		system("pause");
		return;
	}
	while (flag) {
		system("cls");
		current->getCustomer();
		cout << "1.Name: " << current->getCustomer()->getName() << endl;
		cout << "2.Address: " << current->getCustomer()->getAddress() << endl;
		cout << "3.Phone: " << current->getCustomer()->getPhone() << endl;
		cout << "0.Exit" << endl;
		cout << "Enter attribute you want to change: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1: {
			cout << "Enter new name: ";
			getline(cin, update);
			current->getCustomer()->setName(update);
			break;
		}
		case 2: {
			cout << "Enter new address: ";
			getline(cin, update);
			current->getCustomer()->setAddress(update);
			break;
		}
		case 3: {
			cout << "Enter new phone number: ";
			getline(cin, update);
			current->getCustomer()->setPhone(update);
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