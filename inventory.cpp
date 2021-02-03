// -------------------------------------------- inventory.cpp ---------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class in charge of the number of stock of DVD movies for borrows and returns. 
// --------------------------------------------------------------------------------------------------------------------

#include "inventory.h"

// --------------------------------- default constructor ----------------------------------------
// Description: The private data members numberStock and maxStock are initialized to -1 and 0
//		respectively.
// ----------------------------------------------------------------------------------------------
Inventory::Inventory() : numberStock(-1), maxStock(0){} 

// -------------------------------------- destructor --------------------------------------------
// Description: Deallocates memory that was used on the heap.
// ----------------------------------------------------------------------------------------------
Inventory::~Inventory() {} 

// --------------------------------------- setMaxCopies -----------------------------------------
// Description: Sets the maximum number of copies for the private members maxStock and 
//		numberStock.
// ----------------------------------------------------------------------------------------------
void Inventory::setMaxCopies(const int maxNumber){
	maxStock = maxNumber;
	if (numberStock < 0) numberStock = maxNumber;
}

// -------------------------------------- increaseCopies ----------------------------------------
// Description: It increases the number of copies from the stock number when a DVD movie has been
//		returned.
// ----------------------------------------------------------------------------------------------
void Inventory::increaseCopies(){
	if (numberStock != maxStock) numberStock++;
}

// -------------------------------------- decreaseCopies ----------------------------------------
// Description: It decreases the number of copies from the stock number when a DVD movie has been
//		borrowed.
// ----------------------------------------------------------------------------------------------
void Inventory::decreaseCopies(){
	if (numberStock != 0) numberStock--;
}
