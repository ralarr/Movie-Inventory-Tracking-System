// ---------------------------------------------- main.cpp ------------------------------------------------------------
// Erick Larrea CSS343 A
// Creation Date:       12/04/16        
// Date of Last Modification:   12/07/16
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Driver file to test and run the assignment.
// --------------------------------------------------------------------------------------------------------------------

#include "business.h"

int main(){
	Business dvdStore("First DVD STORE/RENTAL");
	ifstream readCustomers("data4customers.txt");
	ifstream readMovies("data4movies.txt");
	ifstream readCommands("data4commands.txt");

	if ((!readCustomers) || (!readMovies) || (!readCommands)){
		cout << "No File" << '\n';
		return 1;
	}
	
	dvdStore.buildCustomers(readCustomers);
	dvdStore.buildInventory(readMovies);
	dvdStore.processCommands(readCommands);

	return 0;
}
