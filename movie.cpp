// ---------------------------------------------- movie.cpp -----------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class in chrage of Movie objects. It grabs the director, title, and year from a movie object to later be
//           processed by movie genre.
// --------------------------------------------------------------------------------------------------------------------

#include "movie.h"

// --------------------------------- default constructor ----------------------------------------
// Description: The private data members title, directo, and year to "", "", and 0 respectively.
// ----------------------------------------------------------------------------------------------
Movie::Movie() : Inventory(), title(""), director(""), year(0) {}

// --------------------------------------- destructor -------------------------------------------
// Description: Deallocates memory that was used on the heap.
// ----------------------------------------------------------------------------------------------
Movie::~Movie() {}

// -------------------------------------- display -----------------------------------------------
// Description: Prints out to the screen the title, director, and year of a Movie object.
// ----------------------------------------------------------------------------------------------
void Movie::display() const { 
	cout << title << " " << director << " " << year << '\n';
}

// ----------------------------------------- setData --------------------------------------------
// Description: Grabs information; the director, title, and year from the external file. 
// ----------------------------------------------------------------------------------------------
void Movie::setData(istream& infile){
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;
} 

// --------------------------------------- displayBanner ----------------------------------------
// Description: Prints out to the screen a banner for Movie objects.
// ----------------------------------------------------------------------------------------------
void Movie::displayBanner() const {
	cout << " ************ MOVIE TITLE *********** " << '\n';
}
