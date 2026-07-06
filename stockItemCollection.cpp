#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "validation.h"
#include "stockItemCollection.h"
#include "colors.h"
using namespace std;

//default define 
stockItemCollection::stockItemCollection() {
	count = 0;
}

void stockItemCollection::addStockItem(productCollection& pc) {
	//storage full checking  
	if (count >= 100) {
		cout << PASTEL_GREEN;
		cout << "Storage is Full!!" << RESET << endl;
		return;
	}
	cout << PASTEL_YELLOW << BOLD;
	cout << "-------------------------------" << endl;
	cout << PASTEL_LAVENDER;
	cout << "      Enter All Information" << endl;
	cout << PASTEL_YELLOW;
	cout << "-------------------------------" << RESET << endl;
	cout << endl;
	//set id for object made by array and assign value on that count
	int stid;
	 stid = intValidation("Enter Stock Item ID: ");
	 if (returnIndexOfStockItemId(stid) != -1) {
		 cout << PASTEL_RED << "This Stock Item already exist!! " << RESET << endl;
		 return;
	 }
	stockItems[count].setstockItemID(stid);

	int pid;
	 pid = intValidation("Enter Product ID: ");
	 if (!pc.productExist(pid)) {
		 cout << PASTEL_RED << "product ID does not exist!!" << RESET << endl;
		 return;
	 }
	 //for not entering duplicate product id
	 if (returnIndexOfProductIdInStockCollection(pid) != -1) {
		 cout << PASTEL_RED << "This Stock Item already exist!! " << RESET << endl;
		 return;
	 }
	stockItems[count].setProductID(pid);
	
	//add supplier id
	int sid;
	sid = intValidation("Enter Supplier ID: ");
	stockItems[count].setSupplierID(sid);


	//add expiry date
	string d;
	cout << PASTEL_BROWN;
	cout << "Enter Expiry Date: ";
	cout << PASTEL_BEIGE;
	cin.ignore();
	getline(cin, d);
	cout << RESET;
	stockItems[count].setProductExpiryDate(d);

	//add  Purchase date
	string pd;
	cout << PASTEL_BROWN;
	cout << "Enter Purchase Date: ";
	cout << PASTEL_BEIGE;
	getline(cin, pd);
	cout << RESET;
	stockItems[count].setPurchasingDate(pd);
	//add product price

	int Puid;
	 Puid = intValidation("Enter Purchase ID: ");
	stockItems[count].setPurchaseID(Puid);
	//add quantity
	int q;
	 q = intValidation("Enter Stock Item Quantity: ");
	stockItems[count].setStockQuantity(q);
	//increase count at the end
	count++;
}
void stockItemCollection::showDetailsOfEnteredProducts(productCollection& pc) {
	cout << PASTEL_BROWN << endl;
	cout<<"   Added Product Details"<< endl;  
	cout << "------------------------------" << endl;
	cout << "Product ID    Item Name   " << endl;

	
	for (int i = 0; i < pc.getProductCount(); i++) {
		
		cout << PASTEL_BROWN <<"   "<<
	   pc.getProductIdAtIndex(i) <<setw(20) << pc.getProductNameAtIndex(i) << endl;
		
		
	}
	cout << "-----------------------------" <<RESET<< endl;
}
//for getting qty of stock item will show in list before adding sales order details
int stockItemCollection::getStockQtyAtIndex(int i) {
	return stockItems[i].getStockQuantity();
}
void stockItemCollection::displayStockItemDetails() {
	
	if (count == 0) {
		cout << PASTEL_RED;
		cout << "NO Stock Item is Entered yet!!" << RESET << endl;
		return;
	}
	cout << PASTEL_YELLOW << BOLD;
	cout << "-----------------------------------" << endl;
	cout << PASTEL_LAVENDER;
	cout << "  Your Entered Stock Item Details " << endl;
	cout << PASTEL_YELLOW;
	cout << "-----------------------------------" << RESET << endl;
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << PASTEL_BROWN << "Stock Item ID      : " << PASTEL_BEIGE << stockItems[i].getStockItemID() << RESET << endl;
		cout << PASTEL_BROWN << "Product ID         : " << PASTEL_BEIGE << stockItems[i].getProductID() << RESET << endl;
		cout << PASTEL_BROWN << "Supplier ID        : " << PASTEL_BEIGE << stockItems[i].getSupplierID() << RESET << endl;
		cout << PASTEL_BROWN << "Purchase ID        : " << PASTEL_BEIGE << stockItems[i].getPurchaseID() << RESET << endl;
		cout << PASTEL_BROWN << "Purchase Date      : " << PASTEL_BEIGE << stockItems[i].getPurchasingDate() << RESET << endl;
		cout << PASTEL_BROWN << "Stock Item Quantity: " << PASTEL_BEIGE << stockItems[i].getStockQuantity() << RESET << endl;
		cout << PASTEL_BROWN << "Expiry Date        : " << PASTEL_BEIGE << stockItems[i].getProductExpiryDate() << RESET << endl;
		cout << PASTEL_BEIGE << "-------------------------------------" << endl;
	}
}

