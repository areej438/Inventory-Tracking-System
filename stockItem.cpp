#include <iostream>
#include "stockItem.h"

//defining default constructor
stockItem::stockItem() {
	 stockItemId = 0;
	 productID = 0;
	 stockQuantity = 0;
	 purchaseID = 0;
	 supplierID = 0;
	 purchaseDate = "none"; // you can check for more proffesional word
	 expiryDate = "none";
	 //stockStatus = "none";
}

//defining copy constructor 
stockItem::stockItem(const stockItem& obj) { //you can change the name of obj
	stockItemId = obj.stockItemId;
	productID = obj.productID;
	stockQuantity = obj.stockQuantity;
	purchaseID = obj.purchaseID;
	supplierID = obj.supplierID;
	purchaseDate = obj.purchaseDate; 
	expiryDate = obj.expiryDate;
	//stockStatus = obj.stockStatus;
}

//defining destructor
stockItem::~stockItem() {
}

//defining setter functions

void stockItem::setstockItemID(int Sid) {
	stockItemId = Sid;
}
void stockItem::setSupplierID(int Spid) {
	supplierID = Spid;
}
void stockItem:: setProductID(int Pid) {
	productID = Pid;
}

void stockItem::setStockQuantity(int Sq) {
	stockQuantity = Sq;
}
void stockItem::setPurchasingDate(string pDate) {
	purchaseDate = pDate;
}
//void stockItem::setStockItemName(string sn) {
//	stockItemName = sn;
//}
void stockItem::setProductExpiryDate(string pExDate) {
	expiryDate = pExDate;
}
//void stockItem::setstockStauts(string sStatus) {
//	stockStatus = sStatus;
//}
void stockItem::setPurchaseID(int Pid) {
	purchaseID = Pid;
}

//definig getter function
int stockItem::getStockItemID() {
	return stockItemId;
}
int stockItem::getProductID() {
	return productID;
}
int stockItem::getSupplierID() {
	return supplierID;
}
int stockItem::getStockQuantity() {
	return stockQuantity;
}
string stockItem::getPurchasingDate() {
	return purchaseDate;
}
//string stockItem::getStockItemName() {
//	return stockItemName;
//}
string stockItem::getProductExpiryDate() {
	return expiryDate;
}
//string stockItem::getStockStatus() {
//	return stockStatus;
//}
int stockItem::getPurchaseID() {
	return purchaseID;
}