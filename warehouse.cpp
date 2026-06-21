#include <iostream>
#include "warehouse.h"
using namespace std;

//default 
warehouse::warehouse() {
	warehouseID = 0;
	staffID = 0;
	warehouseLocation = "none";
	warehouseName = "unknown";
	warehouseCapacity = 0;
}

//copy
warehouse::warehouse(const warehouse& obj) {
	warehouseID = obj.warehouseID;
	staffID = obj.staffID;
	warehouseLocation = obj.warehouseLocation;
	warehouseName = obj.warehouseName;
	warehouseCapacity = obj.warehouseCapacity;
}

//destructor
warehouse::~warehouse() {
	
}
//setter 

void warehouse::setWarehouseID(int WD) {
	warehouseID = WD;
}
void warehouse::setWarehouseName(string n) {
	warehouseName = n;
}
void warehouse::setStaffID(int SD) {
	staffID = SD;
}
void warehouse::setWarehouseLocation(string l) {
	warehouseLocation = l;
}
void warehouse::setWarehouseCapacity(int c) {
	warehouseCapacity = c;
}

//getter function
int warehouse::getWarehouseID() {
	return warehouseID;
}
int warehouse::getStaffID() {
	return staffID;
}
string warehouse::getWarehouseLocation() {
	return warehouseLocation;
}
string warehouse::getWarehouseName() {
	return warehouseName;
}
int warehouse::getWarehouseCapacity() {
	return warehouseCapacity;
}