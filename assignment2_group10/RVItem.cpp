#include "RVItem.h"

void RVItem::Output() {
	Item::Output();
	cout << "Genre: " << this->genre << endl;
}

void RVItem::readItemFile(fstream& fileIn) {
	Item::readItemFile(fileIn);
	getline(fileIn, genre);
}

void RVItem::Input(string type) {
	Item::Input(type);
	cout << "Genre: "; cin >> genre;
}