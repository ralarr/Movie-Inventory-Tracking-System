#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <iostream>
#include <iomanip>

using namespace std;

class Inventory {
  private:
	int numberStock;
	int maxStock;

  public:
	Inventory();			 
	virtual ~Inventory(); 	
	virtual void setData(istream&) = 0; 
	virtual void setDataForCommands(istream&) = 0;	
	virtual void display() const = 0;	
	virtual void displayBanner() const = 0;
	virtual string getItem() const = 0;	

	void setMaxCopies(const int);
	void increaseCopies();
	void decreaseCopies();

	int getAmountIn() { return numberStock; };	
	int getAmountOut() { return maxStock - numberStock; };

	virtual bool operator==(const Inventory&) const = 0;	
	virtual bool operator<(const Inventory&) const = 0;
	virtual Inventory* create() = 0;
};

#endif
