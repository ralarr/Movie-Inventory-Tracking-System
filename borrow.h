#ifndef _BORROW_H_
#define _BORROW_H_
#include "transaction.h"

class Borrow : public Transaction {
  public:
	Borrow();	
	~Borrow(); 	

	bool setData(string, Inventory*, Customer*);
	void display() const;
	Transaction* create();
};

#endif
