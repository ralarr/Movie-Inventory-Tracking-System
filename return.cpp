// ---------------------------------------------- return.cpp ----------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class that especializes in the return transaction. It inherits from the transaction class.
// --------------------------------------------------------------------------------------------------------------------

#include "return.h"

// --------------------------------- default constructor ----------------------------------------
// Description: The private data member trastype is initialized to "Return".
// ----------------------------------------------------------------------------------------------
Return::Return() : Transaction(){
	transType = "Return";
}

// --------------------------------------- destructor -------------------------------------------
// Description: Deallocates memory on the heap.
// ----------------------------------------------------------------------------------------------
Return::~Return() {}

// ---------------------------------------- setData ---------------------------------------------
// Description: Function to set the data of a returned object.
// ----------------------------------------------------------------------------------------------
bool Return::setData(string media, Inventory* item, Customer* aCustomer){
	if (item != NULL){
		mediaType = media;
		movieItem = item;

		if (mediaType != "") movieItem->increaseCopies();
	}

	return true;
}

// ---------------------------------------- display ---------------------------------------------
// Description: Prints to the screen the mediaType(D) for DVD and the transaction type(R).
// ----------------------------------------------------------------------------------------------
void Return::display() const {
	cout << mediaType << " " << transType << " ";
} 

// ---------------------------------------- create ----------------------------------------------
// Description: Creates a new object of type Return.
// ----------------------------------------------------------------------------------------------
Transaction* Return::create(){ 
	return new Return(); 
} 
