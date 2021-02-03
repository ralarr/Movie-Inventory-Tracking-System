// ---------------------------------------------- customer.cpp ----------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class in charge of customer variables, transactions, and displays.
// --------------------------------------------------------------------------------------------------------------------

#include "customer.h"

// --------------------------------- default constructor ----------------------------------------
// Description: The private data members are  initialized.
// ----------------------------------------------------------------------------------------------
Customer::Customer() : customerID(0), firstName(""), lastName(""), next(NULL){
	transactionHistory.reserve(10);	
}

// --------------------------------------- destructor -------------------------------------------
// Description: Deallocates memory on the heap.
// ----------------------------------------------------------------------------------------------
Customer::~Customer(){
	delete next;
}

// ----------------------------------------- setData --------------------------------------------
// Description: Grabs the data for Customer values from the external file(data4customers.txt).
// ----------------------------------------------------------------------------------------------
void Customer::setData(istream& infile){
	infile >> customerID;
	
 	if (infile.eof()) return;
	
	infile.get();
	infile >> lastName;

	infile.get();
	infile >> firstName;
}

// ------------------------------ displayCustomerTransactions -----------------------------------
// Description: Prints out to the screen al the transactions made by a customer in chronological
//		order.
// ----------------------------------------------------------------------------------------------
void Customer::displayCustomerTransactions() const {
	cout << "----------------------------------------------------------------------------------------\n";
        cout << " Transactions for customer--->   Id:" << customerID << "    Name: " << lastName << ", " 
	     << firstName << '\n';
        cout << "----------------------------------------------------------------------------------------\n";
                
        if (transactionHistory.size() > 0) {
                for (int i = 0; i < transactionHistory.size(); ++i){
                        transactionHistory[i].display();
                        transactionHistory[i].getItem()->display();
                }
                cout << '\n';
        } else cout << "No Transactions found for customer with ID: " << customerID << '\n';
        cout << '\n';
}

// ------------------------------------ addTransaction ------------------------------------------
// Description: Adds(pushes back) a new transaction into the transactionHistory vector.
// ----------------------------------------------------------------------------------------------
void Customer::addTransaction(Transaction trans){
        transactionHistory.push_back(trans);
}

// ------------------------------------- setCustomerID ------------------------------------------
// Description: It sets the private variable customerID to a new value passed in the parameter.
// ----------------------------------------------------------------------------------------------
void Customer::setCustomerID(int newID){
        customerID = newID;
}

// ------------------------------------- setFirstName -------------------------------------------
// Description: It sets the private variable firstName to a new value passed in the parameter.
// ----------------------------------------------------------------------------------------------
void Customer::setFirstName(string newFirstName){
        firstName = newFirstName;
}

// ------------------------------------- setLastName --------------------------------------------
// Description: It sets the private variable lastName to a new value passed in the parameter.
// ----------------------------------------------------------------------------------------------
void Customer::setLastName(string newLastName){
        lastName = newLastName;
}

// ----------------------------------------- setNext --------------------------------------------
// Description: It sets the private variable next to a new value passed in the parameter.
// ----------------------------------------------------------------------------------------------
void Customer::setNext(Customer* newNext){
        next = newNext;
}
