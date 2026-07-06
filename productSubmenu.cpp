#include <iostream>
#include <string>
#include "validation.h"
#include "productSubmenu.h"
//#include "product.h" no need here bcz it is incuded in productcollection.h file so indirectly also included here
#include "colors.h"
#include "productCollection.h"

using namespace std;


// product sub menu funtion define
void productSubMenu(productCollection& pc) {
	//productCollection pc;
	//pc.loadFromCSV();
	int choice = 0;
	do {
		cout<<PASTEL_YELLOW;
		cout << "                   ===========================" << endl;
		cout << PASTEL_LAVENDER;
		cout << "                        Product sub-Menu" <<PASTEL_YELLOW<< endl;
		cout << "                   ===========================" <<RESET<< endl;
		cout <<PASTEL_YELLOW<< endl;
		cout << "                    1. Add Product Details " << endl;
		cout << "                    2. View Product Details" << endl;
		cout << "                    3. Search Product By ID" << endl;
		cout << "                    4. Update Product" << endl;
		cout << "                    5. Remove Product" << endl;
		cout << PASTEL_GRAY;
		cout << "                    6. Back to Main Menu" << endl; //exit will end the system

		 choice = intValidation("Enter your choice: ");
		switch (choice) {
		case 1:
			pc.addProduct();
		    break;
		case 2:
			pc.displayProduct();
			//products[count].displayProduct();  i cannot use this(products) directly that's why i need to create
			// a object with type product collection that will be use here
			break;
		case 3:
			pc.findProductByID();
			break;
		case 4:
			pc.updateProduct();
			break;
		case 5:
			pc.removeProduct();
			break;
		case 6:
			//cout << "Back to main Menu" << endl;
			//mainMenu(); we will not write it becuse this calls second time main menu 
			// we will write only return so it will just return to main menu which was called for first
			pc.saveToFile();
			return;
		default:
			cout <<PASTEL_RED<< "Invalid Choice!!" << RESET<<endl;
			break;
		}
	} while (choice != 6);
	
}