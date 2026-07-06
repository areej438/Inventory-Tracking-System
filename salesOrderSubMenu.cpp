#include <iostream>
#include <string>
#include "validation.h"
#include "salesOrderSubMenu.h"
#include "SalesOrderCollection.h"

#include "colors.h"
using namespace std;



void salesOrderSubMenu(productCollection& pc,stockItemCollection& sic,salesOrderCollection& so) {
	//salesOrderCollection so;
	//productCollection pc;
	//stockItemCollection sic;
	//so.loadFromCSV();
	//pc.loadFromCSV();
	//sic.loadFromCSV();
	int choice = 0;
	do {
		cout << PASTEL_YELLOW<< endl;
		cout << "                    ===========================" << endl;
		cout << PASTEL_LAVENDER;
		cout << "                       Sales Order sub-Menu" << endl;
		cout << PASTEL_YELLOW;
		cout << "                    ===========================" << endl;
		cout << endl;
		cout << "                    1. Add Sales Order Details " << endl;
		cout << "                    2. View Sales Order Details" << endl;
		cout << "                    3. Search Sales Order Details" << endl;
		cout << "                    4. Update Sales Order Details" << endl;
		cout << "                    5. Remove Sales Order Details" << endl;
		cout << PASTEL_GRAY;
		cout << "                    6. Back to Main Menu" << RESET<<endl;

		choice = intValidation("Enter your choice: ");
		switch (choice) {
		case 1:
			so.showDetailsOfEnteredProducts(pc,sic);
			so.addSalesOrderDetails(pc,sic);
			break;
		case 2:
			so.displaySalesOrderDetails();
			break;
		case 3:
			so.findSalesOrderByID();
			break;
		case 4:
			so.updateSalesOrderDetails();
			break;
		case 5:
			so.removeSalesOrderDetails();
			break;
		case 6:
			so.saveToFile();
			return;
		default:
			cout << PASTEL_RED;
			cout << "Invalid Choice!!" <<RESET <<endl;
			break;
		}
	} while (choice != 6);
}