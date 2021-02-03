#ifndef _RETURN_H_
#define _RETURN_H_

#include "transaction.h"
#include "customer.h"

class Return : public Transaction {
  public:
	Return();	
	~Return();	
 
	bool setData(string, Inventory*, Customer*);
	void display() const;
	Transaction* create(); 
};

#endif
