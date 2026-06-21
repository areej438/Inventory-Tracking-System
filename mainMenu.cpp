#include <iostream>
//#include <iomanip>
#include "validation.h"
#include "mainMenu.h"
#include "productSubmenu.h"
#include "stockItemSubmenu.h"
#include "salesOrderSubMenu.h"
#include "warehouseSubmenu.h"
#include "colors.h"


using namespace std;
void mainMenu() {

	int choice = 0;
	do {
		cout << PASTEL_YELLOW <<BOLD<< endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << PASTEL_LAVENDER;
		cout << "                           Main Menu" << endl;
		cout << PASTEL_YELLOW;
		cout << "------------------------------------------------------------------------" << endl;
		cout << RESET << endl;
		cout << PASTEL_YELLOW;
		cout << "                    1. Product Management" << endl;
		cout << "                    2. stock Item Management" << endl;
		cout << "                    3. Supplier Management" << endl;
		cout << "                    4. Purchase Order Management" << endl;
		cout << "                    5. Sales Order Management" << endl;
		cout << "                    6. Warehouse Management" << endl;
		cout << "                    7. Staff Management" << endl;
		cout << PASTEL_RED;
		cout << "                    8. Exit" << endl; //exit will end the system
		cout << RESET<< endl;

		
	   choice = intValidation("Enter your choice: ");
	
		switch (choice) {
		case 1:
			productSubMenu();
			break;
		case 2:
			stockItemSubMenu();
			break;
		case 3:
			cout << "supplier management" << endl;
			break;
		case 4:
			cout << "purchase order management" << endl;
			break;
		case 5:
			salesOrderSubMenu();
			break;
		case 6:
			warehouseSubmenu();
			break;
		case 7:
			cout << "staff management" << endl;
			break;
		case 8:
			cout << PASTEL_GREEN;
			cout << "GOOD BYE!" <<RESET<< endl;
			break;

		default:
			cout <<PASTEL_RED << "Invalid Choice!!!" <<RESET<< endl;
			break;
		}
	} while (choice != 8);
};