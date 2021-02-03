#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"

static const int MAXITEMS = 26;
static const int CLASSIC = 2;
static const int DRAMA = 3;
static const int COMEDY = 5;
static const int BORROW = 1;
static const int HISTORY = 7;
static const int RETURN = 17;

class Factory {
  private:
    Inventory* storeInventory[MAXITEMS];
    Transaction* transactionInventory[MAXITEMS];
    string mediaType[MAXITEMS];

    int charToInt(char) const; 

    public:
    Factory();		
    ~Factory();	

    Inventory* createMovie(char, istream&);
    Transaction* createTransaction(char, istream&);
    int toIndex(char);
    string getMediaType(char);
};

#endif
