#include <iostream>
#include "validation.h"
#include <sstream>//stringstraem is a class belong to it
#include <fstream>
#include "productCollection.h"
#include "colors.h"
using namespace std;


//default define 
productCollection::productCollection(){
	count = 0;
}

void productCollection::addProduct() {
	//storage full checking   i can't do it in subemnu file because count is private
	if (count >= 100) {
		cout << PASTEL_GREEN;
		cout << "Storage is Full!!" << RESET<<endl;
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
	int pid;
	pid = intValidation("Enter Product ID: ");
	if (returnIndexOfProductId(pid) != -1) {
		cout << PASTEL_RED << "ID already exist!!" << RESET << endl;
		return;
	}
	products[count].setProductID(pid);//we cannot directly sign in because products[count] is acting as obj

	//add supplier id
	int sid;
	sid = intValidation("Enter Supplier ID: ");
	products[count].setSupplierID(sid);

	//add product name
	string n;
	cout << PASTEL_BROWN;
	cout << "Enter Product Name: ";
	cout << PASTEL_BEIGE;
	cin.ignore();
	getline(cin, n);
	cout << RESET;
	products[count].setProductName(n);
	//add product price

	double p;
	p = doubleValidation("Enter Product Price: ");
	products[count].setProductPrice(p);
	
	count++;
}
//for showing list in stock collection
int productCollection::getProductIdAtIndex(int index) {

	 return products[index].getProductID();
}
string productCollection::getProductNameAtIndex(int index) {

	return products[index].getProductName();
}
int productCollection::getProductCount()
{
	return count;
}
void productCollection::displayProduct() {
	
	if (count == 0) {
		cout << PASTEL_RED;
		cout << "NO Product is Entered yet!!" <<RESET<< endl;
		return;
	}
	cout << PASTEL_YELLOW << BOLD;
		cout << "-------------------------------" << endl;
		cout << PASTEL_LAVENDER;
		cout << "  Your Entered Product Details " << endl;
		cout << PASTEL_YELLOW;
		cout << "-------------------------------" << RESET << endl;
		cout << endl;
	for (int i = 0; i < count; i++) {
		cout << PASTEL_BROWN<<  "Product ID      : " << PASTEL_BEIGE << products[i].getProductID() << RESET<<endl;
		cout << PASTEL_BROWN << "Product Nmae    : " << PASTEL_BEIGE << products[i].getProductName() << RESET<<endl;
		cout << PASTEL_BROWN << "Supplier ID     : " << PASTEL_BEIGE << products[i].getSupplierID() << RESET<<endl;
		cout << PASTEL_BROWN << "Product Price   : " << PASTEL_BEIGE << products[i].getProductPrice() << RESET<< endl;
		cout << PASTEL_BEIGE<<"-------------------------------------" << endl;
	}
}

void productCollection::findProductByID() {
	//condition if no product is enter but user still search
	if (count == 0) {
		cout << PASTEL_RED << "NO Product is Entered Yet!!" << endl;
		return;
	}
	int searchID;
	searchID = intValidation("Enter Product ID: ");
	bool productFound = false;//flag will solve the problem
	                        
	for (int i = 0; i < count; i++) {
		
		if (searchID == products[i].getProductID()) {
			productFound = true;

			cout << PASTEL_YELLOW << BOLD;
			cout << "-------------------------------" << endl;
			cout << PASTEL_LAVENDER;
			cout << "  Your Searched Product Details " << endl;
			cout << PASTEL_YELLOW;
			cout << "-------------------------------" << RESET << endl;
			cout << endl;
			cout << PASTEL_BROWN << "Product ID      : " << PASTEL_BEIGE << products[i].getProductID() << RESET << endl;
			cout << PASTEL_BROWN << "Product Nmae    : " << PASTEL_BEIGE << products[i].getProductName() << RESET << endl;
			cout << PASTEL_BROWN << "Supplier ID     : " << PASTEL_BEIGE << products[i].getSupplierID() << RESET << endl;
			//cout << PASTEL_BROWN << "Product Quantity: " << PASTEL_BEIGE << products[i].getProductQuantity() << RESET << endl;
			cout << PASTEL_BROWN << "Product Price   : " << PASTEL_BEIGE << products[i].getProductPrice() << RESET << endl;
			cout << PASTEL_BEIGE << "       ----------------------" << endl;
			
			break;
			
		}
		
		}
	if (!productFound) {//after loop must
		cout << PASTEL_RED;
		cout << "This Product ID does not exist!!" << RESET << endl;
		return;
	}
}

//this is helper function for search and delete which will return index,otherwise code will repeat
int productCollection::returnIndexOfProductId(int id) {
	int index = -1;
	for (int i = 0; i < count; i++) {
		if (id == products[i].getProductID()) {
			return i; 
		}	
	}
	return -1;//when not found
}
bool productCollection:: productExist(int id) {
	return returnIndexOfProductId(id) != -1;
}
void productCollection::updateProduct() {
	if (count == 0) {
		cout << PASTEL_RED;
		cout << "NO Product is Entered yet!!" <<RESET<< endl;
		return;
	}
	int id;
	id = intValidation("Enter Product ID: ");
	int index = returnIndexOfProductId(id);

	if (index == -1) {
		cout << PASTEL_RED << "Product ID does not exist!!" << endl;
		return;
	}
	//can we write this all in else of above if?
	//add updated info

	int Pid;
	Pid = intValidation("Enter Product ID: ");
	products[index].setProductID(Pid);
	

	int Sid;
	Sid = intValidation("Enter New Supplier ID: ");
	products[index].setSupplierID(Sid);
	

	cout << PASTEL_BROWN << "Enter New Product Name: ";
	cout << PASTEL_BEIGE;
	string n;
	cin.ignore();
	getline(cin, n);
	products[index].setProductName(n);
	cout << RESET ;

	double price;
	price = doubleValidation("Enter New Product Price: ");
	products[index].setProductPrice(price);
	
	

	cout <<PASTEL_GREEN<< "Product Details updated successfully!" << endl;
}

void productCollection::removeProduct() {
	if (count == 0) {
		cout << PASTEL_RED;
		cout << "NO Product is Entered yet!!" << RESET << endl;
		return;
	}
	int id;
	id = intValidation("Enter Product ID: ");
	int index = returnIndexOfProductId(id);

	if (index == -1) {
		cout << PASTEL_RED << "Product ID does not exist!!" << endl;
		return;
	}
	//shift your array
		for (int i = index; i < count-1; i++) {//start from index will start from 
			                                   //defected part still get info for understanding
			products[i] = products[i+1];
			
		}
		count--;//outside loop why look at it properly
		cout << PASTEL_GREEN << "Poduct Details are removed Successfully!!" << endl;
}

//function for file reading
void productCollection:: loadFromCSV() {//sir uses parameter here bcz if you have more than one file 
	count = 0; 
	ifstream rfile("Products.csv"); //same file name check why?
	if (!rfile) {
		cout << "File is not open " << endl;
		return;
	}
	string line;
	getline(rfile, line);
	
	while (getline(rfile,line)) {
		stringstream ss(line);
		string idstr;
		getline(ss, idstr, ',');
		int Pid = stoi(idstr);
		string name;
		getline(ss, name, ',');
		string Sidstr;
		getline(ss, Sidstr, ',');
		int Sid = stoi(Sidstr);
		
		string price;
		getline(ss, price, ',');
		double pric = stod(price);
		//now assign values to suitable count
		products[count].setProductID(Pid);
		products[count].setProductName(name);
		products[count].setSupplierID(Sid);
		products[count].setProductPrice(pric);
		//products[count].setProductQuantity(Pqty);

		count++;
	}
	rfile.close();
}

//write into file function
void productCollection::saveToFile() {
	ofstream outFile("Products.csv");
	if (!outFile) {
		cout << "file is not opened" << endl;
		return;//chexk why 
	}
	outFile << "Product ID,Product Name,Supplier ID,Product Price" << endl;
	if (count == 0) {
		cout << PASTEL_RED << "NO Products are entered yet,Nothing to write in file!!" << endl;
		outFile.close();
		return;
	}
	for (int i = 0; i < count; i++) {
		outFile << products[i].getProductID()<<"," << products[i].getProductName() << "," << products[i].getSupplierID()
			<< "," << products[i].getProductPrice() << endl;
	}
	cout <<PASTEL_GREEN<< "Products detail are written succesfully" << endl;
	outFile.close();
}