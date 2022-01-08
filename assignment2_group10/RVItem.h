#pragma once
#include "Item.h"

// Movies and Record DVD
class RVItem : public Item {
private:
	string genre;
public:
	//constructor
	RVItem();
	RVItem(string id, string title, string type, string loanType, int stock, float fee, string genre);

	//destructor
	~RVItem() { ; }

	// print RV Item info
	void Output();

	// read item file
	int readItemFile(fstream&);
	
	// save item file
	void saveItemFile(fstream&);

	// update type of customer
	void updateType(Item* item, string newType);

	//overload ostream
	friend ostream& operator << (ostream& stream, const RVItem* item);

	//getter
	string getGenre();

	//setter
	void setGenre(string genre);
};
