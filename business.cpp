// ---------------------------------------------- business.cpp --------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class in charge of building the customers and movies inventory and to process the given command correctly
//	     all from the external files.
// --------------------------------------------------------------------------------------------------------------------

#include "business.h"

// --------------------------------- default constructor ----------------------------------------
// Description: The private data member businessName to ""
// ----------------------------------------------------------------------------------------------
Business::Business() : businessName("") {}

// --------------------------- overloaded string constructor ------------------------------------
// Description: To initialize an object of type Business with a name passed as a string. 
// ----------------------------------------------------------------------------------------------
Business::Business(string name) : businessName(name) {}

// -------------------------------------- destructor --------------------------------------------
// Description: Deallocates memory that was used on the heap.
// ----------------------------------------------------------------------------------------------
Business::~Business(){
	delete allCustomers;
}

// ------------------------------------ buildCustomers ------------------------------------------
// Description: It adds properly new customers to the hash table. The customers informations is
//		obtained from the external file(data4customers.txt).
// ----------------------------------------------------------------------------------------------
void Business::buildCustomers(istream& customersFile){
	while (true){
		Customer* customer = new Customer();
		customer->setData(customersFile);

		if (customersFile.eof()){
			delete customer;
			break;
		}
// pass the appropriate string to build the customers hash table
		allCustomers->addCustomer(customer->getCustomerID(), customer->getFirstName(), customer->getLastName());
		delete customer;
	}
        
}

// -------------------------------------- buildInventory ----------------------------------------
// Description: It properly adds movies to the movie inventory. The movie information is obtained
//		from the external file(data4movies.txt).
// ----------------------------------------------------------------------------------------------
void Business::buildInventory(istream& infile){		
	char ch = ' ';
	int qty = 0;

	while (true){
		infile >> ch;
			
		infile.get();
		infile >> qty;
		
		string qtyToString = to_string(qty);
		
		getline(infile, qtyToString, ',');

		if (infile.eof()) break;

		// create a new movie item using the factory class
		Inventory* newMovie = factory.createMovie(ch, infile);
		
		if (newMovie != NULL){
			newMovie->setData(infile);
			bool inserted = inventoryList[factory.toIndex(ch)].insert(newMovie, qty);

			if (!inserted){
				delete newMovie;
				cout << "Movie couldn't be inserted" << '\n';
			}
		}
		newMovie = NULL;
		delete newMovie;
	}
}

// ------------------------------------ processCommands ------------------------------------------
// Description: It processess the commands obtained from the external file(data4commands.txt).
// ----------------------------------------------------------------------------------------------
void Business::processCommands(istream& infile){
	char action = ' ';
	char genre = ' ';
	char media = ' ';
	int idCustomer = 0;
	bool found = false;
	string mediaType = "";
	char endOfLine = '\n';
	Inventory* location = NULL;
	Customer* tmpCustomer = NULL;
	Inventory*  tmpDvd = NULL;

	while (true){
		infile >> action;
		
		if (infile.eof()) break; 

		if (action == 'I'){	// display the whole current inventory
			displayInventory();
			action = ' ';
		} else if (infile.get() == endOfLine) action = ' ';
		else {	// check what command was passed other than I
			Transaction* processedTran = factory.createTransaction(action, infile);

			if (processedTran != NULL){
				infile >> idCustomer;	// get the customerID

				if (infile.eof()) break;

				if (lookUpCustomer(idCustomer)){ 
					tmpCustomer = getCustomer(idCustomer);
					
					bool isHistory = processedTran->setData(mediaType, location, tmpCustomer);

					if (infile.get() != endOfLine && isHistory){ 
						infile >> media;	// get the type of media

						mediaType = factory.getMediaType(media);

						if (mediaType != ""){  
							infile >> genre;	// get the movie genre

							tmpDvd = factory.createMovie(genre, infile);

							if (tmpDvd != NULL){
								tmpDvd->setDataForCommands(infile);

								found = inventoryList[factory.toIndex(genre)].retrieve(*tmpDvd, location);
								if (found == false)	// if movie was bogus or not founded
									cout << "******ERROR****** :   Movie Title not found in inventory:   " << tmpDvd->getItem() << '\n';
								
								delete tmpDvd;	// delete from heap
								tmpDvd = NULL;

								bool found2 = processedTran->setData(mediaType, location, tmpCustomer);
								if ((found && found2) && mediaType != "") tmpCustomer->addTransaction(*processedTran);
									
								delete processedTran;
								processedTran = NULL;
							} else {	// if an invalid genre was passed
								cout << "******ERROR****** :   " << genre << " is not an existing genre" << '\n';
								if (processedTran != NULL) delete processedTran;
								processedTran = NULL;
							}
							string temp;
							getline(infile, temp, endOfLine);
							delete tmpDvd;
							tmpDvd = NULL;
						} else {
							string temp;
							getline(infile, temp, endOfLine);
							// When invalid command is passed
							cout << "******ERROR****** :   Invalid Command code:   " << media << '\n';

							if (processedTran != NULL) delete processedTran;
							processedTran = NULL;
						}
					} else {
						if (processedTran != NULL) delete processedTran;
						processedTran = NULL;
					}
				} else {	// if an invalid customer id was passed
					cout << "******ERROR****** :   Customer ID: " << idCustomer << " not found" << '\n';
					if (processedTran != NULL) delete processedTran;
	
					processedTran = NULL;
					string temp;
					getline(infile, temp, endOfLine);
				}
			} else {	// if an invalid action code was passed
				cout << "******ERROR****** :   Invalid Action Code " << action << '\n';

				if (processedTran != NULL) delete processedTran;
				
				processedTran = NULL;
			}
		}
		found = false;
		idCustomer = 0;
		location = NULL;
		tmpCustomer = NULL;
		tmpDvd = NULL; 	
	}
}

// --------------------------------- displayInventory -------------------------------------------
// Description: It displays the current inventory for an object of type Business.
// ----------------------------------------------------------------------------------------------
void Business::displayInventory() const {
	if (businessName != "")	{
		cout << "--------------------------------------------------------------\n";
                cout << "Displaying Inventory for:    " << businessName << '\n';
                cout << "--------------------------------------------------------------\n";
	}

	for (int i = MAXINVENTORY; i > 0; --i){	// display in the order required by the assignment
		if (!inventoryList[i].isEmpty()){
				inventoryList[i].displayInOrder(inventoryList[i].getRoot());
				cout << '\n';
		}
	}
}

// ------------------------------------ lookUpCustomer ------------------------------------------
// Description: It calls the findCustomer function of the Hash class to check if a customer
//	 	exists.
// ----------------------------------------------------------------------------------------------
bool Business::lookUpCustomer(int id){
	return allCustomers->findCustomer(id);
}

// --------------------------------------- getCustomer ------------------------------------------
// Description: It returns a customer that is found through the getCustomer function of the class
// 		Hash.
// ----------------------------------------------------------------------------------------------
Customer* Business::getCustomer(int id){
        Customer* newCust = allCustomers->getCustomer(id);
        return newCust;
}
