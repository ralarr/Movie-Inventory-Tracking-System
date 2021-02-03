#ifndef _DRAMAMOVIE_H_
#define _DRAMAMOVIE_H_

#include "movie.h"

using namespace std;

class Drama : public Movie {
  private:
    const string GENRE;     

  public: 
	Drama();		
	~Drama(); 		

	void setData(istream& );
    void setDataForCommands(istream&);
	void display() const;
	void displayBanner() const;
	bool operator==(const Inventory&) const;
	bool operator<(const Inventory&) const;
	Inventory* create();
};

#endif
