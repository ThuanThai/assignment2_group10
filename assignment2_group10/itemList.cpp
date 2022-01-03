#pragma once
#include "itemList.h"
#include "StreamingItem.h"
#include "support.h"
#include <iostream>
using namespace std;

void itemList::appendItemBack(Item* newItem) {
	ItemNode* newNode = new ItemNode(newItem);
	ItemNode* current = head;
	if (current == NULL) {
		head = newNode;
		return;
	}
	while (current->getNext() != NULL) {
		current = current->getNext();
	}
	current->setNext(newNode);
}

ItemNode* itemList::findItem(string searchEl) {
	ItemNode* current = head;
	while (current != NULL && current->getItem()->getId() != searchEl && current->getItem()->getTitle() != searchEl) {
		current = current->getNext();
	}
	if (current == NULL) {
		return NULL;
	}
	return current;
}

void itemList::updateItem(string id) {
	string update;
	int choice;
	bool flag = true;
	ItemNode* current = findItem(id);
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
			while (!isValidItemId(update) || this->findItem(update) != NULL) {
				cout << "Valid Item Id syntax: Ixxx-yyyy | yyyy < 2022 | ID is unique in list." << endl;
				cout << "Enter new ID: "; getline(cin, update);
			}
			current->getItem()->setId(update);
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
			while (!update._Equal("Game") && !update._Equal("DVD") && !update._Equal("Record")) {
				cout << "Only enter valid type: Game || DVD || Record" << endl;
				cout << "Enter new type: ";
				getline(cin, update);
				cout << endl;
			}
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
			while (!update._Equal("2-day") && !update._Equal("1-week")) {
				cout << "Only enter valid loan type: 2-day || 1-week" << endl;
				cout << "Enter new loan type: ";
				getline(cin, update);
				cout << endl;
			}
			current->getItem()->setLoanType(update);
			break;
		}
		case 5: {
			int newStock = 0;
			// get stock size
			cout << endl;
			inputStockSize(&newStock);
			current->getItem()->setStock(newStock);
			break;
		}
		case 6: {
			float newFee = 0.0f;
			cout << endl;
			inputFee(&newFee);
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

void itemList::deleteItem(string ID) {
	ItemNode* current = this->head;
	ItemNode* prev = NULL;
	if (current->getItem()->getId() == ID && current->getNext() != NULL) {
		this->head = this->head->getNext();
		delete current;
		return;
	}
	while (current != NULL && current->getItem()->getId() != ID) {
		prev = current;
		current = current->getNext();
	}
	if (current == NULL) {
		cout << "Cannot found valid information!\n";
		return;
	}
	prev->setNext(current->getNext());
	delete current;
	cout << "Delete Successfully!\n";
	system("pause");
}

void itemList::printItemList() {
	ItemNode* current = this->head;
	int i = 1;
	while (current != NULL) {
		cout << "\t\t===== Item " << i << "=====\n";
		if (current->getItem()->getType()._Equal("Game")) {
			cout << current->getItem();
		}
		else {
			cout << (RVItem*)current->getItem();
		}
		current = current->getNext();
		i++;
	}
}
void itemList::displayOutOfStock() {
	ItemNode* current = head;
	int i = 1;
	while (current != NULL) {
		if (current->getItem()->getStock() == 0) {
			cout << "\t\t===== Item " << i << "=====\n";
			cout << current->getItem();
			i++;
		}
		current = current->getNext();
	}
}
void itemList::addNewItem(string type) {
	Item* newItem = new Item;
	string id, title, loanType, genre;
	int stock = 0;
	float fee = 0.0f;
	// get id
	do {
		cout << "Valid Item Id syntax: Ixxx-yyyy | yyyy < 2022 | ID is unique in list." << endl;
		cout << "ID: "; getline(cin, id);
	} while (!isValidItemId(id) || this->findItem(id) != NULL);

	// get title
	cout << endl;
	cout << "Title: "; getline(cin, title);

	// get loanType
	cout << endl;
	do {
		cout << "Valid loan type: 2-day | 1-week" << endl;
		cout << "Loan Type: "; getline(cin, loanType);
	} while (!loanType._Equal("2-day") && !loanType._Equal("1-week"));

	// get stock size
	cout << endl;
	inputStockSize(&stock);

	// get fee
	cout << endl;
	inputFee(&fee);

	// get genre
	if (type._Equal("DVD") || type._Equal("Record")) {
		cout << endl;
		newItem = new RVItem;
		do {
			cout << "Valid genre: Action | Horror | Drama | Comedy" << endl;
			cout << "Genre: "; cin >> genre;
		} while (!genre._Equal("Action") && !genre._Equal("Horror") && !genre._Equal("Drama") && !genre._Equal("Comedy"));

		newItem->setGenre(genre);
	}
	newItem->setId(id);
	newItem->setTitle(title);
	newItem->setType(type);
	newItem->setLoanType(loanType);
	newItem->setStock(stock);
	newItem->setFee(fee);
	this->appendItemBack(newItem);
}

void itemList::readItemFile(string fileName) {
	fstream fileIn;
	string tmp;
	int line = 1;
	int len;
	int byte;
	fileIn.open(fileName, ios_base::in);
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
			int status = newItem->readItemFile(fileIn);
			if (status == 0) {
				if (this->isValidItem(*newItem)) {
					appendItemBack(newItem);
				}
			}
			else {
				checkItemMissing(status);
				cout << "in line " << line << " file: " << fileName << endl;
			}
		}
		else if (search(tmp, "DVD") || search(tmp, "Record")) {
			len = tmp.length();
			byte = (len * (-1)) - 2;
			fileIn.seekg(byte, 1);
			newItem = new RVItem;
			int status =  newItem->readItemFile(fileIn);
			if (status == 0) {
				if (this->isValidItem(*newItem)) {
					appendItemBack(newItem);
				}
			}
			else {
				checkItemMissing(status);
				cout << "in line " << line << " file: " << fileName << endl;
			}
		}
		line++;
	}
	fileIn.close();
}

