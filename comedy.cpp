// --------------------------------------------- comedy.cpp -----------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class in charge of all the functionality for a movie of comedy genre. it grabs the appropriate data from
//           an external file and displays inventory results. It inherits from the Movie class.
// --------------------------------------------------------------------------------------------------------------------

#include "comedy.h"

// --------------------------------- default constructor ----------------------------------------
// Description: Initializes private variable GENRE.
// ----------------------------------------------------------------------------------------------
Comedy::Comedy() : Movie(), GENRE("COMEDY") {}

// ------------------------------------- destructor ---------------------------------------------
// Description: Deallocates memory on the heap.
// ----------------------------------------------------------------------------------------------
Comedy::~Comedy() {}

// --------------------------------------- setData ----------------------------------------------
// Description: Grabs the appropriate information from the external file into proper variables.
// ----------------------------------------------------------------------------------------------
void Comedy::setData(istream& infile){
        infile.get();
        getline(infile, director, ',');
        
        if (director.size() > 18) title.resize(18);

        infile.get();
        getline(infile, title, ',');
        
        if (title.size() > 32) title.resize(32);

        infile.get();
        infile >> year;
}

// --------------------------------- setDataForCommands -----------------------------------------
// Description: It properly grabs the updated data to be used for commands(data4commands.txt).
// ----------------------------------------------------------------------------------------------
void Comedy::setDataForCommands(istream& infile) {
        infile.get();
        getline(infile, title, ',');
        infile >> year;
}

// --------------------------------------- display ----------------------------------------------
// Description: Displays information in the correct order and sets an appropriate padding.
// ----------------------------------------------------------------------------------------------
void Comedy::display() const { 	
	cout << left << setw(32) << title << " " << setw(18) << director << " "
             << setw(5) << year << '\n';
}

// ------------------------------------- displayBanner ------------------------------------------
// Description: Displays the appropriate banner for classic movies.
// ----------------------------------------------------------------------------------------------
void Comedy::displayBanner() const {
	cout << "Display Comedy movies FIRST" << '\n';
	cout << "*************************** COMEDY MOVIES ***********************************\n";
	cout << "IN-HAND  BORROWED   TITLE    		             DIRECTOR           YEAR  \n";
	cout << "*****************************************************************************\n";
}

// ------------------------------------ overloaded operator== -----------------------------------
// Description: It overloads the operator== so movies of the comedy genre can be compared.
// ----------------------------------------------------------------------------------------------
bool Comedy::operator==(const Inventory& rhs) const {
	const Comedy& comedy = static_cast<const Comedy&>(rhs);
	return (title == comedy.title && year == comedy.year);
}

// -------------------------------- overloaded operator< ----------------------------------------
// Description: It overloads the operator< to check the order of two movies of the comedy genre.
// ----------------------------------------------------------------------------------------------
bool Comedy::operator<(const Inventory& rhs) const {
	const Comedy& comedy = static_cast<const Comedy&>(rhs);

	if (title < comedy.title) return true;
	else if (title == comedy.title) return (year < comedy.year);
	else return false;
}

// ----------------------------------------- create ---------------------------------------------
// Description: It creates a new object of type comedy.
// ----------------------------------------------------------------------------------------------
Inventory * Comedy::create(){ 
	return new Comedy();
}