void stockItemCollection::findStockItemByID() {
	//condition if no product is enter but user still search
	if (count == 0) {
		cout << PASTEL_RED << "NO Stock Item is Entered Yet!!" << endl;
		return;
	}
	int searchID;
	searchID = intValidation("Enter Stock Item ID: ");
	
	bool stockItemFound = false;//flag will solve the problem
	
	for (int i = 0; i < count; i++) {

		if (searchID == stockItems[i].getStockItemID()) {
			stockItemFound = true;
			
			cout << PASTEL_YELLOW << BOLD;
			cout << "---------------------------------------" << endl;
			cout << PASTEL_LAVENDER;
			cout << "  Your Searched Stock Item ID Details " << endl;
			cout << PASTEL_YELLOW;
			cout << "---------------------------------------" << RESET << endl;
			cout << endl;
			cout << PASTEL_BROWN << "Stock Item ID      : " << PASTEL_BEIGE << stockItems[i].getStockItemID() << RESET << endl;
			cout << PASTEL_BROWN << "Product ID         : " << PASTEL_BEIGE << stockItems[i].getProductID() << RESET << endl;
			cout << PASTEL_BROWN << "Supplier ID        : " << PASTEL_BEIGE << stockItems[i].getSupplierID() << RESET << endl;
			cout << PASTEL_BROWN << "Purchase ID        : " << PASTEL_BEIGE << stockItems[i].getPurchaseID() << RESET << endl;
			cout << PASTEL_BROWN << "Purchase Date      : " << PASTEL_BEIGE << stockItems[i].getPurchasingDate() << RESET << endl;
			cout << PASTEL_BROWN << "Stock Item Quantity: " << PASTEL_BEIGE << stockItems[i].getStockQuantity() << RESET << endl;
			cout << PASTEL_BROWN << "Expiry Date        : " << PASTEL_BEIGE << stockItems[i].getProductExpiryDate() << RESET << endl;
			cout << PASTEL_BEIGE << "       ----------------------" << endl;
			break;

		}

	}
	if (!stockItemFound) {//after loop must
		cout << PASTEL_RED;
		cout << "This Stock Item does not exist!!" << RESET << endl;
		return;
	}
}

//this is helper function for search and delete which will return index,otherwise code will repeat
int stockItemCollection::returnIndexOfStockItemId(int id) {
	int index = -1;
	for (int i = 0; i < count; i++) {
		if (id == stockItems[i].getStockItemID()) {
			return i;
		}
	}
	return -1;//when not found
}
//find index of that product id in stockItem collection 

int stockItemCollection::returnIndexOfProductIdInStockCollection(int pid) {
	int index = -1;
	for (int i = 0; i < count; i++) {
		if (pid == stockItems[i].getProductID()) {
			return i;
		}	
	}
	return -1;//when not found
}
//helper for getting quantitiy
int stockItemCollection::quantityOfStockItem(int pid){
	int index = returnIndexOfProductIdInStockCollection(pid);
	if (index == -1) {
		cout << "Product ID does not exist" << endl;
		return -1;
	}
	int qty = stockItems[index].getStockQuantity();
	return qty;
}

void stockItemCollection::updateStockItemQty(int pid, int remainingQty) {
	int index = returnIndexOfProductIdInStockCollection(pid);
	cout << "before:" << stockItems[index].getStockQuantity() << endl;
	stockItems[index].setStockQuantity(remainingQty);
	cout << "after:" << stockItems[index].getStockQuantity() << endl;
}

