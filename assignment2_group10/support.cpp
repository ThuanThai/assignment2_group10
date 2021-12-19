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
	while (flag) {
		system("cls");
		current->getItem()->Output();
		cout << "0.Exit" << endl;
		cout << "enter choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:{
			getline(cin, update);
			current->getItem()->setId(id);
			break;
		}
		case 2:{
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

void menu(itemList& iList) {
	bool flag = true;
	string choice;
	string id;
	listReadItemfile(iList);
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
				cout << "enter id: ";
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
		else if (choice == "2") {
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
		}
		else if (choice == "4") {
			customerlist.printcustomerlist();
			system("pause");
		}
		else if (choice == "exit" || choice == "exit") {
			flag = false;
			break;
		}*/
	}
}
bool isValidItemId(string id) {
	if (id.length() != 9) return false;
	if (id.at(0) != 'I') return false;
	if (id.at(4) != '-') return false;
	if (stoi(id.substr(5, 4)) > 2022) return false;
	return true;
}