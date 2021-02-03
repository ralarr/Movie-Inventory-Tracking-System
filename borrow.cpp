// ---------------------------------------------- borrow.cpp ----------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class that especializes in the borrow transaction. It inherits from the transaction class.
// --------------------------------------------------------------------------------------------------------------------

#include "borrow.h"

// --------------------------------- default constructor ----------------------------------------
// Description: The private data member trastype is initialized to "Borrow".
// ----------------------------------------------------------------------------------------------
Borrow::Borrow() : Transaction(){
	transType = "Borrow";
} 

// --------------------------------------- destructor -------------------------------------------
// Description: Deallocates memory on the heap.
// ----------------------------------------------------------------------------------------------
Borrow::~Borrow() {} 

// ---------------------------------------- setData ---------------------------------------------
// Description: Function to set the data of a borrowed object.
// ----------------------------------------------------------------------------------------------
bool Borrow::setData(string media, Inventory* dvdMovie, Customer* aCustomer){
	if (dvdMovie != NULL){
		mediaType = media;
		movieItem = dvdMovie;

		if (mediaType != "") movieItem->decreaseCopies();
	}
	return true;
}

// ---------------------------------------- display ---------------------------------------------
// Description: Prints to the screen the mediaType(D) for DVD and the transaction type(B).
// ----------------------------------------------------------------------------------------------
void Borrow::display() const {
	cout << mediaType << " " << transType << " ";
}

// ---------------------------------------- create ----------------------------------------------
// Description: Creates a new object of type Borrow.
// ----------------------------------------------------------------------------------------------
Transaction* Borrow::create(){
	return new Borrow();
}
