#pragma once
#include "product.h"
class productCollection {
    product products[100];
	int count;
public:
	//defaoult
	productCollection();

	//functions
	void addProduct();
	void displayProduct();
	void removeProduct();
	void updateProduct();
	void findProductByID();
	int returnIndexOfProductId(int id);//helper functiom
	int getProductIdAtIndex(int index);
	string getProductNameAtIndex(int index);
	int getProductCount();

//function for file handling
	void loadFromCSV();
	void saveToFile();
	bool productExist(int id);
	

};