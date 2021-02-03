// ---------------------------------------------- history.cpp ---------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/14/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class in charge of history transactions. It inherits from the Transaction class.
// --------------------------------------------------------------------------------------------------------------------

#include "history.h"
#include "customer.h"

// --------------------------------- default constructor ----------------------------------------
// Description: The private data member transType to History.
// ----------------------------------------------------------------------------------------------
History::History() : Transaction(){
	transType = "History";
}

// ------------------------------------- destructor ---------------------------------------------
// Description: Deallocates memory that was used on the heap.
// ----------------------------------------------------------------------------------------------
History::~History() {}

// --------------------------------------- setData ----------------------------------------------
// Description: Properly sets the data and displays the respective transaction for a customer.
// ----------------------------------------------------------------------------------------------
bool History::setData(string media, Inventory* item, Customer* aCustomer){
	aCustomer->displayCustomerTransactions();
	return false; 
}

// --------------------------------------- create -----------------------------------------------
// Description: Creates a new object of type Hystory.
// ----------------------------------------------------------------------------------------------
Transaction* History::create(){ 
	return new History(); 
}
