
#pragma once
#include "stockItem.h"
#include "productCollection.h"
class stockItemCollection {
	stockItem stockItems[100];
	int count;
public:
	//defaoult
	stockItemCollection();

	//functions
	void addStockItem(productCollection& pc);
	void displayStockItemDetails();
	void removeStockItem();
	void updateStockItem();
	void findStockItemByID();
	int returnIndexOfStockItemId(int id); //helper function
	int returnIndexOfProductIdInStockCollection(int pid);
	int quantityOfStockItem(int pid);
	void updateStockItemQty(int pid, int remainingQty);
	void showDetailsOfEnteredProducts(productCollection& pc);
	int getStockQtyAtIndex(int i);
	//function for file handling
	void loadFromCSV();
	void saveToFile();
};