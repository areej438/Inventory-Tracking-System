#pragma once
#include <string>
using namespace std;
class salesOrder {
	int salesID;
	int productID;
	int staffID;//we will not 
	int quantity;
	double price;
	double totalAmount;//we will not use it
	string salesDate; // learn about date data type for salesDate
public:
	//default constructor
	salesOrder();

	//copy constructor
	salesOrder(const salesOrder& existingObj);

	//destructor 
	~salesOrder();

	//setter functions
	void setSalesID(int Sid);
	void setProductID(int Pid);
	void setStaffID(int Sid);
	void setQuantity(int q);
	void setSalesPrice(double sp);
	void setTotalAmount(double t);
	void setSalesDate(string sd);

	//getter functions
	int getSalesID();
	int getProductID();
	int getStaffID();
	int getQuantity();
	double getSalesPrice();
	double getTotalAmount();
	string getSalesDate();
};

