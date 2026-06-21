#include <iostream>
#include <fstream>
#include <sstream>
#include "salesOrderCollection.h"
#include "colors.h"
#include "validation.h"
using namespace std;

//default define 
salesOrderCollection::salesOrderCollection() {
	count = 0;
}

void salesOrderCollection::addSalesOrderDetails() {
	//storage full checking   i can't do it in subemnu file because count is private
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
	saleOrders[count].setProductID(pid);//we cannot directly sign in because products[count] is acting as obj

	//add product price

	double p;
	p = doubleValidation("Enter Product Price: ");
	saleOrders[count].setSalesPrice(p);
	//add quantity
	int q;
	q = intValidation("Enter Product Quantity: ");
	saleOrders[count].setQuantity(q);

	//add expiry date
	string d;
	cout << PASTEL_BROWN;
	cout << "Enter Sales Date: ";
	cout << PASTEL_BEIGE;
	cin.ignore();
	getline(cin, d);
	cout << RESET;
	saleOrders[count].setSalesDate(d);
	//increase count at the end
	count++;
}
void salesOrderCollection::displaySalesOrderDetails() {
	//epmty product checking condition, y is liye qk jb array create hwa to 
	// memory m space bn gi hy default constructor ki yhan show is liye ni ho rhi qk hum loop count 
	// lga rhy han count hi zero ho ga to loop ni chly ga
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
	if (count == 0) {//why else is not running when without this condition ans is loop will not run
		cout << PASTEL_RED << "NO Sale Order Detail is Entered Yet!!" << endl;
		return;
	}
	int searchID;
	searchID = intValidation("Enter Product ID: ");
	bool salesOrderFound = false;//flag will solve the problem
	//If first element doesn’t match → it immediately says “Not found”
	// (never check index 1)It never checks remaining elements
	for (int i = 0; i < count; i++) {

		if (searchID == saleOrders[i].getSalesID()) {
			salesOrderFound = true;
			//addproduct y phir view product ka funct ider call ni ho rha wo kh rha hy y function product class ka ni hy
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
	if (!salesOrderFound) {//after loop must
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
	return -1;//when not found
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
	//can we write this all in else of above if?
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
	for (int i = index; i < count - 1; i++) {//start from index will start from 
		//defected part still get info for understanding
		saleOrders[i] = saleOrders[i + 1];

	}
	count--;//outside loop why look at it properly
	cout << PASTEL_GREEN << "Sales Order Details are removed Successfully!!" << endl;
}

//function for file reading
void salesOrderCollection::loadFromCSV() {//sir uses parameter here bcz if you have more than one file 
	count = 0;//this count is added on chatgpt suggestion why?   //then you can add any filename insted hard coding but we have only 2 simple files
	ifstream rfile("SalesOrder.csv"); //same file name check why?
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
	ofstream outFile("SalesOrder.csv");//csv is liyy qk is ny dobara load bhi to hona hy us k liyr usy comma separated values chaoye
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
