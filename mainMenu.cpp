#include <iostream>
#include "mainMenu.h"
#include "productSubmenu.h"
#include "stockItemSubmenu.h"
#include "salesOrderSubMenu.h"
#include "warehouseSubmenu.h"
#include "colors.h"
using namespace std;
void mainMenu() {
    int choice = 0;
    //this is the thing i writr new
    productCollection pc;
    stockItemCollection sic;
    salesOrderCollection so;
    pc.loadFromCSV();
    sic.loadFromCSV();
    so.loadFromCSV();
    do {
        cout << PASTEL_YELLOW << BOLD << endl;
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
        cout << "                    6. Wrehouse Management" << endl;
        cout << "                    7. Staff Management" << endl;
        cout << PASTEL_RED;
        cout << "                    8. Exit" << endl;
        cout << RESET << endl;
        cout << PASTEL_BROWN << "Enter your choice: ";
        cin >> choice;
        cout << RESET << endl;
        switch (choice) {
        case 1:
            productSubMenu(pc);
            break;
        case 2:
            stockItemSubMenu(pc,sic);
            break;
        case 3:
            cout << "supplier management" << endl;
            break;
        case 4:
            cout << "purchase order management" << endl;
            break;
        case 5:
            salesOrderSubMenu(pc,sic,so);
            break;
        case 6:
            warehouseSubmenu();
            cout << "warehouse management" << endl;
            break;
        case 7:
            cout << "staff management" << endl;
            break;
        case 8:
            cout << PASTEL_GREEN;
            cout << "GOOD BYE!" << RESET << endl;
            break;
        default:
            cout << PASTEL_RED << "InvalidChoice!!!" << RESET << endl;
            break;
        }
    } while (choice != 8);
};