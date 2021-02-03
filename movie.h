#ifndef _MOVIE_H_
#define _MOVIE_H_

#include "inventory.h"

class Movie : public Inventory {
  protected:
	string title;           
	string director;        
	int year;

  public:
	Movie();		
	~Movie();		
	void setData(istream&);
        void setDataForCommands(istream&) = 0;
	void display() const;
	void displayBanner() const = 0;
	
	string getItem() const { return title; };
	string getDirector() { return director; }; 
	string getTitle() { return title; };	
	int getYear() { return year; };		

	bool operator==(const Inventory&) const = 0;
	bool operator<(const Inventory&) const = 0;
	Inventory* create() = 0;
};

#endif
