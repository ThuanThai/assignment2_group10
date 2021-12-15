#pragma once
#include "Item.h"
#include "RVItem.h"
#include "itemList.h"
#include "customerNode.h"
#include "customerList.h"
using namespace std;

//void readItemFile(ifstream& fileIn, StreamingItem& newStreamingItem) {
//	// initialize storing elements
//	string id, title, type, loanType, genre = "";
//	int stock;
//	float fee;
//	// read file
//	getline(fileIn, id, ',');
//	getline(fileIn, title, ',');
//	getline(fileIn, type, ',');
//	getline(fileIn, loanType, ',');
//	fileIn >> stock;
//	fileIn.ignore();
//	fileIn >> fee;
//	fileIn.ignore();
//	if (type._Equal("Record") || type._Equal("DVD")) {
//		// get genre if it is DVD/records
//		getline(fileIn, genre, '\n');
//		// set attributes
//		newStreamingItem.setId(id);
//		newStreamingItem.setTitle(title);
//		newStreamingItem.setType(type);
//		newStreamingItem.setLoanType(loanType);
//		newStreamingItem.setStock(stock);
//		newStreamingItem.setFee(fee);
//		newStreamingItem.setGenre(genre);
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
//	}
//}
//
//void readCustomerFile(ifstream& fileIn, Customer& newCustomer) {
//	string tmp;
//	getline(fileIn, newCustomer.id, ',');
//	getline(fileIn, newCustomer.name, ',');
//	getline(fileIn, newCustomer.address, ',');
//	getline(fileIn, newCustomer.phone, ',');
//	fileIn >> newCustomer.numOfRentals;
//	fileIn.ignore();
//	getline(fileIn, newCustomer.customerType);
//	while (getline(fileIn, tmp, '\n')) {
//		if (tmp[0] == 'I') {
//			stringstream ss(tmp);
//			ss >> newCustomer.listItemId.list[newCustomer.listItemId.count];
//			newCustomer.listItemId.count++;
//		}
//		else {
//			int byte = (tmp.length() + 2) * (-1);
//			fileIn.seekg(byte, 1);
//			break;
//		}
//	}
//}
//


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
			newItem= new Item;
			newItem->readItemFile(fileIn);
			itemList.appendItemBack(newItem);
		}
		else if (!flag) {
			len = tmp.length();
			byte = (len * (-1)) - 2;
			fileIn.seekg(byte, 1);
			newItem = new RVItem;
			newItem->readItemFile(fileIn);
			itemList.appendItemBack(newItem);
		}
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


//void uppdateitem(string id, itemlist& itemlist) {
//	node* current = itemlist.gethead();
//	int choice;
//	bool flag = true;
//	while (current != null && current->getitem().id != id) {
//		current = current->getnext();
//	}
//	if (current == null) {
//		cout << "cannot found!\n";
//		return;
//	}
//	item newitem = current->getitem();
//	while (flag) {
//		system("cls");
//		cout << "1.id: " << current->getitem().id << endl;
//		cout << "2.title: " << current->getitem().title << endl;
//		cout << "3.type: " << current->getitem().type << endl;
//		cout << "4.loan type: " << current->getitem().loantype << endl;
//		cout << "5.num of copies: " << current->getitem().numofcopies << endl;
//		cout << "6.fee: " << current->getitem().fee << endl;
//		if (current->getitem().genre != "") {
//			cout << "7. genre: " << current->getitem().genre << endl;
//		}
//		cout << "0. exit" << endl;
//		cout << "enter choice: ";
//		cin >> choice;
//		switch (choice) {
//		case 1:{
//			cin >> newitem.id;
//			current->setitem(newitem);
//			break;
//		}
//		case 2:{
//			cin >> newitem.title;
//			current->setitem(newitem);
//			break;
//		}
//		case 3: {
//			cin >> newitem.type;
//			current->setitem(newitem);
//			break;
//		}
//		case 4: {
//			cin >> newitem.loantype;
//			current->setitem(newitem);
//			break;
//		}
//		case 5: {
//			cin >> newitem.numofcopies;
//			current->setitem(newitem);
//			break;
//		}
//		case 6: {
//			cin >> newitem.fee;
//			current->setitem(newitem);
//			break;
//		}
//		case 7: {
//			cin >> newitem.genre;
//			current->setitem(newitem);
//			break;
//		}
//		case 0:
//			flag = false;
//			break;
//		default:
//			cout << "wrong chocie";
//			continue;
//		}
//	}
//}
//
//void menu(itemlist& itemlist, customerlist& customerlist) {
//	bool flag = true;
//	string choice;
//	string id;
//	while (flag) {
//		system("cls");
//		cout << "1. add a new item, update or delete an existing item\n";
//		cout << "2. print item list\n";
//		cout << "3. add new customer or update an existing customer\n";
//		cout << "4. print customer list\n";
//		cin >> choice;
//		if (choice == "1") {
//			system("cls");
//			cout << "1. add a new item\n";
//			cout << "2. update a new item\n";
//			cout << "3. delete\n";
//			cin >> choice;
//			if (choice == "1") {
//				additem(itemlist);
//			}
//			else if (choice == "2") {
//				cout << "enter id: ";
//				cin >> id;
//				uppdateitem(id, itemlist);
//			}
//			else if (choice == "3") {
//				itemlist.printitemlist();
//				cout << "\t\t ===== delete =====\n";
//				cout << "enter id: ";
//				cin >> id;
//				itemlist.deleteitem(id);
//			}
//		}
//		else if (choice == "3") {
//			itemlist.printitemlist();
//			system("pause");
//		}
//		else if (choice == "3") {
//			system("cls");
//			cout << "1. add a new item\n";
//			cout << "2. update a new item\n";
//			cout << "3. delete\n";
//			cin >> choice;
//			if (choice == "1") {
//				additem(itemlist);
//			}
//			else if (choice == "2") {
//				cout << "enter id: ";
//				cin >> id;
//				uppdateitem(id, itemlist);
//			}
//			else if (choice == "3") {
//				itemlist.printitemlist();
//				cout << "\t\t ===== delete =====\n";
//				cout << "enter id: ";
//				cin >> id;
//				itemlist.deleteitem(id);
//			}
//		}
//		else if (choice == "4") {
//			customerlist.printcustomerlist();
//			system("pause");
//		}
//		else if (choice == "exit" || choice == "exit") {
//			flag = false;
//			break;
//		}
//	}
//}

