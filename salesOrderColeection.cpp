#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "salesOrderCollection.h"
//#include "productCollection.h"
#include "colors.h"
#include "validation.h"
using namespace std;


//default define 
salesOrderCollection::salesOrderCollection() {
	count = 0;
}

void salesOrderCollection::addSalesOrderDetails(productCollection& pc, stockItemCollection& sic) {
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
	int sid;
	sid = intValidation("Enter Sales ID: ");
	if (returnIndexOfSalesOrderId(sid) != -1) {
		cout << PASTEL_RED << "This sales ID already exit!!" << RESET << endl;
		return;
	}
	saleOrders[count].setSalesID(sid);

	int pid;
	pid = intValidation("Enter Product ID: ");
	//for checking the same product id or for matching you can say
	if (!pc.productExist(pid)) {
		cout << PASTEL_RED << "product ID does not exist!!" << RESET << endl;
		return;
	}
	saleOrders[count].setProductID(pid);
	
	//add product price

	double p;
	p = doubleValidation("Enter Product Price: ");
	saleOrders[count].setSalesPrice(p);

	string d;
	cout << PASTEL_BROWN;
	cout << "Enter Sales Date: ";
	cout << PASTEL_BEIGE;
	cin.ignore();
	getline(cin, d);
	cout << RESET;
	saleOrders[count].setSalesDate(d);
	//add quantity
	int q;
	q = intValidation("Enter Product Quantity: ");
	//if enough stock is available or not?
	if (q > sic.quantityOfStockItem(pid)) {
		cout <<PASTEL_RED<< "stock is not available" << endl;
		return;
	}
	saleOrders[count].setQuantity(q);
	//subtraction,to get remaing qty which will be used for updation of stock qty also
	int remainingStockQty = sic.quantityOfStockItem(pid) - q;
	sic.updateStockItemQty(pid, remainingStockQty);
	sic.saveToFile();//when sale happens it store in RAM (subtraction of product) not in CSV so that after
	                //another run in list it shows previous one after svaing in csv proble will be solved
	//add expiry date
	
	//increase count at the end
	count++;
}

void salesOrderCollection::showDetailsOfEnteredProducts(productCollection& pc,stockItemCollection& sic) {
	cout << PASTEL_BROWN << endl;
	cout << "   Added Product Details" << endl;
	cout << "------------------------------" << endl;
	cout << "Product ID    Item Name   Quantity" << endl;

	//pc.getProductList();  this will cause formatting problem 
	//for (int i = 0; i < count; i++) {
	//	cout<<"      " << stockItems[i].getStockQuantity() << endl;
	//}
	//cout << RESET << endl;
	for (int i = 0; i < pc.getProductCount(); i++) {
		//int index = pc.returnIndexOfProductId(i);this will gice the index of 0,1 bcz 'i' is acting as product id here
		int prdctId = pc.getProductIdAtIndex(i);//this will give index of that prdct id which is at index (i) 0,1,..
		int stockqtyIndx = sic.returnIndexOfProductIdInStockCollection(prdctId);
		cout << PASTEL_BROWN << "   " <<
			pc.getProductIdAtIndex(i) << setw(20) << pc.getProductNameAtIndex(i) << setw(16);
		if (stockqtyIndx == -1) {
			cout << "not added"<<endl;
		}
		else { cout << sic.getStockQtyAtIndex(stockqtyIndx) << endl; }


	}
	cout << "-----------------------------" << RESET << endl;
}
void salesOrderCollection::displaySalesOrderDetails() {
	//epmty product checking condition
	if (count == 0) {
		cout << PASTEL_RED;
		cout << "NO Sales Order is Entered yet!!" << RESET << endl;
		return;
	}
	cout << PASTEL_YELLOW << BOLD;
	cout << "-------------------------------" << endl;
	cout << PASTEL_LAVENDER;
	cout << "  Your Entered Sales Order Details " << endl;
	cout << PASTEL_YELLOW;
	cout << "-------------------------------" << RESET << endl;
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << PASTEL_BROWN << "Product ID         : " << PASTEL_BEIGE << saleOrders[i].getProductID() << RESET << endl;
		cout << PASTEL_BROWN << "Sales ID           : " << PASTEL_BEIGE << saleOrders[i].getSalesID() << RESET << endl;
		cout << PASTEL_BROWN << "Sales Order Date   : " << PASTEL_BEIGE << saleOrders[i].getSalesDate() << RESET << endl;
		cout << PASTEL_BROWN << "Sale Order Quantity: " << PASTEL_BEIGE << saleOrders[i].getQuantity() << RESET << endl;
		cout << PASTEL_BROWN << "Sale Order Price   : " << PASTEL_BEIGE << saleOrders[i].getSalesPrice() << RESET << endl;
		cout << PASTEL_BEIGE << "-------------------------------------" << endl;
	}
}

