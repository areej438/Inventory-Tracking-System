#include <iostream>
#include <string>
#include "validation.h"
#include "warehouse.h"
#include "warehouseSubmenu.h"
#include "warehouseCollection.h"
#include "colors.h"
using namespace std;


void warehouseSubmenu() {
	warehouseCollection w;
	w.loadFromCSV();
	int choice = 0;
	do {
		cout << PASTEL_YELLOW;
		cout << "                   ===========================" << endl;
		cout << PASTEL_LAVENDER;
		cout << "                       Warehouse sub-Menu" << endl;
		cout << PASTEL_YELLOW;
		cout << "                   ===========================" << endl;
		cout << RESET << endl;

		cout << PASTEL_YELLOW;
		cout << "                    1. Add Warehouse Details " << endl;
		cout << "                    2. View Warehouse Details" << endl;
		cout << "                    3. Search Warehouse Details" << endl;
		cout << "                    4. Update Warehouse Details " << endl;
		cout << "                    5. Remove Warehouse Details" << endl;
		cout << PASTEL_GRAY;
		cout << "                    6. Back to Main Menu" << endl;

		
		choice = intValidation("Enter your choice: ");
		
		switch (choice) {
		case 1:
			w.addWarehouse();
			break;
		case 2:
			w.displayWarehouse();
			break;
		case 3:
			w.findWarehouseByID();
			break;
		case 4:
			w.updateWarehouse();
			break;
		case 5:
			w.removeWarehouse();
			break;
		case 6:
			w.saveToFile();
			return;
		default:
			cout << PASTEL_RED << "Invalid Choice!!" << endl;
			break;
		}
	} while (choice != 6);
}