void itemList::saveItemFile(string fileName) {
	fstream fileOut(fileName, ios_base::out);
	if (!fileOut) {
		cerr << "Can't open file\n";
	}
	ItemNode* current = head;
	while (current != NULL) {
		current->getItem()->saveItemFile(fileOut);
		current = current->getNext();
	}
	fileOut.close();
}

// check if the valid item
bool itemList::isValidItem(Item item) {
	//check valid id
	if (!isValidItemId(item.getId())) return false;
	//check valid type
	if (!item.getType()._Equal("Game") && !item.getType()._Equal("DVD") && !item.getType()._Equal("Record")) return false;
	//check valid loan type
	if ((!item.getLoanType()._Equal("2-day") && !item.getLoanType()._Equal("1-week"))) return false;
	//check for the same id which is already added to the list
	if (this->findItem(item.getId()) != NULL) {
		ItemNode* existedItem = this->findItem(item.getId());
		// if new item is an existed item in the list - add up the stock
		if (existedItem->getItem()->getTitle() == item.getTitle() && existedItem->getItem()->getType() == item.getType()
			&& existedItem->getItem()->getLoanType() == item.getLoanType() && existedItem->getItem()->getFee() == item.getFee()
			) {
			existedItem->getItem()->setStock(existedItem->getItem()->getStock() + item.getStock());
		}
		return false;
	}
	return true;
}

bool itemList::isValidItem(RVItem item) {
	//check valid id
	if (!isValidItemId(item.getId())) return false;
	//check valid type
	if (!item.getType()._Equal("Game") && !item.getType()._Equal("DVD") && !item.getType()._Equal("Record")) return false;
	//check valid loan type
	if ((!item.getLoanType()._Equal("2-day") && !item.getLoanType()._Equal("1-week"))) return false;
	//check valid genre
	if (!item.getGenre()._Equal("Action") && !item.getGenre()._Equal("Horror") && !item.getGenre()._Equal("Drama") && !item.getGenre()._Equal("Comedy") && !item.getGenre()._Equal("")) return false;
	//check for the same id which is already added to the list
	if (this->findItem(item.getId()) != NULL) {
		ItemNode* existedItem = this->findItem(item.getId());
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

void itemList::sort_by_id()
{
	//check if list has "something"
	if (head == NULL) {
		cout << "Nothing in the list" << endl;
		return;
	}
	bool sorted = 0;
	ItemNode* tmp;
	ItemNode* prev;
	//start sorting
	while (!sorted) {
		tmp = head;
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

void itemList::sort_by_title()
{
	//check if list has "something"
	if (head == NULL) {
		cout << "Nothing in the list" << endl;
		return;
	}
	bool sorted = 0;
	ItemNode* tmp;
	ItemNode* prev;
	//start sorting
	while (!sorted) {
		tmp = head;
		while (tmp->getNext() != NULL) {
			prev = tmp;
			tmp = tmp->getNext();

			//sorting by title
			if (compare_string(prev->getItem()->getTitle(), tmp->getItem()->getTitle()) == 1) {
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
