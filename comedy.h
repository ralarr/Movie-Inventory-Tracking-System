#ifndef _COMEDYMOVIE_H_
#define _COMEDYMOVIE_H_

#include "movie.h"

class Comedy : public Movie {
  private:
    const string GENRE;

  public: 
	Comedy();		
	~Comedy();		

 	void setData(istream& );
        void setDataForCommands(istream&);
	void display() const;
	void displayBanner() const;
	bool operator==(const Inventory&) const;
	bool operator<(const Inventory&) const;
	Inventory * create();
};

#endif
