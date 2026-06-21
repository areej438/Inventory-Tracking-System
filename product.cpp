#include <iostream>
#include "product.h"
using namespace std;

	//default constructor
	product::product() {
		productID = 0;
		supplierID = 0;
		productName = "unknown";
		price = 0;
		quantity = 0;
	}

	//copy constructor
	product::product(const product& existingObj) {
		productID = existingObj.productID;
		supplierID = existingObj.supplierID;
		productName = existingObj.productName;
		price = existingObj.price;
		quantity = existingObj.quantity;
	}

	//destructor 
	product::~product() {
		//cout << "destructor is called" << endl; i am doing this bcz for now i passed the object as argument in submenu 
		                                        //class  thats why on ending of function this line was printing
	}

	//setter functions
	void product ::setProductID(int PD) {
		productID = PD;
	}
	void  product::setSupplierID(int SD) {
		supplierID = SD;
	}
	void  product::setProductName(string PN) {
		productName = PN;
	}
	void  product::setProductPrice(double PP) {
		price = PP;
	}
	void  product::setProductQuantity(int PQ) {
		quantity = PQ;
	}

	//getter functions
	int product::getProductID() {
		return productID;
	}
	int  product::getSupplierID() {
		return supplierID;
	}
	double  product::getProductPrice() {
		return price;
	}
	int product::getProductQuantity() {
		return quantity;
	}
	string  product::getProductName() {
		return productName;
	}
