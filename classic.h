#ifndef _CLASSICMOVIE_H_
#define _CLASSICMOVIE_H_

#include "movie.h"

class Classic : public Movie {
  private:
    string actorFName;
	string actorLName;
    int month;
    const string GENRE;

  public:
	Classic();	
	~Classic();		

	void setData(istream&);
	void setDataForCommands(istream&);
	void display() const;
	void displayBanner() const;
	bool operator==(const Inventory&) const;
	bool operator<(const Inventory&) const;
	Inventory * create();
};

#endif
