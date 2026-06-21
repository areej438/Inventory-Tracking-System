
#pragma once
#include "stockItem.h"
class stockItemCollection {
	stockItem stockItems[100];
	int count;
public:
	//defaoult
	stockItemCollection();

	//functions
	void addStockItem();
	void displayStockItemDetails();
	void removeStockItem();
	void updateStockItem();
	void findStockItemByID();
	int returnIndexOfStockItemId(int id); //helper function
	//function for file handling
	void loadFromCSV();
	void saveToFile();
};