void stockItemCollection::updateStockItem() {
	if (count == 0) {
		cout << PASTEL_RED;
		cout << "NO Stock Item is Entered yet!!" << RESET << endl;
		return;
	}
	int id;
	id = intValidation("EnterStock Item ID you want to Update: ");
	int index = returnIndexOfStockItemId(id);

	if (index == -1) {
		cout << PASTEL_RED << "Stock Item ID does not exist!!" << endl;
		return;
	}
	
	//add updated info

	int stid;
	stid = intValidation("Enter New Stock Item ID: ");
	stockItems[index].setstockItemID(stid);

	int Pid;
	 Pid = intValidation("Enter new Product ID: ");
	stockItems[index].setProductID(Pid);

	int Sid;
	Sid = intValidation("Enter new Supplier ID: ");
	stockItems[index].setSupplierID(Sid);



	int qty;
	 qty = intValidation("Enter New Stock Item Quantity: ");
	cin.ignore();
	stockItems[index].setStockQuantity(qty);

	string d;
	cout << PASTEL_BROWN;
	cout << "Enter New Expiry Date: ";
	cout << PASTEL_BEIGE;
	getline(cin, d);
	cout << RESET;
	stockItems[index].setProductExpiryDate(d);

	//add  Purchase date
	string pd;
	cout << PASTEL_BROWN;
	cout << "Enter New Purchase Date: ";
	cout << PASTEL_BEIGE;
	getline(cin, pd);
	cout << RESET;
	stockItems[index].setPurchasingDate(pd);
	//add product price

	int pid;
	pid = intValidation("Enter New Purchase ID: ");
	stockItems[index].setPurchaseID(pid);



	cout << PASTEL_GREEN << "Stock Item Details updated successfully!" << endl;
}

void stockItemCollection::removeStockItem() {
	if (count == 0) {
		cout << PASTEL_RED;
		cout << "NO Stock Item is Entered yet!!" << RESET << endl;
		return;
	}
	int id;
	id = intValidation("Enter Stock Item ID you want to remove product Details: ");

	int index = returnIndexOfStockItemId(id);

	if (index == -1) {
		cout << PASTEL_RED << "Stock Item ID does not exist!!" << endl;
		return;
	}
	//shift your array
	for (int i = index; i < count - 1; i++) {
		stockItems[i] = stockItems[i + 1];

	}
	count--;
	cout << PASTEL_GREEN << "Your Selected ID Details are removed Successfully!!" << endl;
}

//function for file reading
void stockItemCollection::loadFromCSV() {
	count = 0;
	ifstream rfile("StockItem.csv"); 
	if (!rfile) {
		cout << "File is not open " << endl;
		return;
	}
	string line;
	getline(rfile, line);
	while (getline(rfile, line)) {
		stringstream ss(line);
		string idstr;
		getline(ss, idstr, ',');
		int SIid = stoi(idstr);
		string Pidstr;
		getline(ss, Pidstr, ',');
        int Productid = stoi(Pidstr);
		//string name;
		//getline(ss, name, ',');
		string sid;
		getline(ss, sid, ',');
		int Suid = stoi(sid);
		string Puidstr;
		getline(ss, Puidstr, ',');
		int Puid = stoi(Puidstr);
		string puDate;
		getline(ss, puDate, ',');
		string qty;
		getline(ss, qty, ',');
		int Sqty = stoi(qty);
		string ExDate;
		getline(ss, ExDate, ',');
		//now assign values to suitable count
		stockItems[count].setstockItemID(SIid);
		stockItems[count].setProductID(Productid);
		
		stockItems[count].setSupplierID(Suid);
		stockItems[count].setPurchaseID(Puid);
		stockItems[count].setPurchasingDate(puDate);
		stockItems[count].setStockQuantity(Sqty);
		stockItems[count].setProductExpiryDate(ExDate);


		count++;
	}
	rfile.close();
}

//write into file function
void stockItemCollection::saveToFile() {
	ofstream outFile("StockItem.csv");
	if (!outFile) {
		cout << "file is not opened" << endl;
		return;
	}
	outFile << "StockItem ID,Product ID,Supplier ID,Purchase ID,Purchase Date,Stock Quantity,Expiry Date" << endl;
	if (count == 0) {
		cout << PASTEL_RED << "NO Products are entered yet,Nothing to write in file!!" << endl;
		outFile.close();
		return;
	}
	for (int i = 0; i < count; i++) {
		outFile << stockItems[i].getStockItemID() << "," << stockItems[i].getProductID()
			<< "," << stockItems[i].getSupplierID() << "," <<stockItems[i].getPurchaseID()<<"," << stockItems[i].getPurchasingDate()
			<<"," << stockItems[i].getStockQuantity()<<"," << stockItems[i].getProductExpiryDate() << endl;
	}
	cout << PASTEL_GREEN << "Products detail are written succesfully" << endl;
	outFile.close();
}