void salesOrderCollection::findSalesOrderByID() {
	//condition if no product is enter but user still search
	if (count == 0) {
		cout << PASTEL_RED << "NO Sale Order Detail is Entered Yet!!" << endl;
		return;
	}
	int searchID;
	searchID = intValidation("Enter Sales Order ID: ");
	bool salesOrderFound = false;
	for (int i = 0; i < count; i++) {

		if (searchID == saleOrders[i].getSalesID()) {
			salesOrderFound = true;
			
			cout << PASTEL_YELLOW << BOLD;
			cout << "-------------------------------" << endl;
			cout << PASTEL_LAVENDER;
			cout << "  Your Searched Sale Order Details " << endl;
			cout << PASTEL_YELLOW;
			cout << "-------------------------------" << RESET << endl;
			cout << endl;
			cout << PASTEL_BROWN << "Product ID         : " << PASTEL_BEIGE << saleOrders[i].getProductID() << RESET << endl;
			cout << PASTEL_BROWN << "Sales ID           : " << PASTEL_BEIGE << saleOrders[i].getSalesID() << RESET << endl;
			cout << PASTEL_BROWN << "Sales Order Date   : " << PASTEL_BEIGE << saleOrders[i].getSalesDate() << RESET << endl;
			cout << PASTEL_BROWN << "Sale Order Quantity: " << PASTEL_BEIGE << saleOrders[i].getQuantity() << RESET << endl;
			cout << PASTEL_BROWN << "Sale Order Price   : " << PASTEL_BEIGE << saleOrders[i].getSalesPrice() << RESET << endl;
			cout << PASTEL_BEIGE << "       ----------------------" << endl;
			break;

		}

	}
	if (!salesOrderFound) {
		cout << PASTEL_RED;
		cout << "This Sales ID does not exist!!" << RESET << endl;
		return;
	}
}

//this is helper function for search and delete which will return index,otherwise code will repeat
int salesOrderCollection::returnIndexOfSalesOrderId(int id) {
	int index = -1;
	for (int i = 0; i < count; i++) {
		if (id == saleOrders[i].getSalesID()) {
			return i;
		}
	}
	return -1;
}



void salesOrderCollection::updateSalesOrderDetails() {
	if (count == 0) {
		cout << PASTEL_RED;
		cout << "NO Sales Order is Entered yet!!" << RESET << endl;
		return;
	}
	int id;
	id = intValidation("Enter Sales ID you want to Update: ");
	int index = returnIndexOfSalesOrderId(id);

	if (index == -1) {
		cout << PASTEL_RED << "Sales Order ID does not exist!!" << endl;
		return;
	}
	
	//add updated info

	int soid;
	 soid = intValidation("Enter new Sales Order ID: ");
	saleOrders[index].setSalesID(soid);
	//product id
	int Pid;
	Pid = intValidation("Enter new Product ID: ");
	saleOrders[index].setProductID(Pid);
	//sales date
	cout << PASTEL_BROWN << "Enter New Sales Date: ";
	cout << PASTEL_BEIGE;
	string sd;
	cin.ignore();
	getline(cin, sd);
	saleOrders[index].setSalesDate(sd);
	cout << RESET;

	double price;
	price = doubleValidation("Enter new Sales Order Price: ");
	saleOrders[index].setSalesPrice(price);
	
	//quanty
	int qty;
	qty = intValidation("Enter new Sales Order Quantity: ");
	saleOrders[index].setQuantity(qty);
	

	cout << PASTEL_GREEN << "Sale Order Details updated successfully!" << endl;
}

void salesOrderCollection::removeSalesOrderDetails() {
	if (count == 0) {
		cout << PASTEL_RED;
		cout << "NO Sales Order is Entered yet!!" << RESET << endl;
		return;
	}
	int id;
	id = intValidation("Enter Sales ID you want to remove product Details: ");
	int index = returnIndexOfSalesOrderId(id);

	if (index == -1) {
		cout << PASTEL_RED << "Sales ID does not exist!!" << endl;
		return;
	}
	//shift your array
	for (int i = index; i < count - 1; i++) {
		saleOrders[i] = saleOrders[i + 1];

	}
	count--;
	cout << PASTEL_GREEN << "Sales Order Details are removed Successfully!!" << endl;
}

//function for file reading
void salesOrderCollection::loadFromCSV() {
	count = 0;
	ifstream rfile("SalesOrder.csv"); 
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
		int Pid = stoi(idstr);
		string Sidstr;
		getline(ss, Sidstr, ',');
		int Sid = stoi(Sidstr);
		string SOdate;
		getline(ss, SOdate, ',');
		string qty;
		getline(ss, qty, ',');
		int SOqty = stoi(qty);
		string price;
		getline(ss, price, ',');
		double pric = stod(price);
		//now assign values to suitable count
		saleOrders[count].setProductID(Pid);
		saleOrders[count].setSalesID(Sid);
		saleOrders[count].setSalesDate(SOdate);
		saleOrders[count].setQuantity(SOqty);
		saleOrders[count].setSalesPrice(pric);

		count++;
	}
	rfile.close();
}

//write into file function
void salesOrderCollection::saveToFile() {
	ofstream outFile("SalesOrder.csv");
	if (!outFile) {
		cout << "file is not opened" << endl;
		return;//chexk why 
	}
	outFile << "Product ID,Sales ID,Date,Sales order Quantity,sales order Price" << endl;
	if (count == 0) {
		cout << PASTEL_RED << "NO Products are entered yet,Nothing to write in file!!" << endl;
		outFile.close();
		return;
	}
	for (int i = 0; i < count; i++) {
		outFile << saleOrders[i].getProductID() << "," << saleOrders[i].getSalesID() << "," <<saleOrders[i].getSalesDate()
			<< "," << saleOrders[i].getQuantity() << "," <<saleOrders[i].getSalesPrice() << endl;
	}
	cout << PASTEL_GREEN << "Products detail are written succesfully" << endl;
	outFile.close();
}
