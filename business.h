#ifndef _BUSINESS_H_
#define _BUSINESS_H_

#include <fstream>
#include <vector>

#include "customer.h"
#include "factory.h"
#include "binarytree.h"
#include "hashtable.h"

static const int MAXINVENTORY = 53;

class Business {
  private:
        Hash* allCustomers = new Hash;
        BinaryTree inventoryList[MAXINVENTORY];
        vector<Transaction> storeTransactionHistory;
        Factory factory;
        string businessName;

  public:
	Business();		
 	Business(string);	
	~Business();		

	void buildCustomers(istream&);
	void buildInventory(istream&);
	void processCommands(istream&);
	void displayInventory() const;
	bool lookUpCustomer(int);
	string getBusinessName() const { return businessName; };
	Customer* getCustomer(int);
};

#endif
