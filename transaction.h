#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include "movie.h"

class Customer;
class Transaction {
  protected:
	string transType;
	string mediaType;
	Inventory* movieItem;
 
  public:
	Transaction(); 		
	virtual ~Transaction(); 

	virtual bool setData(string media, Inventory * item, Customer * aCustomer);
	virtual void display() const;
	virtual Transaction * create();

	string getMediaType() { return mediaType; };
	string getTransactionType() { return transType; };	
	Inventory* getItem() const { return movieItem; };	
};

#endif
