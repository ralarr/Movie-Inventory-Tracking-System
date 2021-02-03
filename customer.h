#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include "movie.h"
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"

using namespace std;

class Customer {
  private:
	int customerID;
	string firstName;
	string lastName;
	Customer* next;
	vector<Transaction> transactionHistory;

  public:
	Customer();	
	~Customer();	
	
	void setData(istream&);

	void displayCustomerTransactions() const;
	void addTransaction(Transaction);

	
	void setCustomerID(int);
	void setFirstName(string);
	void setLastName(string);
	void setNext(Customer*);

	int getCustomerID() const { return customerID; };
	string getFirstName() const { return firstName; };
	string getLastName() const { return lastName; };
	Customer* getNext() const { return next; };
};

#endif
