
#pragma once
#include "salesOrder.h"
#include "productCollection.h"
#include "stockItemCollection.h"
class salesOrderCollection {
	salesOrder saleOrders[100];
	int count;
public:
	//defaoult
	salesOrderCollection();
	

	//functions
	void addSalesOrderDetails( productCollection& pc, stockItemCollection& sic);
	void displaySalesOrderDetails();
	void removeSalesOrderDetails();
	void updateSalesOrderDetails();
	void findSalesOrderByID();
	//helping func
	int returnIndexOfSalesOrderId(int id);
	void showDetailsOfEnteredProducts(productCollection& pc,stockItemCollection& sic);

	//function for file handling
	void loadFromCSV();
	void saveToFile();
};