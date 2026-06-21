
#pragma once
#include "salesOrder.h"
class salesOrderCollection {
	salesOrder saleOrders[100];
	int count;
public:
	//defaoult
	salesOrderCollection();

	//functions
	void addSalesOrderDetails();
	void displaySalesOrderDetails();
	void removeSalesOrderDetails();
	void updateSalesOrderDetails();
	void findSalesOrderByID();
	int returnIndexOfSalesOrderId(int id);
	//function for file handling
	void loadFromCSV();
	void saveToFile();
};