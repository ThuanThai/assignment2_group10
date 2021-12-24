#pragma once
#include "Customer.h"
class RegularCustomer:public Customer
{
public:
	RegularCustomer();
	~RegularCustomer();
	bool borrowing(Item* item);
	bool returning(Item* item);
};

