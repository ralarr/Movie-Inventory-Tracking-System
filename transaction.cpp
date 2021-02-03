// -------------------------------------------- transaction.cpp -------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Parent class of the classes Borrow, Return, and History. It processes the movie items depending on their
//	     respective genre.
// --------------------------------------------------------------------------------------------------------------------

#include "transaction.h"

// --------------------------------- default constructor ----------------------------------------
// Description: The private data members transType is initialized to Transaction, mediaType to ""
//		and movieItem to NULL.
// ----------------------------------------------------------------------------------------------
Transaction::Transaction() : transType("Transaction"), mediaType(""), movieItem(NULL) {}

// -------------------------------------- destructor --------------------------------------------
// Description: Deallocates memory that was used on the heap.
// ----------------------------------------------------------------------------------------------
Transaction::~Transaction() {}

// ------------------------------------------- setData ------------------------------------------
// Description: Virtual function for the children classes. For this class, it grabs inforamtion
//		for media type, and a movie item.
// ----------------------------------------------------------------------------------------------
bool Transaction::setData(string media, Inventory* item, Customer* cust){
	mediaType = media;
	movieItem = item;
	return true;
}	

// --------------------------------------- display ----------------------------------------------
// Description: Virtual function that prints out to the screen the media and transactio types.
// ----------------------------------------------------------------------------------------------
void Transaction::display() const {
	cout << mediaType << " " << transType << ": ";
}

// ----------------------------------------- create ---------------------------------------------
// Description: It creates a new object of type Transaction.
// ----------------------------------------------------------------------------------------------
Transaction* Transaction::create(){
	return new Transaction();
}
