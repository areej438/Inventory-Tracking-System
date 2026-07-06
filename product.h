#pragma once
#include <string>
using namespace std;
class product {
private:
	int productID;
	int supplierID;
	string productName;
	double price;
	//int quantity;
public:
	//default constructor
	product();

	//copy constructor
	product(const product& existingObj);
	
	//destructor 
	~product();

	//setter functions
	void setProductID(int PD);
	void setSupplierID(int SD); 
	void setProductName(string PN);
	void setProductPrice(double PP); 
	//void setProductQuantity(int PQ);

	//getter functions
		int getProductID(); 
		int getSupplierID(); 
		double getProductPrice();
	    //int getProductQuantity();
		string getProductName();
		
};