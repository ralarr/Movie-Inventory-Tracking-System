// ---------------------------------------------- factory.cpp ---------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class to create Inventory and transaction obcject. Define an interface for creating an object, but let 
// 	     subclasses decide which class to instantiate. 
// --------------------------------------------------------------------------------------------------------------------

#include "factory.h"

// --------------------------------- default constructor ----------------------------------------
// Description: Initializes the inventory and transactions array depending and their subclasses.
// ----------------------------------------------------------------------------------------------
Factory::Factory(){
	for (int i = 0; i < MAXITEMS; ++i){
		storeInventory[i] = NULL;
		transactionInventory[i] = NULL;
		mediaType[i] = "";
    }

	storeInventory[CLASSIC] = new Classic();
	storeInventory[DRAMA] = new Drama();
	storeInventory[COMEDY] = new Comedy();

	transactionInventory[BORROW] = new Borrow();
	transactionInventory[HISTORY] = new History();
	transactionInventory[RETURN] = new Return();

	mediaType[DRAMA] = "DVD";
}

// --------------------------------------- destructor -------------------------------------------
// Description: Deallocates memory on the heap.
// ----------------------------------------------------------------------------------------------
Factory::~Factory(){
	for (int i = 0; i < MAXITEMS; i++){
		if (storeInventory[i] != NULL) delete storeInventory[i];

		if (transactionInventory[i] != NULL) delete transactionInventory[i];
	}
}

// -------------------------------------- createMovie -------------------------------------------
// Description: Creates a new Movie object depending on which subclass has called the factory 
//		class.
// ----------------------------------------------------------------------------------------------
Inventory* Factory::createMovie(char genre, istream& infile){
	string tmp;
	if (storeInventory[charToInt(genre)] == NULL){
		getline(infile, tmp, '\n');
		return NULL;
	} else return storeInventory[charToInt(genre)]->create();
}

// ----------------------------------- createTransaction ----------------------------------------
// Description: Creates a new Transaction object depending on which subclass has called the 
//		factory class.
// ----------------------------------------------------------------------------------------------
Transaction* Factory::createTransaction(char ch, istream& infile){
	string tmp;
	if (transactionInventory[charToInt(ch)] == NULL){
		getline(infile, tmp, '\n');
		return NULL;
	} else return transactionInventory[charToInt(ch)]->create();
}	

// ---------------------------------------- toIndex ---------------------------------------------
// Description: Helper function to access a private function and converts a char to int.
// ----------------------------------------------------------------------------------------------
int Factory::toIndex(char ch){
	return charToInt(ch);
}

// ------------------------------------- getMediaType -------------------------------------------
// Description: Getter function to return the correct media type.
// ----------------------------------------------------------------------------------------------
string Factory::getMediaType(char ch){
	return mediaType[charToInt(ch)];
}

// ----------------------------------------- charToInt ------------------------------------------
// Description: Private function that converts a char to an int depending on its corresponding
//		ascending ASCII value.
// ----------------------------------------------------------------------------------------------
int Factory::charToInt(char genre) const { 
	if (genre < 'a') return genre - 'A'; 
	else return 0;
}
