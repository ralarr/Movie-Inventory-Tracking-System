// -------------------------------------------- hashtable.cpp ---------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/01/16        
// Date of Last Modification:   12/04/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Class in charge of inserting(add) customers into a hash table. The hash table is made of an array of size
//   	     13(a prime number for less collisions) which in case of collisions, it adds the new user in to a linked 
//	     list attached to the array index. The array can be easily changed to hold more indexes but for the purpose
//	     of the assigment 13 is enough.
// --------------------------------------------------------------------------------------------------------------------

#include "hashtable.h"

// --------------------------------- default constructor ----------------------------------------
// Description: Initializes private data members. customerID to -1, firstName and lastName to
//		empty and the next pointer to NULL.
// ----------------------------------------------------------------------------------------------
Hash::Hash(){       
        for (int i = 0; i < TABLE_SIZE; ++i){       
                HashTable[i] = new Customer;
                HashTable[i]->setCustomerID(-1);
                HashTable[i]->setFirstName("empty");
                HashTable[i]->setLastName("empty");
                HashTable[i]->setNext(NULL);
        }
}

// --------------------------------------- destructor -------------------------------------------
// Description: It properly deallocates memory that was used on the heap.
// ----------------------------------------------------------------------------------------------
Hash::~Hash(){       
        for (int i = 0; i < TABLE_SIZE; ++i){       
                delete HashTable[i];
        }
}

// -------------------------------------- addCustomer -------------------------------------------
// Description: Adds a new customer to the hash table after passing the ID to the hash function.
//		If there is already a customer object in the index array, it adds the new 
//		customer to the linked list attached to that array index.
// ----------------------------------------------------------------------------------------------
void Hash::addCustomer(int id, string fName, string lName){       
        int index = hashFunction(id);
        if (HashTable[index]->getCustomerID() == -1){       
                HashTable[index]->setCustomerID(id);
                HashTable[index]->setFirstName(fName);
                HashTable[index]->setLastName(lName);
        } else {       
                Customer* Ptr = HashTable[index];
                Customer* n = new Customer;
                n->setCustomerID(id);
                n->setFirstName(fName);
                n->setLastName(lName);
                n->setNext(NULL);
                
                while (Ptr->getNext() != NULL){       
                        Ptr = Ptr->getNext();
                }
                Ptr->setNext(n);
        }
}

// -------------------------------------- hashFunction ------------------------------------------
// Description: Hash function that used the mod % operator to add a new customer into the hash
//		table.
// ----------------------------------------------------------------------------------------------
int Hash::hashFunction(int id){       
        return id % TABLE_SIZE;
}

// --------------------------------------- getCustomer ------------------------------------------
// Description: It finds a customer in the hash table using the customer ID which is passed as
//		parameter.
// ----------------------------------------------------------------------------------------------
Customer* Hash::getCustomer(int id){
        int index = hashFunction(id);
        Customer* Ptr = HashTable[index];
        while (Ptr != NULL) {
                if (Ptr->getCustomerID() == id) {
                        return Ptr;
                }
                Ptr = Ptr->getNext();
        }

        return nullptr;
}

// -------------------------------------- findCustomer ------------------------------------------
// Description: Returns a boolean to check wheter a customer exists in the hash table. It uses 
//		the customer ID as parameter.
// ----------------------------------------------------------------------------------------------
bool Hash::findCustomer(int id){
	int index = hashFunction(id);
	Customer* Ptr = HashTable[index];
	while (Ptr != NULL){
		if (Ptr->getCustomerID() == id) return true;
		Ptr = Ptr->getNext();
	}

	return false;
}

// ------------------------------------- printTable ---------------------------------------------
// Description: Prints out the customers and their respective information. It only prints out the
//		customers in the array. It also prints out how many Customer objects are in the 
//		same index(in the linked list). This is a fucntion that is not used by the
//		assignment but it is useful for expansion and troubleshooting purposes.
// ----------------------------------------------------------------------------------------------
void Hash::printTable(){
        for (int i = 0; i < TABLE_SIZE; ++i){
                int number = numberOfCustomersInIndex(i);
                cout << "******************\n";
                cout << "index = " << i << '\n';
                cout << HashTable[i]->getCustomerID() << '\n';
                cout << HashTable[i]->getFirstName() << '\n';
                cout << HashTable[i]->getLastName() << '\n';
                cout << "number of items = " << number << '\n';
                cout << "******************\n";
        }
}

// --------------------------------- numberOfCustomersInIndex ---------------------------------------
// Description: Prints out the number of items in an index. This is a fucntion that is not used 
// 		by the assignment but it is useful for expansion and troubleshooting purposes.
// ----------------------------------------------------------------------------------------------
int Hash::numberOfCustomersInIndex(int index){
        int count = 0;
        if (HashTable[index]->getFirstName() == "empty") return count;
        else {
                count++;
                Customer* Ptr = HashTable[index];
                while (Ptr->getNext() != NULL){
                        count++;
                        Ptr = Ptr->getNext();
                }
                return count;
        }
}
