#include <iostream>
#include "salesOrder.h"
using namespace std;

//defining default constructor
salesOrder::salesOrder() {
	salesID = 0;
	productID = 0;
	staffID = 0;
	quantity = 0;
	price = 0;
	totalAmount = 0;
	salesDate = "unknown";
}

//defining copy constructor
salesOrder::salesOrder(const salesOrder& existingSalesOBj) { // for learning change this before submission
	salesID = existingSalesOBj.salesID;
	productID = existingSalesOBj.productID;
	staffID = existingSalesOBj.staffID;
	quantity = existingSalesOBj.quantity;
	price = existingSalesOBj.price;
	totalAmount = existingSalesOBj.totalAmount;
	salesDate = existingSalesOBj.salesDate;
}

//defining destructor
salesOrder::~salesOrder() {
	
}

//defining all setter functions
void salesOrder::setSalesID(int Sid) {
	salesID = Sid;
}
void salesOrder::setProductID(int Pid) {
	productID = Pid;
}
void salesOrder::setStaffID(int Sid) {
	staffID = Sid;
}
void salesOrder::setQuantity(int q) {
	quantity = q;
}
void salesOrder::setSalesPrice(double p) {
	price = p;
}
void salesOrder::setSalesDate(string d) {
	salesDate = d;
}
void salesOrder::setTotalAmount(double t) {
	totalAmount = t;
}

//defining all getter functions
int salesOrder:: getSalesID() {
	return salesID;
}
int salesOrder::getProductID() {
	return productID;
}
int salesOrder::getStaffID() {
	return staffID;
}
int salesOrder::getQuantity() {
	return quantity;
}
double salesOrder::getSalesPrice() {
	return price;
}
string salesOrder::getSalesDate() {
	return salesDate;
}
double salesOrder::getTotalAmount() {
	return totalAmount;
}