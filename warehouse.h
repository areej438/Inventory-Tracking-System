#pragma once
#include <string>
#include "stockItem.h" //for composition
using namespace std;
class warehouse {
	int warehouseID;
	int staffID;
	string warehouseLocation;
	string warehouseName;
	int warehouseCapacity;

	stockItem Items[5];//composition
public:
	//default constructor
	warehouse();

	//copy constructor
	warehouse(const warehouse& obj);

	//destructor
	~warehouse();

	//setter functions
	void setWarehouseID(int WD);
	void setStaffID(int SD);
	void setWarehouseLocation(string l);
	void setWarehouseName(string n);
	void setWarehouseCapacity(int c);

	//getter functions
	int getWarehouseID();
    int getStaffID();
	string getWarehouseLocation();
	string getWarehouseName();
	int getWarehouseCapacity();

};