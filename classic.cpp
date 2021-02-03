// --------------------------------------------- classic.cpp ----------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class in charge of all the functionality for a movie of classic genre. it grabs the appropriate data from
//	     an external file and displays inventory results. It inherits from the Movie class.
// --------------------------------------------------------------------------------------------------------------------

#include "classic.h"

// --------------------------------- default constructor ----------------------------------------
// Description: Initializes private variables actorFName, actorLName, month, GENRE
// ----------------------------------------------------------------------------------------------
Classic::Classic() : Movie(), actorFName(""), actorLName(""), month(0), GENRE("CLASSIC") {}

// ------------------------------------- destructor ---------------------------------------------
// Description: Deallocates memory on the heap.
// ----------------------------------------------------------------------------------------------
Classic::~Classic() {}

// --------------------------------------- setData ----------------------------------------------
// Description: Grabs the appropriate information from the external file into proper variables.
// ----------------------------------------------------------------------------------------------
void Classic::setData(istream& infile){
	infile.get();
	getline(infile, director, ',');

	if (director.size() > 18) title.resize(18);		

	infile.get();
	getline(infile, title, ',');

	if (title.size() > 32) title.resize(32);		

	infile.get();
	infile >> actorFName >> actorLName;
	infile >> month >> year;
}

// --------------------------------- setDataForCommands -----------------------------------------
// Description: It properly grabs the updated data to be used for commands(data4commands.txt).
// ----------------------------------------------------------------------------------------------
void Classic::setDataForCommands(istream& infile){
	infile >> month;
	infile >> year;
	infile >> actorFName;
	infile >> actorLName;
}

// --------------------------------------- display ----------------------------------------------
// Description: Displays information in the correct order and sets an appropriate padding.
// ----------------------------------------------------------------------------------------------
void Classic::display() const {
	cout << left << setw(24) << title << " " << setw(20) << director << " " << setw(6) << month << " "
             << setw(6) << year << " " << actorFName << " " << actorLName << '\n';
}

// ------------------------------------- displayBanner ------------------------------------------
// Description: Displays the appropriate banner for classic movies.
// ----------------------------------------------------------------------------------------------
void Classic::displayBanner() const {
	cout << "************************************** CLASSIC MOVIES ********************************************\n";
	cout << "IN-HAND  BORROWED   MOVIE-TITLE              DIRECTOR-NAME        MONTH  YEAR   " <<
		"ACTOR-NAME" << '\n';
	cout << "**************************************************************************************************\n";
}

// ------------------------------------ overloaded operator== -----------------------------------
// Description: It overloads the operator== so movies of the classic genre can be compared.
// ----------------------------------------------------------------------------------------------
bool Classic::operator==(const Inventory& rhs) const {
	const Classic& classic = static_cast<const Classic&>(rhs);

	return (year == classic.year && month == classic.month
		&& actorFName == classic.actorFName &&
		actorLName == classic.actorLName);
}

// -------------------------------- overloaded operator< ----------------------------------------
// Description: It overloads the operator< to check the order of two movies of the classic genre.
// ----------------------------------------------------------------------------------------------
bool Classic::operator<(const Inventory& rhs) const {
	const Classic& classic = static_cast<const Classic&>(rhs);

	if (year < classic.year) return true;
	else if (year == classic.year){
		if (actorFName < classic.actorFName) return true;
		else if (actorFName == classic.actorFName) return (actorLName < classic.actorLName);
		else return false;
	} else return false;
}

// ----------------------------------------- create ---------------------------------------------
// Description: It creates a new object of type classic.
// ----------------------------------------------------------------------------------------------
Inventory* Classic::create() { 
	return new Classic(); 
}
