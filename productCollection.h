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
//function for file handling
	void loadFromCSV();
	void saveToFile();
	
	

};