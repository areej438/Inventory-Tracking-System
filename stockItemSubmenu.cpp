#include <iostream>
#include <string>
#include "validation.h"
#include "stockItem.h"
#include "stockItemSubmenu.h"
#include "stockItemCollection.h"
#include "colors.h"
using namespace std;


void stockItemSubMenu(productCollection& pc,stockItemCollection& sic) {//i added argumnt in this an .h file also
	//stockItemCollection sic;
	//productCollection pc;
	//pc.loadFromCSV();
	//sic.loadFromCSV();
	int choice = 0;
	do {
		cout << PASTEL_YELLOW;
		cout << "                   ===========================" << endl;
		cout << PASTEL_LAVENDER;
		cout << "                       Stock Item sub-Menu" << endl;
		cout << PASTEL_YELLOW;
		cout << "                   ===========================" << endl;
		cout <<RESET<< endl;

		cout << PASTEL_YELLOW;
		cout << "                    1. Add Stock Item Details " << endl;
		cout << "                    2. View Stock Item Details" << endl;
		cout << "                    3. Search Stock Item" << endl;
		cout << "                    4. Update Stock Item" << endl;
		cout << "                    5. Remove Stock Item" << endl;
		cout << PASTEL_GRAY;
		cout << "                    6. Back to Main Menu" << endl;

		
		 choice = intValidation("Enter your choice: ");
		switch (choice) {
		case 1:
			sic.showDetailsOfEnteredProducts(pc);
			sic.addStockItem(pc);
			break;
		case 2:
			sic.displayStockItemDetails();
			break;
		case 3:
			sic.findStockItemByID();
			break;
		case 4:
			sic.updateStockItem();
			break;
		case 5:
			sic.removeStockItem();
			break;
		case 6:
			sic.saveToFile();
			return;
		default:
			cout <<PASTEL_RED<< "Invalid Choice!!" << endl;
			break;
		}
	} while (choice != 6);

}