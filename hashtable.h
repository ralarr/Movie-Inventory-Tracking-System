#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "customer.h"

class Hash {
  private:
      static const int TABLE_SIZE = 13;    
      Customer* HashTable[TABLE_SIZE];
  public:
      Hash();         
      ~Hash();      
      int hashFunction(int);
      void addCustomer(int, string, string);
      bool findCustomer(int);
	Customer* getCustomer(int);
	void printTable();
      int numberOfCustomersInIndex(int);
};

#endif
