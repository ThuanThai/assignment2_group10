#pragma once
#include "Customer.h"
#define MAX_BORROW 2
class GuestCustomer:public Customer
{
public:
	GuestCustomer();
	~GuestCustomer();
	bool borrowing(Item* item);
	bool returning(Item* item);
};

