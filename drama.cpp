// ---------------------------------------------- drama.cpp -----------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class in charge of all the functionality for a movie of drama genre. it grabs the appropriate data from
//           an external file and displays inventory results. It inherits from the Movie class.
// --------------------------------------------------------------------------------------------------------------------

#include "drama.h"

// --------------------------------- default constructor ----------------------------------------
// Description: Initializes private variable GENRE.
// ----------------------------------------------------------------------------------------------
Drama::Drama() : Movie(), GENRE("DRAMA") {}

// ------------------------------------- destructor ---------------------------------------------
// Description: Deallocates memory on the heap.
// ----------------------------------------------------------------------------------------------
Drama::~Drama() {}

// --------------------------------------- setData ----------------------------------------------
// Description: Grabs the appropriate information from the external file into proper variables.
// ----------------------------------------------------------------------------------------------
void Drama::setData(istream& infile){
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;
}

// --------------------------------- setDataForCommands -----------------------------------------
// Description: It properly grabs the updated data to be used for commands(data4commands.txt).
// ----------------------------------------------------------------------------------------------
void Drama::setDataForCommands(istream& infile){
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');
}

// --------------------------------------- display ----------------------------------------------
// Description: Displays information in the correct order and sets an appropriate padding.
// ----------------------------------------------------------------------------------------------
void Drama::display() const {
        cout << left << setw(32) << title << " " << setw(18) << director << " " 
	     << setw(5) << year << '\n';
}

// ------------------------------------- displayBanner ------------------------------------------
// Description: Displays the appropriate banner for drama movies.
// ----------------------------------------------------------------------------------------------
void Drama::displayBanner() const {
        cout << "*************************** DRAMA MOVIES ************************************\n";
        cout << "IN-HAND  BORROWED   TITLE                            DIRECTOR           YEAR  \n";
        cout << "*****************************************************************************\n";
}

// ------------------------------------ overloaded operator== -----------------------------------
// Description: It overloads the operator== so movies of the drama genre can be compared.
// ----------------------------------------------------------------------------------------------
bool Drama::operator==(const Inventory& rhs) const {
	const Drama& drama = static_cast<const Drama&>(rhs);
	return (director == drama.director && title == drama.title);
} 

// -------------------------------- overloaded operator< ----------------------------------------
// Description: It overloads the operator< to check the order of two movies of the drama genre.
// ----------------------------------------------------------------------------------------------
bool Drama::operator<(const Inventory& rhs) const {
	const Drama& drama = static_cast<const Drama&>(rhs);

	if (director < drama.director) return true;
	else if (director == drama.director) return (title < drama.title);
	else return false;
}

// ----------------------------------------- create ---------------------------------------------
// Description: It creates a new object of type drama.
// ----------------------------------------------------------------------------------------------
Inventory* Drama::create(){
	 return new Drama(); 
}
