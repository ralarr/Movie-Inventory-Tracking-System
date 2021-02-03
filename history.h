#ifndef _HISTORY_H_
#define _HISTORY_H_

#include "transaction.h"
#include "customer.h"

class History : public Transaction {
  public:
	History();		
	~History();	
	bool setData(string, Inventory*, Customer*);
	Transaction* create();
};

#endif
